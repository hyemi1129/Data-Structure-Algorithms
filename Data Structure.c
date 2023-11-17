// 스택을 포함해서 모든 변수를 메모리 스택공간에 저장하면 메모리 효율이 나빠진다.
// 메모리 힙 공간을 적절히 활용하는 코드(malloc)를 보여준다면 면접관이 좋아한다.

#include <stdio.h>
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
}

// 스택 활용