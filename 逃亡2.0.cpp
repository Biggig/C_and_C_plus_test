#include <stdio.h>
int main() {
    int i, m, s, t, ot, os;
    while (~scanf("%d%d%d", &m, &s, &t)) {
        ot = t;
        os = s;
        while (m >= 10 && t >= 1 && s > 0) {
            m -= 10;
            s -= 60;
            t--;
        }
        while (m < 10 && t >= 1) {//只有满足这些情况，才用魔法 ！！！！！ 
            if (m >= 0 && m <= 1 && s > 102 && t >= 7) {
                t -= 7;
                s -= 120;
            } else if (m >= 2 && m <= 5 && s > 34 && t >= 3) {
                t -= 3;
                s -= 60;
                m = (m + 8) % 10;
            } else if (m >= 6 && m <= 9 && s > 17 && t >= 2) {
                t -= 2;
                s -= 60;
                m = (m + 4) % 10;
            } else {
                break;
            }
        }
        while (t >= 1 && s > 0) {//否则，跑步 
            s -= 17;
            t--;
        }
        printf("%s\n%d\n", s > 0 ? "No" : "Yes", s > 0 ? os - s : ot - t);
    }
    return 0;
}
