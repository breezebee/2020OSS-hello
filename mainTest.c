#include "product.h"
#include "manager.h"
#include "saveload.h"
#include "search.h"

int main(void){
#ifdef DEBUG
	printf("Debug: [%s : %d] %s\n",__FILE__,__LINE__,__func__);
#endif
        Snack s[100];
        int count = 0, menu = 0;
        int curcount = 0;
	count = loadSnackList(s);
	curcount = count;
        while (1){
                menu = selectMenu();
                if (menu == 0) break;
                if (menu == 1 || menu == 3 || menu == 4){
                        if(count == 0){
                                continue;
                        }
                }
                if (menu == 1){
			if(count > 0){
                        	listSnack(s,curcount);
			}
                }
                else if (menu == 2){
                        count += addSnack(&s[curcount++]);
                }
                else if (menu == 3){
                        int no = selectSnack(s, curcount);
			if(no==0){
				printf("취소되었습니다.");
                                continue;
                        }
                        updateSnack(&s[no-1]);
                }
                else if (menu == 4){
                        int no, deleteok;
                        no = selectSnack(s, curcount);
                        if(no==0){
                                printf("취소되었습니다.");
                                continue;
                        }
                        printf("정말 삭제하시겠습니까?(예:1)");
                        scanf("%d", &deleteok);
                        if(deleteok == 1){
                                deleteSnack(&s[no-1]);
                                count--;
                        }
                }
		else if (menu == 5){
			if(count ==0){
                                printf("데이터가 없습니다!\n");
			}
			else{
				saveSnackList(s, curcount);
			}
		}
		else if (menu == 6){
			int searchMenu;
                        printf("어떤 검색을 하시겠습니까?\n1.이름검색\n2.가격검색\n3.별점검색\n\n");
                        printf("번호를 고르세요");
			scanf("%d", &searchMenu);
			switch(searchMenu){
				case 1 : searchSnackName(s, curcount); break;
				case 2 : searchSnackPrice(s,curcount); break;
				case 3 : searchSnackStarNum(s, curcount); break;
				default: break;
			}
		}	
	}
        printf("종료됨!\n");
        return 0;
}


