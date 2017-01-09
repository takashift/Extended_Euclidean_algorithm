#include <stdio.h>

int Euclidean(int arg_m, int arg_n)
{
    int change;
    int m[100];
    m[1] = arg_m;
    int n[100];
    n[1] = arg_n;
    int l[100];
    
    if (m[1] < n[1]){
        change = n[1];
        n[1]=m[1];
        m[1]=change;
    }
    
    int i = 0;
    int r = m[1] % n[1];
    do {
        i++;
        l[i] = m[i]/n[i];
        printf("%d = %d * %d + ", m[i], n[i], l[i]);
        m[i+1] = n[i];
        n[i+1] = r;
        r = m[i+1] % n[i+1];
        printf("%d・・・(%d)\n", n[i+1], i);
    } while (r != 0);
    
    int imax = i;
    
    if (r == 0){
        printf("%d = %d * %d\n", m[i+1], n[i+1], m[i+1]/n[i+1]);
    }
    
    int gcd = n[imax + 1];
    printf("よりG.C.D.(%d, %d) = %d\n", arg_m, arg_n, gcd);
    
    while (i>0) {
        printf("(%d)より\n", i);
        printf("  %d = %d - %d * %d・・・(%d)'\n", n[i+1], m[i], n[i], l[i], i);
        i--;
    }
    
    int j = imax+1;
    int a[100];
    int b[100];
    int x[100];
    int y[100];
    
    if (imax == 1){
        a[j] = m[imax];
        x[j] = 1;
        b[j] = n[imax];
        y[j] = l[imax]*(-1);
        printf("  %d = %d * (%d) + %d * (%d)・・・(%d)\n", n[imax+1], a[j], x[j], b[j], y[j], j);
    }
    else {
        i = imax-1;
        printf("(%d)'を(%d)'に代入\n", imax-1, imax);
        a[j] = n[i];
        x[j] = l[i] * l[imax] + 1;
        b[j] = m[i];
        y[j] = l[imax]*(-1);
        printf("  %d = %d * (%d) + %d * (%d)・・・(%d)\n", n[imax+1], a[j], x[j], b[j], y[j], j);
    }
    
    while (i > 1) {
        i--;
        printf("(%d)'を(%d)に代入\n", i, j);
        j++;
        if (n[i+1] == a[j-1]) {
            x[j] = x[j-1];
            y[j] = l[i]*(-1) * x[j-1] + y[j-1];
            a[j] = m[i];
            b[j] = n[i];
        }
        else if(n[i+1] == b[j-1]) {
            x[j] = l[i]*(-1) * y[j-1] + x[j-1];
            y[j] = y[j-1];
            a[j] = n[i];
            b[j] = m[i];
        }
        printf("  %d = %d * (%d) + %d * (%d)・・・(%d)\n", n[imax+1], a[j], x[j], b[j], y[j], j);
    }
    
    printf("よって（%d, %d）\n", x[j], y[j]);
    
    return gcd;
}

int main(){
    int ax;
    int b;
    int mod;
    int gcd;
    int change;
    
    while (1) {
        printf("(終了時はa:0)\n数値a:");
        scanf("%d", &ax);

        if(ax==0)
            break;
        
        printf("b:");
        scanf("%d", &mod);
       
        gcd = Euclidean(ax, mod);
        
        printf("\n");
    }
    
    return 0;
}
