import os
os.system('make clean')
exec(open('builder.py').read())
os.system('make run')
