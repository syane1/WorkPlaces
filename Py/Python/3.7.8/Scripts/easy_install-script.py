#!C:\Workplace\Py\Python\3.7.8\python37.exe
# EASY-INSTALL-ENTRY-SCRIPT: 'setuptools','console_scripts','easy_install'
__requires__ = 'setuptools'
import re
import sys
from pkg_resources import load_entry_point

if __name__ == '__main__':
    sys.argv[0] = re.sub(r'(-script\.pyw?|\.exe)?$', '', sys.argv[0])
    sys.exit(
        load_entry_point('setuptools', 'console_scripts', 'easy_install')()
    )
