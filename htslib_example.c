#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "bgzf.h"
#include "sam.h"

int main(int argc, char *argv[])
{
    samFile* sf;
    bam1_t* b;
    int64_t offset;

    if ((sf = sam_open(argv[1], "r")) == 0) {
        return 1;
    }
    bam_hdr_t *h = bam_hdr_read(sf->fp.bgzf);
    b = (bam1_t*)calloc(1, sizeof(bam1_t));

    while (1) {
        int64_t offset = bgzf_tell(sf->fp.bgzf);
        if (bam_read1(sf->fp.bgzf, b) > 0)
        {
            char *qname = bam_get_qname(b);
            printf("0x%-16llx %s\n", offset, qname);
        } else {
            break;
        }
    }

    return 0;
}
