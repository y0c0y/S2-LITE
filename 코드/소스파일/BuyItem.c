#include "BuyItem.h"
int price[6] = { 400,300,700,4000,100, 0 };
int Select_Buy_Chioce = 0;

int movecnt = 0;

void startBuyItem()
{
    Select_Buy_Chioce = 0;
    Choice_Status = HP;
    Choice_Status_Before = HP;

    Select = C_WHITE;
    SelectBUY = 0;

    system("cls");

    num = 0;
    total = 0;

    state = 0;
    DrawItmeFirst();

    while (STATE != START_TOWN) {
        DrawBOX(Select, C_BLACK);

        if (Select == C_GREEN_)
        {
            Buttons();
            while (!DrawBuyItem());
            movecnt = 0;
        }

        while (1)
        {
            if (Select == C_WHITE) {
                if (DrawChoiceItem()) break;
                movecnt = 0;
            }

            if (Select == C_GREEN_)
            {
                if (DrawUpDown()) break;
                //movecnt = 0;

            }
        }

    }

}
void DrawItmeFirst()
{
    DrawHPPortion(C_GREEN_, C_BLACK);
    DrawMPPortion(C_WHITE, C_BLACK);
    DrawALLPortion(C_WHITE, C_BLACK);
    DrawEXPPortion(C_WHITE, C_BLACK);
    DrawGOLDBOX(C_WHITE, C_BLACK);
    DrawLEAVE(C_WHITE, C_BLACK);

    for (int y = 0; y < 50; y++)
    {
        gotoxy(120, y);
        printf("│");
    }

    drawInventory();
}

void drawInventory()
{
    for (int y = 2; y < 50; y++)
    {
        gotoxy(130, y);
        for (int x = 130; x < 150; x++)
            printf(" ");
    }

    gotoxy(136, 12);
    printf("<인벤토리>");
    gotoxy(132, 15);
    printf("돈 : %d 원", money);
    gotoxy(128, 18);
    printf("하급 강화의 돌 : %d 개", enhancementStone1);
    gotoxy(128, 20);
    printf("중급 강화의 돌 : %d 개", enhancementStone2);
    gotoxy(128, 22);
    printf("상급 강화의 돌 : %d 개", enhancementStone3);
    gotoxy(130, 24);
    printf("체력 포션 : %d 개", healingPotion);
    gotoxy(130, 27);
    printf("마나 포션 : %d 개", manaPotion);
    gotoxy(128, 29);
    printf("체력/마나 포션 : %d 개", allPotion);
    gotoxy(130, 31);
    printf("경험치 포션 : %d 개", expPotion);
}

int CheckMoney(int num)
{
    for (int x = 60; x < 90; x++) {
        for (int y = 22; y < 23; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    int sum = price[Choice_Status];

    sum *= num;
    if ((sum < 0 || (money < sum && num == 1)) || (level == 16 && Choice_Status == EXP))
    {
        gotoxy(60, 22);
        setcolor(C_RED_, C_BLACK);
        printf("구매가 불가능합니다.");
        setcolor(C_WHITE, C_BLACK);

        return -1;
    }
    else if (sum > money)
    {

        gotoxy(60, 22);
        setcolor(C_GREEN_, C_BLACK);
        printf("최대 수량에 도달했습니다");
        setcolor(C_WHITE, C_BLACK);

        return 1;
    }
    else
    {
        gotoxy(60, 22);
        setcolor(C_GREEN_, C_BLACK);
        printf("구매가 가능합니다.");
        setcolor(C_WHITE, C_BLACK);

        return 0;
    }
}

int MoneyGacha()
{
    int ran = rand() % 100 + 1;

    if (ran <= 20)
    {
        gotoxy(50, 39);
        printf("○ 배팅 금액 만큼 얻으셨습니다.");
        return -1;
    }
    else if (ran > 60)
    {
        gotoxy(50, 39);
        printf("□ 배팅 금액 만큼 잃으셨습니다.");
        return 1;
    }
    else
    {
        gotoxy(50, 39);
        printf("△ 소유 금액 변동이 없습니다.");
        return 0;
    }
}

int DrawChoiceItem() {

    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            switch (key) {
            case UP:
                RemoveItemInstructions();

                if (Choice_Status != HP) {
                    Choice_Status_Before = Choice_Status;
                    Choice_Status--;
                    DrawSelect(Choice_Status_Before, Choice_Status);
                }

                DrawItemInstructions();

                break;
            case DOWN:
                RemoveItemInstructions();

                if (Choice_Status != LEAVE) {
                    Choice_Status_Before = Choice_Status;
                    Choice_Status++;
                    DrawSelect(Choice_Status_Before, Choice_Status);
                }

                DrawItemInstructions();

                break;

            case ENTER:
                if (Choice_Status == LEAVE)
                {
                    RemoveItemInstructions();
                    STATE = START_TOWN;
                    return 1;
                }
                if (Select == C_WHITE) {
                    if (!CheckMoney(1)) {
                        Select = C_GREEN_;
                        gotoxy(60, 22);
                        printf("                ");
                        DrawBOX(Select, C_BLACK);
                        return 1;
                    }
                }
                break;
            }
        }
    }
    return 0;
}


