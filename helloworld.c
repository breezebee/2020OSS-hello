/* CRUD 성적관리 프로그램
1. 사용자 데이터 타입 정의
2. 데이터 추가 함수 구현
3. 데이터 보기 기능 구현
4. 데이터 수정 기능 구현
5. 데이터 삭제 기능 구현
6. 데이터 관리를 위한 메뉴 및 Main 완성
7. 다중 데이터 처리 구현
8. 파일 저장/불러오기 기능 구현
9. 검색 기능 구현
10. 라이브러리 생성
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1. 사용자 데이터 타입 정의
    필요한 변수 선언*/
typedef struct { //typedef로 구조체 정의 해주어 선언시마다 struct를 쓰지 않도록 해준다 
    char name[50]; 
    int weight; 
    int price; 
    int standardPrice;
    int starNum; 
}Snack; //이름 정의


int selectMenu(); 

/*2. 점수 추가 기능 구현*/
int addSnack(Snack *s); 
/*3. 입력한 점수 출력 기능 구현*/
void readSnack(Snack s);
/*4. 입력된 점수 수정 기능 구현*/
int updateSnack(Snack *s);
/*4. 입력된 점수 삭제 기능 구현*/
int deleteSnack(Snack *s); 

/*7. 다중 데이터 처리 구현*/
void listSnack(Snack *s, int count); 
int selectSnack(Snack *s, int count); 

/*8. 파일 저장/불러오기 기능 구현*/
void saveSnackList(Snack *s, int count);
int loadSnackList(Snack s[]);

/*9. 검색 기능 구현*/
void searchSnackName(Snack *s, int count); 
void searchSnackPrice(Snack *s, int count); 
void searchSnackStarNum(Snack *s, int count); 

int selectMenu(){ 
    int menu;
    printf("\n==과자관리 프로그램==\n");
    printf("1. 조회\n2. 추가\n3. 수정\n4. 삭제\n5. 저장\n6. 검색\n0. 종료\n\n");
    printf("원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addSnack(Snack *s){ //정보 직접 수정: 포인터로 받음
    printf("제품명은? ");
    getchar();
    fgets(s->name, 50, stdin);
    printf("중량은? ");
    scanf("%d", &s->weight);
    printf("가격은? ");
    scanf("%d", &s->price);
    printf("표준가격은? ");
    scanf("%d", &s->standardPrice);
    printf("별점수은? ");
    scanf("%d", &s->starNum);
    printf("\n=> 추가됨!\n");
    return 1; //잘 추가 되었는지 1 리턴
}

void readSnack(Snack s){ 
    printf("%8d원 %3dg %7d원 %4d점  %s", s.price, s.weight, s.standardPrice, s.starNum, s.name);
}
int updateSnack(Snack *s){ //정보 직접 수정: 포인터로 받음
    printf("제품명은? ");
    getchar();
    fgets(s->name, 50, stdin);
    printf("중량은? ");
    scanf("%d", &s->weight);
    printf("가격은? ");
    scanf("%d", &s->price);
    printf("표준가격은? ");
    scanf("%d", &s->standardPrice);
    printf("별점수은? ");
    scanf("%d", &s->starNum);
    printf("=> 수정됨!\n");
    return 1; //제대로 추가 되었는지 1 리턴
}
int deleteSnack(Snack *s){ //정보 직접 수정: 포인터로 받음
    s->weight= -1; 
    s->price= -1;
    s->standardPrice= -1;
    s->starNum= -1;
    printf("=> 삭제됨!\n");
    return 1; //삭제가 제대로 되었는지 확인
}


void listSnack(Snack *s, int count){ 
    //배열을 보내줌: 첫번째 두번째 세번째 등 반복문을 돌려야하므로
    //count: 몇번째 인덱스까지 입력 되었는지
    printf("\n번호    가격  중량 표준가격 별점수  제품명");
    printf("\n========================================\n");
    for(int i = 0; i< count; i++){
    if(s[i].weight == -1 && s[i].price == -1 && s[i].standardPrice == -1 && s[i].starNum){
        continue;
    }
    printf("%2d", i+1);
    readSnack(s[i]);
    printf("\n");
    }
}

int selectSnack(Snack *s, int count){ 
    //리스트를 보여줘야하기 때문에 배열 변수
	int num;
	listSnack(s, count);
    printf("번호를 고르세요 (취소: 0) ");
	scanf("%d", &num);
	return num;
}


void saveSnackList(Snack *s, int count){ //데이터 배열변수를 넘김
    FILE *fp; //파일 포인터 생성
    fp = fopen("snack.txt", "wt"); //파일 열기 fopen()
    for(int i=0; i<count; i++){ 
            //파일에 데이터 출력(쓰기) fprintf() fputs()
            if(s[i].weight != -1 || s[i].price != -1 || s[i].standardPrice != -1 || s[i].starNum != -1){
                    fprintf(fp,"%d %d %d %d %s", s[i].price, s[i].weight, s[i].standardPrice, s[i].starNum, s[i].name);
            }
    }
    fclose(fp); //파일 닫기
    printf("저장됨!\n");
}
int loadSnackList(Snack *s){ //데이터 배열변수를 넘김
    int count = 0;
    FILE *fp; //파일 포인터 생성
    fp = fopen("snack.txt", "rt"); //파일 열기 fopen()
    if(fp == NULL){ //파일이 없다면 종료
            printf("=> 파일 없음\n");
            return 0;
    }
    for( ; ; count++){
            //파일에 데이터 입력(읽기)
            fscanf(fp,"%d %d %d %d %[^\n]", &s[count].price, &s[count].weight, &s[count].standardPrice, &s[count].starNum, s[count].name);
            if(feof(fp)){ //파일의 끝
                    break;
            }
    }
    fclose(fp);
    printf("=>로딩 성공\n");
    return count; //count 리턴
}
