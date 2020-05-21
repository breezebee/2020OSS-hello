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