int DrawUpDown() {

    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            switch (key) {
            case UP:

                SelectUP();
                num++;
                if (CheckMoney(num) == 1) num -= 1;

                gotoxy(60, 29);  printf("         ");
                gotoxy(60, 29);  printf("구매 : %d개", num);
                gotoxy(60, 31);  printf("                   ");
                gotoxy(60, 31);  printf("총 금액: %d", price[Choice_Status] * num);
                break;

            case DOWN:

                SelectDOWN();
                num--;
                if (CheckMoney(num) == -1)num = 0;

                gotoxy(60, 29);  printf("         ");
                gotoxy(60, 29);  printf("구매 : %d개", num);
                gotoxy(60, 31);  printf("                   ");
                gotoxy(60, 31);  printf("총 금액: %d", price[Choice_Status] * num);
                break;
            case LEFT:
                if (Select_Buy_Chioce) {
                    SelectBUYItem_Choice();
                    Select_Buy_Chioce = 1;
                }
                break;
            case RIGHT:

                if (Select_Buy_Chioce) {
                    ReturnBUYItem_Choice();
                    Select_Buy_Chioce = 2;
                }
                break;
            case ENTER:
                if (movecnt)
                {
                    if (!Select_Buy_Chioce) {
                        Select_Buy_Chioce = 1;
                        Show_Choice();
                        movecnt = 0;
                    }
                    else if (Select_Buy_Chioce) {
                        if (movecnt)
                        {
                            if (Select_Buy_Chioce == 2) {
                                Select = C_WHITE;
                                num = 0;
                                Select_Buy_Chioce = 0;
                            }
                            else {
                                total = price[Choice_Status] * num;
                                if (Choice_Status == GOLD)
                                    total *= MoneyGacha(num);
                                Calculate();
                                Sleep(1000);
                                if (Choice_Status == EXP)
                                {
                                    UsingEXPPortion();

                                }
                                SetZero();
                                Select_Buy_Chioce = 0;
                            }
                            gotoxy(60, 22);
                            printf("                ");
                            return 1;
                        }

                    }
                }

                break;

            }
        }
    }
    return 0;

}
void Box(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(30, 5); printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");//0
    gotoxy(30, 6); printf("┃                                                                           ┃");//1
    gotoxy(30, 7); printf("┃                                                                           ┃");//1
    gotoxy(30, 8); printf("┃                                                                           ┃");//1
    gotoxy(30, 9); printf("┃                                                                           ┃");//1
    gotoxy(30, 10); printf("┃                                                                           ┃");//1
    gotoxy(30, 11); printf("┃                                                                           ┃");//1
    gotoxy(30, 12); printf("┃                                                                           ┃");//1
    gotoxy(30, 13); printf("┃                                                                           ┃");//1
    gotoxy(30, 14); printf("┃                                                                           ┃");//1
    gotoxy(30, 15); printf("┃                                                                           ┃");//1
    gotoxy(30, 16); printf("┃                                                                           ┃");//1
    gotoxy(30, 17); printf("┃                                                                           ┃");//1
    gotoxy(30, 18); printf("┃                                                                           ┃");//1
    gotoxy(30, 19); printf("┃                                                                           ┃");//1
    gotoxy(30, 20); printf("┃                                                                           ┃");//1
    gotoxy(30, 21); printf("┃                                                                           ┃");//1
    gotoxy(30, 22); printf("┃                                                                           ┃");//1
    gotoxy(30, 23); printf("┃                                                                           ┃");//1
    gotoxy(30, 24); printf("┃                                                                           ┃");//1
    gotoxy(30, 25); printf("┃                                                                           ┃");//1
    gotoxy(30, 26); printf("┃                                                                           ┃");//1
    gotoxy(30, 27); printf("┃                                                                           ┃");//1
    gotoxy(30, 28); printf("┃                                                                           ┃");//1
    gotoxy(30, 29); printf("┃                                                                           ┃");//1
    gotoxy(30, 30); printf("┃                                                                           ┃");//1
    gotoxy(30, 31); printf("┃                                                                           ┃");//1
    gotoxy(30, 32); printf("┃                                                                           ┃");//1
    gotoxy(30, 33); printf("┃                                                                           ┃");//1
    gotoxy(30, 34); printf("┃                                                                           ┃");//1
    gotoxy(30, 35); printf("┃                                                                           ┃");//1
    gotoxy(30, 36); printf("┃                                                                           ┃");//1
    gotoxy(30, 37); printf("┃                                                                           ┃");//1
    gotoxy(30, 38); printf("┃                                                                           ┃");//1
    gotoxy(30, 39); printf("┃                                                                           ┃");//1
    gotoxy(30, 40); printf("┃                                                                           ┃");//1
    gotoxy(30, 41); printf("┃                                                                           ┃");//1
    gotoxy(30, 42); printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    setcolor(C_WHITE, C_BLACK);
}
void SetEXP()
{
    system("cls");
    DrawHPPortion(C_WHITE, C_BLACK);
    DrawMPPortion(C_WHITE, C_BLACK);
    DrawALLPortion(C_WHITE, C_BLACK);
    DrawEXPPortion(C_GREEN_, C_BLACK);
    DrawGOLDBOX(C_WHITE, C_BLACK);
    DrawLEAVE(C_WHITE, C_BLACK);

    for (int y = 0; y < 50; y++)
    {
        gotoxy(120, y);
        printf("│");
    }

    drawInventory();

    Box(C_GREEN_, C_BLACK);
}

