#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

"""
author : xiaohai
email : xiaohaijin@outlook.com
"""


import subprocess


def main():
    subprocess.call(('make', 'clean'))
    subprocess.call(('xelatex', 'analysisLog.tex'))
    subprocess.call(('bibtex',  'analysisLog.aux'))
    subprocess.call(('xelatex', 'analysisLog.tex'))
    subprocess.call(('xelatex', 'analysisLog.tex'))
    subprocess.call(('evince',  'analysisLog.pdf'))

if __name__ == '__main__':
    main()
