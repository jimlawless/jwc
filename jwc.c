// A simple word counter program
// Copyright 2023 by Jim Lawless
// See MIT License at
// https://github.com/jimlawless/jwc/blob/master/LICENSE

#include <stdio.h>
#include <string.h>

int main(int argc,char **argv) {
    FILE *fp;
    int c;
    int is_word;
    int word_count;
    
    if(argc<2) {
        fprintf(stderr,"\nJim's Word Count (jwc) v1.02 by Jim Lawless https://jimlawless.net/\n\nSyntax:\n\tjwc text-file-name\nor\n");
        fprintf(stderr,"\tjwc -i\n\t...for input from stdin...\n");
        return 1;
    }
    if(!stricmp(argv[1],"-i")||!stricmp(argv[1],"-I"))
        fp=stdin;
    else
    if((fp=fopen(argv[1],"r"))==NULL) {
        fprintf(stderr,"Cannot open input file %s\n",argv[1]);
        return 1;
    }
    is_word=0;
    word_count=0;
    while((c=fgetc(fp))!=-1) {
        if((c==' ')||(c=='\t')||(c=='\r')||(c=='\n')||(c=='\x1a')) {
            if(is_word) {
                word_count++;
                is_word=0;
            }
        }
        else {
            if(!is_word) {
                is_word=1;
            }
        }
    }
    if(is_word)
        word_count++;
            
    printf("%d\n",word_count);
    return 0;
}