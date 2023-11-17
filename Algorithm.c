//퀵 정렬 -- 기말 문제

#include <stdio.h>

int cnt ,n;
int partiiton(int list[], int left, int right){
    int pivot, low, high, temp;
    low = left;
    high = right+1;
    pivot = list[left];
    do{
        do{
            low++;
        }while(pivot<list[low]);
        do{
            high--;
        }while(pivot>list[high]);
        if(low<high){
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    }while(low<high);
    temp = list[high];
    list[high] = list[left];
    list[left] = temp;
    return high;
}

void quicksort(int list[], int left, int right){
    int q;
    if(left<right){
        cnt++;
        q = partiiton(list, left, right);
        printf("%d단계 : ", cnt);
        for(int i=0; i<n; i++)
            printf("%d ", list[i]);
        printf("\n");
        quicksort(list, left, q-1);
        quicksort(list, q+1, right);
    }
}

int main(){
    int list[65];
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d ", list[i]);
    }
    quicksort(list, 0, n-1);
    for(int i=0; i<n; i++)
        printf("%d ", list[i]);
}

// 합병정렬

#include <stdio.h>

int sorted[100];

int cnt, n;
void merge(int list[],int left, int mid, int right)
{
   int i,j,k,l;
   i=left;
   j=mid+1;
   k=left;
   while(i<=mid && j<=right)
   {
      if(list[i]>=list[j])
         sorted[k++]=list[i++];
      else
         sorted[k++]=list[j++];
   }
   if(i>mid)
   {
      for(l=j;l<=right;l++)
         sorted[k++]=list[l];
   }
   else
   {
      for(l=i;l<=mid;l++)
         sorted[k++]=list[l];
   }
   for(l=left;l<=right;l++)
      list[l]=sorted[l];
}
void mergesort(int list[], int left, int right)
{
   int mid;
   if(left<right)
   {
      
      mid=(left+right)/2;
      mergesort(list, left, mid);
      mergesort(list, mid+1, right);
      merge(list,left,mid,right);
      printf("%d단계 : ", ++cnt);
      for(int i=0; i<n; i++)
            printf("%d ",list[i]);
       printf("\n");      
   }
}
int main() 
{
   int list[65];
   int i;
   scanf("%d", &n);
   for(i=0;i<n; i++){
      scanf("%d", &list[i]);
   }
    mergesort(list,0,n-1);
   
    return 0;
}

// 분할정복법 알고리즘 문제1

#include <stdio.h>

int b[9];
int main() {
	char a[101];
	int b[9]={0};
	int i, max=-1, index;
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		b[a[i]-'0']++;
	}
	for(i=0;i<10;i++){
		if(b[i]>=max){
			max=b[i];
			index=i;
		}
	}
	printf("%d", index);
	return 0;
}

// 분할정복법 알고리즘 문제3

#include <stdio.h>

int main() {
	int n, m, data, i, cnt=0, max=-1;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d", &data);
		if(data>m){
			cnt++;
			if(cnt>max)
				max = cnt;
		}
		else cnt = 0;
	}
	printf("%d", max);	
	
	return 0;
}

// 분할정복법 알고리즘 문제4

#include <stdio.h>

int main() {
	int a[2][100];
	int i, j, n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[0][i]);
		a[1][i]=1;
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(a[0][i]<a[0][j])
				a[1][i]++;
		}
	}
	for(i=0; i<n; i++){
		printf("%d", a[1][i]);
	}
	return 0;
}