void drawPlusEXP(double plus)
{
    // 경험치 출력

    RemoveItemInstructions();
    drawInventory();

    int ratioExp = pcExp / (maxExp / 60.0f);
    int exRatio = ratioExp;
    char str[50];

    gotoxy(49, 7); printf("<     경 험 치   물 약   사 용 하 기    >"); Sleep(100);
    gotoxy(49, 10); printf("  적용 전 :  Lv. %d    경험치 (%6d/%6d)", level, pcExp, maxExp); Sleep(100);
    gotoxy(33, 14); printf("exp ");
    setcolor(C_WHITE, C_GREEN);
    for (int i = 0; i < ratioExp; i++)
        printf(" ");
    setcolor(C_WHITE, C_GRAY);
    for (int i = ratioExp; i < 60; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);

    Sleep(1000);

    plus *= maxExp;

    if (level == 15)
    {
        if (pcExp + plus > pcStatTable[5][level])
        {
            plus = pcStatTable[5][level] - pcExp;
        }
    }

    pcExp += plus;

    while (pcStatTable[5][level] <= pcExp) {
        pcExp -= pcStatTable[5][level];
        pcLevelUp();
        if (level == 5 || level == 9 || level == 13)
        {
            selectSkill();
            SetEXP();
            gotoxy(49, 7); printf("<     경 험 치   물 약   사 용 하 기    >"); Sleep(100);
            gotoxy(49, 10); printf("  적용 전 :  Lv. %d    경험치 (%6d/%6d)", level, pcExp, maxExp); Sleep(100);
            gotoxy(33, 14); printf("exp ");
            setcolor(C_WHITE, C_GREEN);
            for (int i = 0; i < exRatio; i++)
                printf(" ");
            setcolor(C_WHITE, C_GRAY);
            for (int i = exRatio; i < 60; i++)
                printf(" ");
            setcolor(C_WHITE, C_BLACK);
        }
    }

    ratioExp = pcExp / (maxExp / 50.0f);

    gotoxy(49, 17); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 18); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 19); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 20); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 21); printf("                                          "); Sleep(100);
    gotoxy(49, 22); printf("         경험치 %.2lf를 얻었습니다.       ", plus); Sleep(100);
    gotoxy(49, 23); printf("                                          "); Sleep(100);
    gotoxy(49, 24); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 25); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 26); printf("                  ┃  ┃                  "); Sleep(100);
    gotoxy(49, 27); printf("               ___┃  ┃___               "); Sleep(100);
    gotoxy(49, 28); printf("               ＼       /                 "); Sleep(100);
    gotoxy(49, 29); printf("                 ＼    /                  "); Sleep(100);
    gotoxy(49, 30); printf("                   ＼ /                   "); Sleep(100);
    gotoxy(49, 31); printf("                     ˇ                   "); Sleep(100);

    gotoxy(49, 34); printf("  적용 후 :  Lv. %d    경험치 (%6d/%6d)", level, pcExp, maxExp);//1
    gotoxy(33, 37); printf("exp ");
    setcolor(C_WHITE, C_GREEN);
    for (int i = 0; i < ratioExp; i++)
        printf(" ");
    setcolor(C_WHITE, C_GRAY);
    for (int i = ratioExp; i < 60; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);

    Sleep(1000);
}


