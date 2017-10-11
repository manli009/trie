//1.给你100000个长度不超过10的单词。对于每一个单词，我们要判断他出没出现过
#include <iostream>
using namespace std;

typedef struct node{
    struct node* next[26];
}trie_node;

trie_node* create_node() {
    trie_node *p  = new trie_node;
    for (int i = 0; i < 26; ++i)
        p->next[i] = NULL;
    return p;
}

void insert_str(char str[], trie_node* head){
    int len1 = strlen(str);
    trie_node *q, *tmp = head;
    for (int i = 0; i < len1; ++i) {
        int c = str[i] - 'a';
        if(!tmp->next[c]) {
            q = create_node();
            tmp->next[c] = q;
            tmp = tmp->next[c];
        }
        else
            tmp = tmp->next[c];
    }
}


void search_str(char str[], trie_node* head){
    int len = strlen(str);
    trie_node* tmp = head;
    for (int i = 0; i < len; ++i) {
        int c = str[i] - 'a';
        if(!tmp->next[c]) {
            cout <<"not find the string" <<endl;
            return;
        }
        else {
            tmp = tmp->next[c];
        }
    }
    cout <<"find the string" <<endl;
    return;
}

int main()
{
    char s[10];
    trie_node *head = create_node();
    do{
        cin >> s;
        insert_str(s,head);
    } while(getchar() != '\n');
    search_str("ab", head);
    return 0;
}
