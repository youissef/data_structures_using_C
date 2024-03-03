#include <stdio.h>
#include <string.h>

#define max 100
typedef char element;
typedef element Pile[max];
// golbales variables
Pile p;
int summit;
// Pile manipulation
void initialisation(){
    summit = -1;
}
int pile_empty(){
    return(summit < 0);
}
int pile_full(){
    return(summit >= max-1);
}
// push
void empiler(element x) {
    if (pile_full())
        printf("Stack is Full!\n");
    else {
        summit++;
        p[summit] = x;
    }
}
char depiler() {
    char x;
    if (pile_empty())
        printf("Pile is empty\n");
    else {
        x = p[summit];
        summit--;
        return x;
    }
}
// palindrome
int palindrome(element ch[max]) {
    int valid = 1, i, lg;
    char x;
    lg = strlen(ch);
    for (i = 0; i < (lg / 2); i++) {
        empiler(ch[i]);
    }
    i = (lg / 2) + 1;
    while (!pile_empty() && valid && i < lg) {
        x = depiler();
        if (x != ch[i])
            return 0;
        i++;
    }
    return 1;
}
// main function
int main() {
    element chaine[max];
    int r;
    printf("Enter a string: ");
    fgets(chaine, sizeof(chaine), stdin);
    chaine[strlen(chaine) - 1] = '\0';
    initialisation();
    r = palindrome(chaine);
    if (r == 1)
        printf("%s is a palindrome.\n", chaine);
    else
        printf("%s is not a palindrome.\n", chaine);

    return 0;
}
