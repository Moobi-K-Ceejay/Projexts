#!/usr/bin/env python3
import sqlite3
from sqlite3 import Error


class DbManager:
    def __init__(self):
        try:
            # Connect to databasr
            self.conn = sqlite3.connect("database.db")

            self.cursor = self.conn.cursor()
            self.sql_query = None
        except Error as e:
            print(e)
            
        finally:
            # Kill connection
            if self.conn:
                conn.close()

    def signUp(self, email, passwd):
        try:
            self.sql_query = '''INSERT INTO Accounts(Email, Password)
                            VALUES(?,?)'''
            self.cursor.execute(self.sql_query, (email,passwd))
        except Error:
            print("[!] Failed To Sign-up User.")
