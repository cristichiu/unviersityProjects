import sqlite3
import base64
from cryptography.fernet import Fernet
from getpass import getpass

import string
import secrets

import hashlib

db_file = "passwords.db"
user_username = ""

conn = sqlite3.connect(db_file)
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS passwords (
    site TEXT,
    user_username TEXT,
    username TEXT,
    password TEXT,
    PRIMARY KEY (site, user_username)
)
""")
cursor.execute("""
CREATE TABLE IF NOT EXISTS user (
    username TEXT PRIMARY KEY,
    password TEXT
)
""")

conn.commit()

def hash_text(data):
    sha256 = hashlib.sha256()
    sha256.update(data.encode("utf-8"))
    return sha256.hexdigest()

def login():
    username = input("Username: ")
    master_pass = getpass("Introdu parola principala: ")
    cursor.execute("SELECT username, password FROM user WHERE username = ? AND password = ?", (username, hash_text(master_pass)))
    row = cursor.fetchone()
    if row:
        return (username, generate_key(master_pass))
    else:
        print("Nu exista asa user.")
        return

def register():
    username = input("Username: ")
    master_pass = getpass("Introdu parola principala: ")
    cursor.execute("INSERT INTO user (username, password) VALUES (?, ?)", (username, hash_text(master_pass)))
    conn.commit()
    return (username, generate_key(master_pass))

def generate_key(password: str) -> bytes:
    return base64.urlsafe_b64encode(password.ljust(32).encode()[:32])

def encrypt(data: str, key: bytes) -> str:
    return Fernet(key).encrypt(data.encode()).decode()

def decrypt(data: str, key: bytes) -> str:
    return Fernet(key).decrypt(data.encode()).decode()

def save_password(site: str, username: str, password: str, key: bytes):
    encrypted_pass = encrypt(password, key)
    cursor.execute("INSERT OR REPLACE INTO passwords (site, username, password, user_username) VALUES (?, ?, ?, ?)", (site, username, encrypted_pass, user_username))
    conn.commit()
    print("Parola salvata!")
    return

def get_password(site: str, key: bytes):
    cursor.execute("SELECT username, password FROM passwords WHERE site = ? AND user_username = ?", (site, user_username))
    row = cursor.fetchone()

    if row:
        username, encrypted_pass = row
        decrypted_pass = decrypt(encrypted_pass, key)
        print(f"username: {username}\nParola: {decrypted_pass}")
    else:
        print("Site-ul nu existe in baza de date.")
    return

def generate_password(length = 12):
    return "".join(secrets.choice(string.ascii_letters + string.digits + "$#.*!@%&_") for i in range(length))

def show_passwords():
    cursor.execute("SELECT * FROM passwords WHERE user_username = ?", (user_username,))
    result = cursor.fetchall()
    for res in result:
        print(res)
def show_users():
    cursor.execute("SELECT * FROM user")
    result = cursor.fetchall()
    for res in result:
        print(res)
