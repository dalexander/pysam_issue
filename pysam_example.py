#!/usr/bin/env python

import sys
import pysam

bamFname = sys.argv[1]

f = pysam.Samfile(bamFname)

f.reset()
while True:
    try:
        posBefore = f.tell()
        rawAln = next(f)
        #posAfter = f.tell()
        #print "%16x %16x %s" % (posBefore, posAfter, rawAln.qname)
        print "0x%-16x %s" % (posBefore, rawAln.qname)

    except StopIteration:
        break
