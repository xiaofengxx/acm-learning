#include<cstdio>
#include<stdlib.h>
#include<string.h>
struct TrieNode{
    bool t;
    struct TrieNode *next[10];
}trie;
void start(struct TrieNode *next)
{
    t=false;
    for(int i=0;i<10;i++)
        next->next[i]=NULL;
}
void ins_Trie(char *s,struct TrieNode* next)
{
    while(*s!='\0'&&*s!=' ')
    {
        if(next->next[*s-'0']==NULL)
        {
            next->next[*s-'0']=(struct TrieNode*)malloc(sizeof(struct TrieNode));
            start(next->next[*s-'0']);
        }
        next=next->next[*s-'0'];
        s++;
        next->t=true;
    }
    return;
}
int Find_Trie(char *s,struct TrieNode *next)
{
    while(*s!='\0')
    {
        if(next->next[*s-'0']==NULL)
            {
                printf("eh\n");
                return 0;
            }
        next=next->next[*s-'0'];
        s++;
    }
    if(next->dc[0]=='\0')
        printf("eh\n");
     else
        printf("%s\n",next->dc);
    return 0;
}
int main()
{
    char ss[60];
    start(&trie);
    while(gets(ss)&&ss[0]!='\0')
    {
        sscanf(ss,"%s %s",bb,aa);
        ins_Trie(aa,&trie);
    }
    while(scanf("%s",aa)!=EOF)
        Find_Trie(aa,&trie);
    return 0;
}
