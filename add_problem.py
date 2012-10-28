# Given problem name:
# 1. Create a proper cpp file from template, exit if file already exist.
# 2. Output a line for the README.md file

from optparse import OptionParser
import sys
import os

if __name__ == '__main__':
    parser = OptionParser(usage = "Usage: add_problem \"Problem Name\"")
    (options, args) = parser.parse_args()
    if len(args) != 1:
        parser.print_help()
        sys.exit(1)
    
    name = args[0]
    in_file_name = 'template.txt'
    out_file_name = name.replace(' ', '_') + '.cpp'

    readme_template = '* [{{ Title }}](https://github.com/timoncui/LeetCode/blob/master/{{ Out file name }})';
    line = readme_template.replace('{{ Title }}', name)
    line = line.replace('{{ Out file name }}', out_file_name)
    print 'Line for README.md:'
    print line    

    if os.path.exists(out_file_name):
        print out_file_name, 'already exists.'
        sys.exit(1)

    with open(in_file_name, 'r') as f:
        s = f.read()
        s = s.replace('{{ Title }}', name)
        with open(out_file_name, 'w') as fo:
            fo.write(s)
        print 'File', out_file_name, 'created.'

