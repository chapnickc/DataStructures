import os.path
import sys
import glob

try:
    path = os.path.abspath(sys.argv[2])
except IndexError as e:
    print(e)

path = os.path.abspath('./shaffer')
glob.glob(f'{path}/*.h')
