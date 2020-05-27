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

