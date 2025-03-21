# Lsass-Dumper-C
Lsass Dumper with C

- Demonstration of dumping lsass process to a dmp file in windows using C and win32 API.

- The code takes the lsass.exe pid as an argument and creates an empty dump file and gets a handle of the lsass.exe process and dump it inside the file.

- Then you can view the password hashes in the dmp file using mimikatz and then crack them with John or Hashcat.