void UsingEXPPortion()
{
    SetEXP();

    double tmp = 0.f;
    int i = 0;
    int expP = expPotion;
    int t = 0;
    while (1)
    {
        if (t == expP) break;
        if (level < 16)
        {
            tmp = ((rand() % 51) + 10) * 1.0 / 100;
            
            drawPlusEXP(tmp);

            expPotion--;

        }
        
        else
        {
            money += expPotion * price[EXP];
            expPotion = 0;
            break;
        }

    }
  
}

void Show_Choice()
{
    for (int x = 50; x < 70; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(50, 35); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(50, 36); printf("┃   구매하기   ┃");//1
    gotoxy(50, 37); printf("┗━━━━━━━━━━━━━━┛");

    for (int x = 70; x < 90; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);

    gotoxy(70, 35); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(70, 36); printf("┃  아이템 선택 ┃");//1
    gotoxy(70, 37); printf("┗━━━━━━━━━━━━━━┛");
}
void ReturnBUYItem_Choice()
{
    movecnt++;

    for (int x = 50; x < 65; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(50, 35); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(50, 36); printf("┃   구매하기   ┃");//1
    gotoxy(50, 37); printf("┗━━━━━━━━━━━━━━┛");

    for (int x = 70; x < 90; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);

    gotoxy(70, 35); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(70, 36); printf("┃  아이템 선택 ┃");//1
    gotoxy(70, 37); printf("┗━━━━━━━━━━━━━━┛");
}
void SelectBUYItem_Choice()
{
    movecnt++;

    for (int x = 50; x < 65; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);
    gotoxy(50, 35); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(50, 36); printf("┃   구매하기   ┃");//1
    gotoxy(50, 37); printf("┗━━━━━━━━━━━━━━┛");

    for (int x = 70; x < 90; x++) {
        for (int y = 35; y < 40; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);

    gotoxy(70, 35); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(70, 36); printf("┃  아이템 선택 ┃");//1
    gotoxy(70, 37); printf("┗━━━━━━━━━━━━━━┛");
}

int DrawBuyItem() {

    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            switch (key) {
            case LEFT:
                if (!Select_Buy_Chioce) {
                    SelectBUYItem();
                }
                break;
            case RIGHT:
                if (!Select_Buy_Chioce) {
                    ReturnSelectItem();
                }
                break;
            case ENTER:
                if (Choice_Status == LEAVE)
                {
                    STATE = START_TOWN;
                    return 1;
                }
                if (movecnt)
                {
                    if (!SelectBUY) {
                        gotoxy(60, 22);
                        printf("                ");
                        DrawBOX(Select, C_BLACK);
                        Select = C_GREEN_;
                        state = 1;
                        UPandDOWN();
                        return 1;
                    }
                    else {
                        Select = C_WHITE;
                        num = 0;
                        gotoxy(60, 22);
                        printf("                ");
                        RemoveItemInstructions();
                        DrawBOX(Select, C_BLACK);
                        return 1;
                    }
                }
                break;
            }
        }
    }
    return 0;
}

void SelectDOWN()
{
    movecnt++;

    for (int x = 80; x < 90; x++) {
        for (int y = 26; y < 29; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(80, 26); printf("┏━┓");//0
    gotoxy(80, 27); printf(" ↑");//1
    gotoxy(80, 28); printf("┗━┛");

    for (int x = 80; x < 90; x++) {
        for (int y = 30; y < 33; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);

    gotoxy(80, 30); printf("┏━┓");//0
    gotoxy(80, 31); printf(" ↓");//1
    gotoxy(80, 32); printf("┗━┛");


}

void SelectUP()
{
    movecnt++;
    for (int x = 80; x < 90; x++) {
        for (int y = 26; y < 29; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);
    gotoxy(80, 26); printf("┏━┓");//0
    gotoxy(80, 27); printf(" ↑");//1
    gotoxy(80, 28); printf("┗━┛");

    for (int x = 80; x < 90; x++) {
        for (int y = 30; y < 33; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);

    gotoxy(80, 30); printf("┏━┓");//0
    gotoxy(80, 31); printf(" ↓");//1
    gotoxy(80, 32); printf("┗━┛");
}

void UPandDOWN() {

    setcolor(C_WHITE, C_BLACK);

    gotoxy(60, 29);  printf("         ");
    gotoxy(60, 29);  printf("구매 : %d개", num);
    gotoxy(60, 31);  printf("                   ");
    gotoxy(60, 31);  printf("총 금액: %d", price[Choice_Status] * num);

    gotoxy(80, 26); printf("┏━┓");//0
    gotoxy(80, 27); printf(" ↑");//1
    gotoxy(80, 28); printf("┗━┛");
    gotoxy(80, 30); printf("┏━┓");//0
    gotoxy(80, 31); printf(" ↓");//1
    gotoxy(80, 32); printf("┗━┛");
}


void SelectBUYItem()
{
    SelectBUY = 0;
    movecnt++;
    for (int x = 50; x < 90; x++) {
        for (int y = 20; y < 27; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_GREEN_, C_BLACK);
    gotoxy(50, 20); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(50, 21); printf("┃   구매하기   ┃");//1
    gotoxy(50, 22); printf("┗━━━━━━━━━━━━━━┛");

    setcolor(C_WHITE, C_BLACK);

    gotoxy(70, 20); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(70, 21); printf("┃  아이템 선택 ┃");//1
    gotoxy(70, 22); printf("┗━━━━━━━━━━━━━━┛");
}

void ReturnSelectItem()
{
    SelectBUY = 1;
    movecnt++;
    setcolor(C_WHITE, C_BLACK);
    for (int x = 50; x < 90; x++) {
        for (int y = 20; y < 27; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(50, 20); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(50, 21); printf("┃   구매하기   ┃");//1
    gotoxy(50, 22); printf("┗━━━━━━━━━━━━━━┛");

    setcolor(C_GREEN_, C_BLACK);
    gotoxy(70, 20); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(70, 21); printf("┃  아이템 선택 ┃");//1
    gotoxy(70, 22); printf("┗━━━━━━━━━━━━━━┛");
}

void Buttons() {

    setcolor(C_WHITE, C_BLACK);
    for (int x = 50; x < 90; x++) {
        for (int y = 20; y < 27; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(50, 20); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(50, 21); printf("┃   구매하기   ┃");//1
    gotoxy(50, 22); printf("┗━━━━━━━━━━━━━━┛");

    gotoxy(70, 20); printf("┏━━━━━━━━━━━━━━┓");//0
    gotoxy(70, 21); printf("┃  아이템 선택 ┃");//1
    gotoxy(70, 22); printf("┗━━━━━━━━━━━━━━┛");
}

void SetZero()
{
    Choice_Status = HP;
    Choice_Status_Before = HP;

    Select = C_WHITE;
    SelectBUY = 0;

    system("cls");

    num = 0;
    total = 0;

    DrawItmeFirst();
}
void Calculate()
{

    switch (Choice_Status)
    {
    case HP:
        healingPotion += num; //HP
        money -= total;

        break;
    case MP:
        manaPotion += num;//MP
        money -= total;

        break;
    case EXP:
        expPotion += num;//EXP
        money -= total;
        break;
    case ALL:
        allPotion += num;//ALL
        money -= total;

        break;
    case GOLD:
        money -= total;
        total *= -1;
    default:
        break;
    }
    gotoxy(60, 41); printf("총 금액 : %d 원", total);


}



void DrawBOX(int color, int bgcolor)
{
    Box(color, bgcolor);

    if (Choice_Status != LEAVE) DrawItemInstructions();
}


void DrawItemInstructions()
{
    switch (Choice_Status)
    {
    case HP:
        gotoxy(49, 7); printf("<      아  이  템     세  부  정  보    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** H P 포 션 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           가격 : 400 원                 ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           효과                          ");//1
        gotoxy(49, 17); printf("           - 최대 체력의 30%% 회복       ");//1
        gotoxy(49, 18); printf("                                         ");//1
        break;
    case MP:
        gotoxy(49, 7); printf("<      아  이  템     세  부  정  보    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** M P 포 션 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           가격 : 300 원                 ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           효과                          ");//1
        gotoxy(49, 17); printf("           - 최대 마나의 30%% 회복       ");//1
        gotoxy(49, 18); printf("                                         ");//1
        break;

    case ALL:
        gotoxy(49, 7); printf("<      아  이  템     세  부  정  보    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** ALL 포 션 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           가격 : 700 원                 ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           효과                          ");//1
        gotoxy(49, 17); printf("           - 최대 마나와 체력의          ");//1
        gotoxy(49, 18); printf("             30%%를 회복                 ");//1
        break;

    case EXP:
        gotoxy(49, 7); printf("<      아  이  템     세  부  정  보    >");//1
        gotoxy(49, 11); printf("                                         ");//1
        gotoxy(49, 12); printf("        ****** EXP 포 션 ******          ");//1
        gotoxy(49, 13); printf("                                         ");//1
        gotoxy(49, 14); printf("           가격 : 4000 원                ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("           효과                          ");//1
        gotoxy(49, 17); printf("           - 최대 경험치의 10 ~ 60%%를   ");//1
        gotoxy(49, 18); printf("             랜덤으로 부여               ");//1
        break;

    case GOLD:
        gotoxy(49, 7); printf("<      아  이  템     세  부  정  보    >");//1
        gotoxy(49, 11); printf("        ****** 골드 박스 ******          ");//1
        gotoxy(49, 12); printf("                                         ");//1
        gotoxy(49, 13); printf("            가격 : 배팅금액              ");//1
        gotoxy(49, 14); printf("     버튼 한번 누를때 마다 100원씩 증감  ");//1
        gotoxy(49, 15); printf("                                         ");//1
        gotoxy(49, 16); printf("     - ○(20%%) : (베팅금액) 만큼 받기   ");//1
        gotoxy(49, 17); printf("     - △(40%%) : (베팅금액) 돌려 받기   ");//1
        gotoxy(49, 18); printf("     - □(40%%) : (베팅금액) 만큼 잃기   ");//1
        break;

    default:
        break;
    }
}

//초기화
void RemoveItemInstructions()
{
    for (int y = 7; y < 40; y++)
    {
        for (int x = 32; x <= 105; x++)
        {
            gotoxy(x, y);
            printf(" ");
        }
    }
}

void DrawSelect(int before, int after)
{

    switch (before)
    {
    case HP:
        DrawHPPortion(C_WHITE, C_BLACK);
        break;
    case MP:
        DrawMPPortion(C_WHITE, C_BLACK);
        break;
    case ALL:
        DrawALLPortion(C_WHITE, C_BLACK);
        break;
    case EXP:
        DrawEXPPortion(C_WHITE, C_BLACK);
        break;
    case GOLD:
        DrawGOLDBOX(C_WHITE, C_BLACK);
        break;
    case LEAVE:
        DrawLEAVE(C_WHITE, C_BLACK);
        break;
    }
    switch (after)
    {
    case HP:
        DrawHPPortion(C_GREEN_, C_BLACK);
        break;
    case MP:
        DrawMPPortion(C_GREEN_, C_BLACK);
        break;
    case ALL:
        DrawALLPortion(C_GREEN_, C_BLACK);
        break;
    case EXP:
        DrawEXPPortion(C_GREEN_, C_BLACK);
        break;
    case GOLD:
        DrawGOLDBOX(C_GREEN_, C_BLACK);
        break;
    case LEAVE:
        DrawLEAVE(C_GREEN_, C_BLACK);
        break;
    }
}

void DrawHPPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 5); printf("┏━━━━━━━━━━━┓");//0
    gotoxy(10, 6); printf("┃  H P 포션 ┃");//1
    gotoxy(10, 7); printf("┗━━━━━━━━━━━┛");
    setcolor(C_WHITE, C_BLACK);
}
void DrawMPPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 12); printf("┏━━━━━━━━━━━┓");
    gotoxy(10, 13); printf("┃  M P 포션 ┃");//1
    gotoxy(10, 14); printf("┗━━━━━━━━━━━┛");
    setcolor(C_WHITE, C_BLACK);
}
void DrawALLPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 19); printf("┏━━━━━━━━━━━┓");
    gotoxy(10, 20); printf("┃  ALL 포션 ┃");
    gotoxy(10, 21); printf("┗━━━━━━━━━━━┛");
    setcolor(C_WHITE, C_BLACK);
}

void DrawEXPPortion(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 26); printf("┏━━━━━━━━━━━┓");
    gotoxy(10, 27); printf("┃  EXP 포션 ┃");
    gotoxy(10, 28); printf("┗━━━━━━━━━━━┛");
    setcolor(C_WHITE, C_BLACK);
}

void DrawGOLDBOX(int color, int bgcolor)
{
    setcolor(color, bgcolor);

    gotoxy(10, 33); printf("┏━━━━━━━━━━━┓");
    gotoxy(10, 34); printf("┃  골드박스 ┃");
    gotoxy(10, 35); printf("┗━━━━━━━━━━━┛");;
    setcolor(C_WHITE, C_BLACK);
}

void DrawLEAVE(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(10, 40); printf("┏━━━━━━━━━━━┓");
    gotoxy(10, 41); printf("┃  나 가 기 ┃");
    gotoxy(10, 42); printf("┗━━━━━━━━━━━┛");
    setcolor(C_WHITE, C_BLACK);
}
