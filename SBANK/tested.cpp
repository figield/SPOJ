#include <cstdio>
#include <map>
#include <string>
using namespace std;
map < string, int > accmap;
char line[34];

int main(){
    int n, t;
    for(scanf("%d", &t); t--; ){
        accmap.clear();
        for(scanf("%d\n", &n); n--; ){
            fgets(line, 34, stdin);
            line[32] = 0;
            ++accmap[line];
        }
        map < string, int >::iterator it;
        for(it = accmap.begin(); it != accmap.end(); it++)
            printf("%s%d\n", it->first.c_str(), it->second);
        if(t) puts("");
    }
}
