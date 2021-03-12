import hashlib
import argparse
import secrets

parser = argparse.ArgumentParser()

parser.add_argument("password")

args = parser.parse_args() 



print(hashlib.pbkdf2_hmac('sha512', args.password.encode(), bytes(secrets.randbits(16)), 100000).hex())
