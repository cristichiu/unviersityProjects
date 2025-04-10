#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    float r = 0;
    float i = 0;
    char num[30];
    cin>>num;

    char *pi, *pii;
    pi = strchr(num+1, '-');
    if(!pi) pi = strchr(num+1, '+');
    pii = strrchr(num, 'i');

    if(!pi) {
        i = atof(num);
        if(!i && pi) i = num[0] == '-' ? -1:1;
    } else {
        r = atof(num);
        i = atof(pi);
        if(!i && pii) i = pi[0] == '-' ? -1:1;
    }

    if(!pii) { r = i; i=0; }

    cout<<r<<" "<<i<<endl;

    return 0;
}
