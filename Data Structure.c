// 스택을 포함해서 모든 변수를 메모리 스택공간에 저장하면 메모리 효율이 나빠진다.
// 메모리 힙 공간을 적절히 활용하는 코드(malloc)를 보여준다면 면접관이 좋아한다.

/* #include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10 // 상수를 지정 전부 대문자

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	element top;
}Stack;

void initStack(Stack* s);
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, element data);
element pop(Stack* s);
element peek(Stack* s);

int main(){
	element data[MAX_STACK_SIZE];
	int i = 0;
	Stack* s = malloc(sizeof(Stack));
	printf("문자열 입력 : ");
	scanf("%s", data);
	while(data[i]){
		push(s, data[i]);
		i++;
	}
	while(!isEmpty(s)){
		printf ("%c", pop(s));
	}
}

//스텍 초기화(스텍의 요소들을 전부 삭제)
void initStack(Stack* s){
	// top 포인터를 -1로 변경해주기만 하면 된다.
	s->top = -1;
}

bool isFull(Stack* s){
	return (s->top == MAX_STACK_SIZE-1);
}

bool isEmpty(Stack* s){
	return (s->top == -1);
}

void push(Stack* s, element data){
	// 가득 찼다면? 푸시 거절
	if(isFull(s)){
		printf("stack is full\n");
		return;
	}
	//아니면 푸시
	s->data[++s->top] = data;
}

element pop(Stack* s){
	return s->data[s->top--];
}

element peek(Stack* s){
	return s->data[s->top];
} */

// 스택 활용


#include <stdio.h>
#include<stdlib.h>
#define MAX 200
typedef int element;
typedef struct{
	element item;
 //힙트리 구조체 정의
}HeapType;
//현재 요소의 개수가 heap_size인 히프 h에 item 삽입 
void insertMaxHeap(HeapType* h, element item){
	int i;
	i = ++(h->heap_size);
	while((i!=1) && (item.key  > h->heap[i/2].key/**/)){//삽입노드가 부모보다 크면
		h->heap[i] = h -> heap[i/2];//부모노드를 삽입위치로 교환
		i=i/2; //i는 부모노드 위치
	}
	h->heap[i]= item;//새로운 노드 삽입
}
element deleteMaxHeap(HeapType* h){ 
	int parent, child;
	element item, temp;
	item = h->heap[1];//루트노드 반환값
	temp = h->heap[(h->heap_size)--]//말단노드를 저장
	parent = 1;
	child = 2;
	while(child <= h->heap_size){
		//현재 노드의 자식 노드 중 더 큰 자식 노드를 검색
		if (child < h->heap_size && h->heap[child] < /*오른쪽노드*/ )
			child++;
		//검색된 자식노드가 말단노드이면 아래로 이동안함.	
		if (temp >= h->heap[child] ) break; 
		//한단계 아래로 이동
		h->heap[parent] = h->heap[child];//
		parent = child;//
		child *= 2;
	}
	h->heap[parent] = temp;//
	return item;
}
void printHeap(HeapType* heap){
	for(int i = 1;i<=heap->heap_size;i++)
		printf("[%d]: %d ",i, heap->heap[i]);
	printf("\n");
}
int main(){
	element e1 =10,e2=5,e3=30;
	HeapType* heap =//동적할당;
	heap->heap_size = 0;
	//삽입
	printf("최대힙 삽입\n");
	insertMaxHeap(heap,e1);	printHeap(heap);
	insertMaxHeap(heap,e2);	printHeap(heap);
	insertMaxHeap(heap,e3);	printHeap(heap);

	//삭제
	printf("최대힙 삭제\n");
	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	free(heap);
	return 0;
}

/* ↑ 이거 고치기 */