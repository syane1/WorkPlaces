#!C:\Workplace\Py\Python\3.7.8\python37.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'tifffile','console_scripts','tiffcomment'
__requires__ = 'tifffile'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('tifffile', 'console_scripts', 'tiffcomment')()
    )
