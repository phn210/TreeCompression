#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

/* nhap tu ban phim so canh, sau do nhap lan luot cac canh cua cay*/

struct CANH
    {
        int dinhTren;
        int dinhDuoi;
    };
CANH* canh;

int timKiem(int x, CANH* canh, int n)
{
    int i,tontai=0;
    for(i=0;i<n;i++)
    {
        if ((canh[i].dinhTren==x&&canh[i].dinhTren!=0)||(canh[i].dinhDuoi==x&&canh[i].dinhDuoi!=0))
        {
            tontai=1; break;
        }
    }
    if (tontai) return i;
    else return -1;
}

int main()
{
    int n,i=0;
    cout << "Nhap so canh: ";//nhap vao so canh n cua cay
    cin >> n;
    CANH* canh;
    canh = (CANH*)calloc(n,sizeof(CANH));
    for(i=0;i<n;i++)
    {
        cout << "Nhap canh thu " << i+1 << endl;
        cin >> canh[i].dinhTren >> canh[i].dinhDuoi;// nhap lan luot cac canh cua cay
    }
    int bac[1001];
    for(i=0;i<=n;i++) bac[i]=0;
    for(i=0;i<n;i++)
    {
        bac[canh[i].dinhTren]++;
        bac[canh[i].dinhDuoi]++;
    }
    CANH* prufer;
    prufer = (CANH*)calloc(n,sizeof(CANH));
    int k; // k la vi tri cua dinh bac 1 nho nhat
    int j=0;
    for(i=0;i<=n;i++)
    {
        if (bac[i]==1&&i!=0)
        {
            k=timKiem(i,canh,n);
            if (k!=-1)
            {
                if (bac[canh[k].dinhTren]>=bac[canh[k].dinhDuoi])
                {
                    prufer[j].dinhTren=canh[k].dinhDuoi;
                    prufer[j].dinhDuoi=canh[k].dinhTren;
                }
                else
                {
                    prufer[j].dinhTren=canh[k].dinhTren;
                    prufer[j].dinhDuoi=canh[k].dinhDuoi;
                }
                bac[canh[k].dinhDuoi]--;
                bac[canh[k].dinhTren]--;
                bac[0]=bac[0]+2;
                j++;
                canh[k].dinhTren=0;
                canh[k].dinhDuoi=0;
                i=0;
            }
        }
    }
    cout << "Prufer code cua cay la: ";
    for (i=0;i<n-1;i++)
    {
        cout << prufer[i].dinhDuoi << " ";
    }
    free(canh); free(prufer);
    return 0;
}
