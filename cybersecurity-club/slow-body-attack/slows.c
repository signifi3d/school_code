#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/ssl.h>

#define BuffSize 1024

void report_and_exit(const char * msg) {
	perror(msg);
	ERR_print_errors_fp(stderr);
	exit(-1);
}

void init_ssl() {
	SSL_load_error_strings();
	SSL_library_init();
}

void cleanup(SSL_CTX* ctx, BIO* bio) {
	SSL_CTX_free(ctx);
	BIO_free_all(bio);
}

void secure_connect(const char* hostname) {

	char name[BuffSize];
	char request[BuffSize];
	char response[BuffSize];
	int  sleeptime = 2;
	char *header =	"POST /purchase HTTP/1.1\r\n"
			"Host: 91a7f62e368e2a833aa0fc5f82220237-metro-lottery-enhanced.web.cityinthe.cloud\r\n"
			"User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:68.0) Gecko/20100101 Firefox/68.0\r\n"
			"Accept: */*\r\n"
			"Accept-Language: en-US,en;q=0.5\r\n"
			"Accept-Encoding: gzip, deflate\r\n"
			"Referer: https://91a7f62e368e2a833aa0fc5f82220237-metro-lottery-enhanced.web.cityinthe.cloud/\r\n"
			"Content-Type: application/json\r\n"
			"Content-Length: 27\r\n"
			"DNT: 1\r\n"
			"Connection: close\r\n\r\n";
	char * payload = "{\"cost\":5,\"tickets\":100000}\r\n";
	

	const SSL_METHOD* method = TLSv1_2_client_method();
	if (NULL == method) report_and_exit("TLSv1_2_client_method...");


 	SSL_CTX* ctx = SSL_CTX_new(method);
  	if (NULL == ctx) report_and_exit("SSL_CTX_new...");

  	BIO* bio = BIO_new_ssl_connect(ctx);
  	if (NULL == bio) report_and_exit("BIO_new_ssl_connect...");

	SSL* ssl = NULL;

	sprintf(name, "%s:%s", hostname, "https");
  	BIO_get_ssl(bio, &ssl); /* session */
  	SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY); /* robustness */
  	BIO_set_conn_hostname(bio, name); /* prepare to connect */

  	/* try to connect */
  	if (BIO_do_connect(bio) <= 0) {
    		cleanup(ctx, bio);
    		report_and_exit("BIO_do_connect...");
  	}

  	/* verify truststore, check cert */
  	if (!SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-certificates.crt", "/etc/ssl/certs/")) 
    		report_and_exit("SSL_CTX_load_verify_locations...");

  	long verify_flag = SSL_get_verify_result(ssl);
  	if (verify_flag != X509_V_OK)
    		fprintf(stderr, "##### Certificate verification error (%i) but continuing...\n", (int) verify_flag);

  	/* now fetch the homepage as sample data */
  	//sprintf(request, "GET / HTTP/1.1\x0D\x0AHost: %s\x0D\x0A\x43onnection: Close\x0D\x0A\x0D\x0A", hostname);
  	BIO_puts(bio, header);
	for (int i = 0; i < strlen(payload); ++i) {
		char slow[2] = { payload[i], '\0' };
		sleep(sleeptime);
		BIO_puts(bio, slow);
	}

  	/* read HTTP response from server and print to stdout */
  	while (1) {
    		memset(response, '\0', sizeof(response));
    		int n = BIO_read(bio, response, BuffSize);
    		if (n <= 0) break; /* 0 is end-of-stream, < 0 is an error */
  	puts(response);
  	}

	cleanup(ctx, bio);
}

int main() {
  	init_ssl();

  	const char* hostname = "91a7f62e368e2a833aa0fc5f82220237-metro-lottery-enhanced.web.cityinthe.cloud";
  	fprintf(stderr, "Trying an HTTPS connection to %s...\n", hostname);
  	secure_connect(hostname);

	return 0;
}

