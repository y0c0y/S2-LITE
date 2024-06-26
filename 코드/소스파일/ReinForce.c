#include "ReinForce.h"
ReinForce_Select = BRACELET;
ReinForce_Select_Before = BRACELET;
Choose_OK = C_WHITE;
SELECT_SWITCH = 0;
int JangGiBAEK[5] = { 0, };

//鬼�� 綠辨 塽 в蹂и 匙

int equipRankUpgarde[5][4] = {
    //喻-> 溯橫 溯橫-> 縑а 縑а-> 嶸棲觼 嶸棲觼-> 溯瞪渦葬
        {70,50,20,5},   //�捕�
        {2500,5000,15000,40000},
        {5,7,3,3},//ж晝 鬼�倣З�
        {0,3,7,5},//醞晝
        {0,0,3,7}//堅晝
};
int equipReinForce[25][10] =
{
    /*NORMAL*/
   {90, 85, 80, 75, 70, 65, 60, 55, 50, 0}, //�捕�
   {500, 1000, 1500, 2000, 2500, 3500, 4500, 5500, 6500,0}, //綠辨
   {1, 2, 3, 0, 0, 0, 0, 0, 0,0}, //ж晝 в蹂и 給 偃熱
   {0, 0, 0, 1, 2, 3, 0, 0, 0,0}, //醞晝 в蹂и 給 偃熱
   {0, 0, 0, 0, 0, 0, 1, 2, 3,0}, //堅晝 в蹂и 給 偃熱
   /*RARE*/
   {75, 69, 63, 57, 51, 45, 39, 33, 27, 0},
   {2000, 3000, 4000, 5000, 6500, 8000, 10500, 12000, 13500,0},
   {2, 4, 6, 0, 0, 0, 0, 0, 0,0},
   {0, 0, 0, 2, 4, 6, 0, 0, 0,0},
   {0, 0, 0, 0, 0, 0, 2, 4, 6,0},
   /*EPIC*/
   {57, 50, 43, 36, 36, 36, 30, 25, 20, 0},
   {5000, 6500, 8000, 10500, 12500, 14500, 16500, 18500, 20500,0},
   {3, 6, 9, 0, 0, 0, 0, 0, 0,0},
   {0, 0, 0, 3, 6, 9, 0, 0, 0,0},
   {0, 0, 0, 0, 0, 0, 3, 6, 9,0},
   /*UNIQUE*/
   {36, 30, 20, 17, 17, 17, 14, 12, 10, 0},
   {10500, 12500, 14500, 16500, 19000, 21500, 24000, 27500, 30000,0},
   {4, 7, 10, 3, 3, 3, 3, 3, 3,0},
   {0, 0, 0, 4, 7, 10, 0, 0, 0,0},
   {0, 0, 0, 0, 0, 0, 4, 7, 10,0},
   /*LEGENDARY*/
   {17, 14, 12, 10, 9, 8, 7, 6, 5, 0},
   {16500, 19000, 21500, 24000, 27000, 30000, 33000, 36000, 39000,0},
   {5, 8, 11, 3, 3, 3, 3, 3, 3,0},
   {3, 3,3, 5, 8, 11, 3, 3, 3,0},
   {3, 3, 3, 3, 3, 3, 5, 8, 11,0},
};
void startReinForce()
{
    int flags = 0;
    ReinForce_Select = HAT;
    ReinForce_Select_Before = HAT;
    system("cls");
    DrawLog();
    while (STATE != START_TOWN) {
        DrawBg(Choose_OK, C_BLACK);
        Draw_ReinForce_Select();
        ShowPercent();
        while (1)
        {
            if (Choose_OK == C_WHITE) {
                if (!flags) {
                    OptionClean();
                    ShowPercent();
                    flags = 1;
                }
                if (ReinForceSelectProcessKeyInput()) {
                    flags = 0;
                    break;
                }

            }
            if (Choose_OK == C_GREEN_) {
                if (!flags) {
                    Option();
                    flags = 1;
                }
                if (ReinForceInSelectProcessKeyInput()) {
                    flags = 0;
                    break;
                }
            }
        }
    }
}
void Draw_ReinForce_Select() {
    switch (ReinForce_Select) {
    case HAT:
        DrawHat(C_GREEN_, C_BLACK);
        DrawRobe(C_WHITE, C_BLACK);
        DrawWeapon(C_WHITE, C_BLACK);
        DrawPalZZi(C_WHITE, C_BLACK);
        DrawShoe(C_WHITE, C_BLACK);
        DrawBACK(C_WHITE, C_BLACK);
        break;
    case ROBE:
        DrawHat(C_WHITE, C_BLACK);
        DrawRobe(C_GREEN_, C_BLACK);
        DrawWeapon(C_WHITE, C_BLACK);
        DrawPalZZi(C_WHITE, C_BLACK);
        DrawShoe(C_WHITE, C_BLACK);
        DrawBACK(C_WHITE, C_BLACK);
        break;
    case SHOES:
        DrawHat(C_WHITE, C_BLACK);
        DrawRobe(C_WHITE, C_BLACK);
        DrawWeapon(C_WHITE, C_BLACK);
        DrawPalZZi(C_WHITE, C_BLACK);
        DrawShoe(C_GREEN_, C_BLACK);
        DrawBACK(C_WHITE, C_BLACK);
        break;
    case WEAPON:
        DrawHat(C_WHITE, C_BLACK);
        DrawRobe(C_WHITE, C_BLACK);
        DrawWeapon(C_GREEN_, C_BLACK);
        DrawPalZZi(C_WHITE, C_BLACK);
        DrawShoe(C_WHITE, C_BLACK);
        DrawBACK(C_WHITE, C_BLACK);
        break;
    case BRACELET:
        DrawHat(C_WHITE, C_BLACK);
        DrawRobe(C_WHITE, C_BLACK);
        DrawWeapon(C_WHITE, C_BLACK);
        DrawPalZZi(C_GREEN_, C_BLACK);
        DrawShoe(C_WHITE, C_BLACK);
        DrawBACK(C_WHITE, C_BLACK);
        break;
    case GOOUT:
        DrawHat(C_WHITE, C_BLACK);
        DrawRobe(C_WHITE, C_BLACK);
        DrawWeapon(C_WHITE, C_BLACK);
        DrawPalZZi(C_WHITE, C_BLACK);
        DrawShoe(C_WHITE, C_BLACK);
        DrawBACK(C_GREEN_, C_BLACK);
        break;
    }
}
void Draw_ReinForce_Select_BA(int BEFORE, int AFTER) {
    switch (BEFORE) {
    case HAT:
        DrawHat(C_WHITE, C_BLACK);
        break;
    case ROBE:
        DrawRobe(C_WHITE, C_BLACK);
        break;
    case SHOES:
        DrawShoe(C_WHITE, C_BLACK);
        break;
    case WEAPON:
        DrawWeapon(C_WHITE, C_BLACK);
        break;
    case BRACELET:
        DrawPalZZi(C_WHITE, C_BLACK);
        break;
    case GOOUT:
        DrawBACK(C_WHITE, C_BLACK);
        break;
    }
    switch (AFTER) {
    case HAT:
        DrawHat(C_GREEN_, C_BLACK);
        break;
    case ROBE:
        DrawRobe(C_GREEN_, C_BLACK);
        break;
    case SHOES:
        DrawShoe(C_GREEN_, C_BLACK);
        break;
    case WEAPON:
        DrawWeapon(C_GREEN_, C_BLACK);
        break;
    case BRACELET:
        DrawPalZZi(C_GREEN_, C_BLACK);
        break;
    case GOOUT:
        DrawBACK(C_GREEN_, C_BLACK);
        break;
    }
}
void drawDownCase() {
    switch (ReinForce_Select) {
    case HAT:
        ReinForce_Select_Before = HAT;
        ReinForce_Select = ROBE;
        break;
    case ROBE:
        ReinForce_Select_Before = ROBE;
        ReinForce_Select = WEAPON;
        break;
    case WEAPON:
        ReinForce_Select_Before = WEAPON;
        ReinForce_Select = SHOES;
        break;
    case SHOES:
        ReinForce_Select_Before = SHOES;
        ReinForce_Select = BRACELET;
        break;
    case BRACELET:
        ReinForce_Select_Before = BRACELET;
        ReinForce_Select = GOOUT;
        break;
    case GOOUT:
        ReinForce_Select_Before = GOOUT;
        break;
    }
}
void MoveUpDraw() {
    OptionClean();
    drawUpCase();
    SetUp();
    Draw_ReinForce_Select_BA(ReinForce_Select_Before, ReinForce_Select);
    ReinForce_Before();
    ReinForce_After();
    Print_ReinForce_Item();
    Print_ReinForce_Need();
    Print_ReinForce_Got();
    ShowPercent();
    Calculate_Can_ReinForce();
}
void MoveDownDraw() {
    OptionClean();
    drawDownCase();
    Draw_ReinForce_Select_BA(ReinForce_Select_Before, ReinForce_Select);
    if (ReinForce_Select == GOOUT) {
        CleanBg();
    }
    else {
        SetUp();
        ReinForce_Before();
        ReinForce_After();
        Print_ReinForce_Item();
        Print_ReinForce_Need();
        Print_ReinForce_Got();
        ShowPercent();
        Calculate_Can_ReinForce();
    }
}
void drawUpCase() {
    switch (ReinForce_Select) {
    case HAT:
        ReinForce_Select_Before = HAT;
        break;
    case ROBE:
        ReinForce_Select_Before = ROBE;
        ReinForce_Select = HAT;
        break;
    case WEAPON:
        ReinForce_Select_Before = WEAPON;
        ReinForce_Select = ROBE;
        break;
    case SHOES:
        ReinForce_Select_Before = SHOES;
        ReinForce_Select = WEAPON;
        break;
    case BRACELET:
        ReinForce_Select_Before = BRACELET;
        ReinForce_Select = SHOES;
        break;
    case GOOUT:
        ReinForce_Select_Before = GOOUT;
        ReinForce_Select = BRACELET;
        break;
    }
}
int ReinForceInSelectProcessKeyInput() {
    for (int i = 0; i < 30; i++)
    {
        if (_kbhit())
        {
            int key = _getch();
            switch (key)
            {
            case LEFT:
                OptionLeft();
                break;
            case ENTER:
                if (ReinForce_Select == GOOUT) {
                    STATE = START_TOWN;
                    return 1;
                }
                if (SELECT_SWITCH == 0) {
                    if (!Calculate_Can_ReinForce()) {
                        ReinForceLoading();
                        ReinForce();
                        Choose_OK = C_WHITE;
                        DrawBg(Choose_OK, C_BLACK);
                        ShowPercent();
                        ReinForce_Before();
                        ReinForce_After();
                    }
                    return 1;
                }
                else if (SELECT_SWITCH == 1) {
                    Choose_OK = C_WHITE;
                    DrawBg(Choose_OK, C_BLACK);
                    SELECT_SWITCH = 0;
                    return 1;
                }
                else if (SELECT_SWITCH == 2) {
                    if (!Calculate_Can_ReinForce()) {
                        ReinForceLoading();
                        ReinForce_RANK();
                        Choose_OK = C_WHITE;
                        DrawBg(Choose_OK, C_BLACK);
                        ShowPercent_RANK_UP();
                        ReinForce_Before();
                        ReinForce_After_RANK();
                        SELECT_SWITCH = 0;
                    }
                    return 1;
                }
                break;  // 'k'
            case RIGHT:
                OptionRight();
                break;
            default:                                        break;
            }
        }
        Sleep(1); // 200 = 跨蝶攪 樓紫
    }
    return 0;
}
int ReinForceSelectProcessKeyInput()
{
    for (int i = 0; i < 30; i++)
    {
        if (_kbhit())
        {
            int key = _getch();
            switch (key)
            {
            case UP:
                MoveUpDraw();
                break;
            case ENTER:
                if (ReinForce_Select == GOOUT) {
                    STATE = START_TOWN;
                    return 1;
                }
                if (Choose_OK == C_WHITE) {
                    Choose_OK = C_GREEN_;
                    DrawBg(Choose_OK, C_BLACK);
                    return 1;
                }
                break;  // 'k'
            case DOWN:
                MoveDownDraw();
                break;
                //case SPACE_BAR:     Check_Portal();                     break;  // ん驍 檜翕
            default:                                        break;
            }
        }
        Sleep(1); // 200 = 跨蝶攪 樓紫
    }
    return 0;
}
void ReinForce_Before() {
    for (int x = 48; x < 75; x++) {
        for (int y = 12; y < 15; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(50, 12);
    switch (equipmentRank[ReinForce_Select]) {
    case NORMAL: printf("蛔晝: 喻蜓"); break;
    case RARE: printf("蛔晝: "); setcolor(C_SKYBLUE, C_BLACK); printf("溯橫"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("蛔晝: "); setcolor(C_PURPLE, C_BLACK); printf("縑а"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("蛔晝: "); setcolor(E_ELECT, C_BLACK); printf("嶸棲觼"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("蛔晝: "); setcolor(C_GREEN_, C_BLACK); printf("瞪撲"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(50, 13);
    printf("溯漣: %d", equipmentLevel[ReinForce_Select]);
    gotoxy(48, 14);
    printf("鬼�值膩�: %.lf%%", equipmentEffect[5 * equipmentRank[ReinForce_Select] + ReinForce_Select][equipmentLevel[ReinForce_Select]]);
}
void ReinForce_After_RANK() {
    for (int x = 118; x < 145; x++) {
        for (int y = 12; y < 15; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(120, 12);
    switch (equipmentRank[ReinForce_Select]) {
    case NORMAL: printf("蛔晝: "); setcolor(C_SKYBLUE, C_BLACK); printf("溯橫"); setcolor(C_WHITE, C_BLACK); break;
    case RARE: printf("蛔晝: "); setcolor(C_PURPLE, C_BLACK); printf("縑а"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("蛔晝: "); setcolor(E_ELECT, C_BLACK); printf("嶸棲觼"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("蛔晝: "); setcolor(C_GREEN_, C_BLACK); printf("瞪撲"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("譆渠 蛔晝縑"); gotoxy(120, 13); printf("紫殖ж樟蝗棲棻."); break;
    }
    if (equipmentRank[ReinForce_Select] != LEGENDARY) {
        int tmp = equipmentLevel[ReinForce_Select] - 3;
        if (tmp < 1)tmp = 1;
        gotoxy(120, 13);
        printf("溯漣: %d", tmp);
        gotoxy(118, 14);
        printf("鬼�值膩�: %.lf%%", equipmentEffect[5 * (equipmentRank[ReinForce_Select] + 1) + ReinForce_Select][tmp]);
    }
}
void ReinForce_After() {
    for (int x = 118; x < 145; x++) {
        for (int y = 12; y < 15; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(120, 12);
    switch (equipmentRank[ReinForce_Select]) {
    case NORMAL: printf("蛔晝: 喻蜓"); break;
    case RARE: printf("蛔晝: "); setcolor(C_SKYBLUE, C_BLACK); printf("溯橫"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("蛔晝: "); setcolor(C_PURPLE, C_BLACK); printf("縑а"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("蛔晝: "); setcolor(E_ELECT, C_BLACK); printf("嶸棲觼"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("蛔晝: "); setcolor(C_GREEN_, C_BLACK); printf("瞪撲"); setcolor(C_WHITE, C_BLACK); break;
    }
    if (equipmentLevel[ReinForce_Select] < 10) {
        gotoxy(120, 13);
        printf("溯漣: %d", equipmentLevel[ReinForce_Select] + 1);
        gotoxy(118, 14);
        printf("鬼�值膩�: %.lf%%", equipmentEffect[5 * equipmentRank[ReinForce_Select] + ReinForce_Select][equipmentLevel[ReinForce_Select] + 1]);
    }
    else {
        gotoxy(120, 13);
        printf("譆渠溯漣縑");
        gotoxy(120, 14);
        printf("紫殖ц蝗棲棻.");
    }
}
void Print_ReinForce_Need() {
    for (int x = 69; x < 89; x++) {
        for (int y = 15; y < 21; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(73, 15);
    printf("в蹂 營猿");
    gotoxy(69, 17);
    printf("絲: \t%d", equipReinForce[5 * equipmentRank[ReinForce_Select] + 1][equipmentLevel[ReinForce_Select] - 1]);
    gotoxy(69, 18);
    printf("ж晝 鬼�倣� 給: %d", equipReinForce[5 * equipmentRank[ReinForce_Select] + 2][equipmentLevel[ReinForce_Select] - 1]);
    gotoxy(69, 19);
    printf("醞晝 鬼�倣� 給: %d", equipReinForce[5 * equipmentRank[ReinForce_Select] + 3][equipmentLevel[ReinForce_Select] - 1]);
    gotoxy(69, 20);
    printf("堅晝 鬼�倣� 給: %d", equipReinForce[5 * equipmentRank[ReinForce_Select] + 4][equipmentLevel[ReinForce_Select] - 1]);
}
void Print_ReinForce_Need_RANK() {
    for (int x = 69; x < 89; x++) {
        for (int y = 15; y < 21; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(73, 15);
    printf("в蹂 營猿");
    gotoxy(69, 17);
    printf("絲: \t%d", equipRankUpgarde[1][equipmentRank[ReinForce_Select]]);
    gotoxy(69, 18);
    printf("ж晝 鬼�倣� 給: %d", equipRankUpgarde[2][equipmentRank[ReinForce_Select]]);
    gotoxy(69, 19);
    printf("醞晝 鬼�倣� 給: %d", equipRankUpgarde[3][equipmentRank[ReinForce_Select]]);
    gotoxy(69, 20);
    printf("堅晝 鬼�倣� 給: %d", equipRankUpgarde[4][equipmentRank[ReinForce_Select]]);
}
void Print_ReinForce_Got() {
    for (int x = 89; x < 109; x++) {
        for (int y = 15; y < 21; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(93, 15);
    printf("模嶸 營猿");
    gotoxy(91, 17);
    printf("絲: \t");
    if (equipReinForce[5 * equipmentRank[ReinForce_Select] + 1][equipmentLevel[ReinForce_Select] - 1] > money)setcolor(C_RED_, C_BLACK);
    gotoxy(102, 17);
    printf("%d", money);
    setcolor(C_WHITE, C_BLACK);
    gotoxy(91, 18);
    printf("ж晝 鬼�倣� 給:");
    if (equipReinForce[5 * equipmentRank[ReinForce_Select] + 2][equipmentLevel[ReinForce_Select] - 1] > enhancementStone1)setcolor(C_RED_, C_BLACK);
    gotoxy(107, 18);
    printf("%d", enhancementStone1);
    setcolor(C_WHITE, C_BLACK);
    gotoxy(91, 19);
    printf("醞晝 鬼�倣� 給:");
    if (equipReinForce[5 * equipmentRank[ReinForce_Select] + 3][equipmentLevel[ReinForce_Select] - 1] > enhancementStone2)setcolor(C_RED_, C_BLACK);
    gotoxy(107, 19);
    printf("%d", enhancementStone2);
    setcolor(C_WHITE, C_BLACK);
    gotoxy(91, 20);
    printf("堅晝 鬼�倣� 給:");
    if (equipReinForce[5 * equipmentRank[ReinForce_Select] + 4][equipmentLevel[ReinForce_Select] - 1] > enhancementStone3)setcolor(C_RED_, C_BLACK);
    gotoxy(107, 20);
    printf("%d", enhancementStone3);
    setcolor(C_WHITE, C_BLACK);
}
int Calculate_Can_ReinForce() {
    for (int x = 78; x < 105; x++) {
        for (int y = 22; y < 23; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    int flag = 0;
    if (SELECT_SWITCH == 0) {
        if (equipReinForce[1][equipmentLevel[ReinForce_Select] - 1] > money)flag = 1;
        if (equipReinForce[2][equipmentLevel[ReinForce_Select] - 1] > enhancementStone1)flag = 1;
        if (equipReinForce[3][equipmentLevel[ReinForce_Select] - 1] > enhancementStone2)flag = 1;
        if (equipReinForce[4][equipmentLevel[ReinForce_Select] - 1] > enhancementStone3)flag = 1;
        if (equipmentLevel[ReinForce_Select] >= 10)flag = 1;
        if (!flag) {
            gotoxy(78, 22);
            setcolor(C_GREEN_, C_BLACK);
            printf("溯漣 鬼�降� 陛棟м棲棻.");
            setcolor(C_WHITE, C_BLACK);
        }
        else {
            gotoxy(78, 22);
            setcolor(C_RED_, C_BLACK);
            printf("溯漣 鬼�降� 碳陛棟м棲棻.");
            setcolor(C_WHITE, C_BLACK);
        }
    }
    if (SELECT_SWITCH == 2) {
        for (int x = 78; x < 100; x++) {
            for (int y = 22; y < 23; y++) {
                gotoxy(x, y);
                printf(" ");
            }
        }
        if (equipRankUpgarde[1][equipmentRank[ReinForce_Select]] > money)flag = 1;
        if (equipRankUpgarde[2][equipmentRank[ReinForce_Select]] > enhancementStone1)flag = 1;
        if (equipRankUpgarde[3][equipmentRank[ReinForce_Select]] > enhancementStone2)flag = 1;
        if (equipRankUpgarde[4][equipmentRank[ReinForce_Select]] > enhancementStone3)flag = 1;
        if (equipmentRank[ReinForce_Select] >= LEGENDARY)flag = 1;
        if (!flag) {
            gotoxy(78, 22);
            setcolor(C_GREEN_, C_BLACK);
            printf("蛔晝 鬼�降� 陛棟м棲棻.");
            setcolor(C_WHITE, C_BLACK);
        }
        else {
            gotoxy(78, 22);
            setcolor(C_RED_, C_BLACK);
            printf("蛔晝 鬼�降� 碳陛棟м棲棻.");
            setcolor(C_WHITE, C_BLACK);
        }
    }
    return flag;
}
void OptionClean() {
    for (int x = 50; x < 125; x++) {
        for (int y = 26; y < 29; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
}
void OptionLeft() {
    if (SELECT_SWITCH != 2) {
        Print_ReinForce_Need();
        ReinForce_After();
        ShowPercent();
        SELECT_SWITCH = 0;
        for (int x = 50; x < 120; x++) {
            for (int y = 26; y < 29; y++) {
                gotoxy(x, y);
                printf(" ");
            }
        }
        setcolor(C_GREEN_, C_BLACK);
        gotoxy(50, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(50, 27); printf("早   溯漣 鬼��  早");//1
        gotoxy(50, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_WHITE, C_BLACK);
        gotoxy(80, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(80, 27); printf("早  嬴檜蠱 摹鷗 早");//1
        gotoxy(80, 28); printf("曲收收收收收收收收收收收收收收旭");
        gotoxy(110, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(110, 27); printf("早   蛔晝 鬼��  早");//1
        gotoxy(110, 28); printf("曲收收收收收收收收收收收收收收旭");
    }
    if (SELECT_SWITCH == 2) {
        SELECT_SWITCH = 1;
        for (int x = 50; x < 125; x++) {
            for (int y = 26; y < 29; y++) {
                gotoxy(x, y);
                printf(" ");
            }
        }
        ReinForce_After();
        gotoxy(50, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(50, 27); printf("早   溯漣 鬼��  早");//1
        gotoxy(50, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_GREEN_, C_BLACK);
        gotoxy(80, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(80, 27); printf("早  嬴檜蠱 摹鷗 早");//1
        gotoxy(80, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_WHITE, C_BLACK);
        gotoxy(110, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(110, 27); printf("早   蛔晝 鬼��  早");//1
        gotoxy(110, 28); printf("曲收收收收收收收收收收收收收收旭");
    }
    Calculate_Can_ReinForce();
}
void OptionRight() {
    if (SELECT_SWITCH != 0) {
        SELECT_SWITCH = 2;
        for (int x = 50; x < 120; x++) {
            for (int y = 26; y < 29; y++) {
                gotoxy(x, y);
                printf(" ");
            }
        }
        Print_ReinForce_Need_RANK();
        ReinForce_After_RANK();
        ShowPercent_RANK_UP();
        setcolor(C_WHITE, C_BLACK);
        gotoxy(50, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(50, 27); printf("早   溯漣 鬼��  早");//1
        gotoxy(50, 28); printf("曲收收收收收收收收收收收收收收旭");

        gotoxy(80, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(80, 27); printf("早  嬴檜蠱 摹鷗 早");//1
        gotoxy(80, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_GREEN_, C_BLACK);
        gotoxy(110, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(110, 27); printf("早   蛔晝 鬼��  早");//1
        gotoxy(110, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_WHITE, C_BLACK);
    }
    if (SELECT_SWITCH == 0) {
        SELECT_SWITCH = 1;
        for (int x = 50; x < 125; x++) {
            for (int y = 26; y < 29; y++) {
                gotoxy(x, y);
                printf(" ");
            }
        }
        Print_ReinForce_Need();
        ReinForce_After();
        gotoxy(50, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(50, 27); printf("早   溯漣 鬼��  早");//1
        gotoxy(50, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_GREEN_, C_BLACK);
        gotoxy(80, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(80, 27); printf("早  嬴檜蠱 摹鷗 早");//1
        gotoxy(80, 28); printf("曲收收收收收收收收收收收收收收旭");
        setcolor(C_WHITE, C_BLACK);
        gotoxy(110, 26); printf("旨收收收收收收收收收收收收收收旬");//0
        gotoxy(110, 27); printf("早   蛔晝 鬼��  早");//1
        gotoxy(110, 28); printf("曲收收收收收收收收收收收收收收旭");
    }
    Calculate_Can_ReinForce();
}
void Option() {
    ShowPercent();
    for (int x = 50; x < 125; x++) {
        for (int y = 26; y < 29; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    setcolor(C_WHITE, C_BLACK);
    gotoxy(50, 26); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(50, 27); printf("早   溯漣 鬼��  早");//1
    gotoxy(50, 28); printf("曲收收收收收收收收收收收收收收旭");
    gotoxy(80, 26); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(80, 27); printf("早  嬴檜蠱 摹鷗 早");//1
    gotoxy(80, 28); printf("曲收收收收收收收收收收收收收收旭");
    gotoxy(110, 26); printf("旨收收收收收收收收收收收收收收旬");//0
    gotoxy(110, 27); printf("早   蛔晝 鬼��  早");//1
    gotoxy(110, 28); printf("曲收收收收收收收收收收收收收收旭");
}
void ShowPercent_RANK_UP() {
    setcolor(C_WHITE, C_BLACK);
    for (int x = 40; x < 144; x++) {
        for (int y = 24; y < 26; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    if (equipmentRank[ReinForce_Select] < LEGENDARY) {
        double tmp = equipRankUpgarde[0][equipmentRank[ReinForce_Select]];
        // 羹溘, 葆釭 綠徽
        int ratioMp = (int)tmp / (100.0f / 85.0f);
        // 葆釭 轎溘
        setcolor(C_WHITE, C_BLACK);
        gotoxy(40, 24); printf("�捕�");
        gotoxy(45, 24);
        setcolor(C_WHITE, C_GREEN_);
        for (int i = 0; i < ratioMp; i++)
            printf(" ");
        setcolor(C_WHITE, C_GRAY);
        for (int i = ratioMp; i < 85; i++)
            printf(" ");
        setcolor(C_WHITE, C_BLACK);
        printf("%6d %%", (int)tmp);
    }
}
void ShowPercent() {
    setcolor(C_WHITE, C_BLACK);
    for (int x = 40; x < 144; x++) {
        for (int y = 24; y < 26; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    if (equipmentLevel[ReinForce_Select] < 10) {
        double tmp = equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1];
        // 羹溘, 葆釭 綠徽
        int ratioMp = (int)tmp / (100.0f / 85.0f);
        double SetMps = equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1] * JangGiBAEK[ReinForce_Select] * 0.05 + tmp;
        int RatioJang = (int)SetMps / (100.0f / 85.0f);
        // 葆釭 轎溘
        setcolor(C_WHITE, C_BLACK);
        gotoxy(40, 24); printf("�捕�");
        gotoxy(45, 24);
        setcolor(C_WHITE, C_GREEN_);
        for (int i = 0; i < ratioMp; i++)
            printf(" ");
        setcolor(C_WHITE, C_RED_);
        for (int i = ratioMp; i < RatioJang; i++)
            printf(" ");
        setcolor(C_WHITE, C_GRAY);
        for (int i = RatioJang; i < 85; i++)
            printf(" ");
        setcolor(C_WHITE, C_BLACK);
        if (!JangGiBAEK[ReinForce_Select])
            printf("%6d %%", equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1]);
        else {
            printf("(   %d+", equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1]);
            setcolor(C_RED_, C_BLACK);
            printf("%.1lf%%", JangGiBAEK[ReinForce_Select] * 0.05 * equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1]);
            setcolor(C_WHITE, C_BLACK);
            printf(")");
        }
    }
}
void Print_ReinForce_Item() {
    for (int x = 75; x < 100; x++) {
        for (int y = 9; y < 11; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(86, 9);
    switch (ReinForce_Select) {
    case HAT:
        printf("賅濠");
        gotoxy(80, 10);
        printf("�膩�: 羹溘 %% 隸陛");
        break;
    case ROBE:
        printf("煎粽");
        gotoxy(79, 10);
        printf("�膩�: 寞橫溘 %% 隸陛");
        break;
    case WEAPON:
        printf("鼠晦");
        gotoxy(79, 10);
        printf("�膩�: 奢問溘 %% 隸陛");
        break;
    case SHOES:
        printf("褐嫦");
        gotoxy(78, 10);
        printf("�膩�: 檜翕樓紫 %% 隸陛");
        break;
    case BRACELET:
        printf("つ鎬");
        gotoxy(80, 10);
        printf("�膩�: 葆釭 %% 隸陛");
        break;
    }
}
void CleanBg() {
    for (int x = 31; x < 140; x++) {
        for (int y = 6; y < 30; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
}
void SetUp() {
    gotoxy(75, 7);
    printf("****** 摹鷗и 嬴檜蠱 ******");
    Print_ReinForce_Item();
    gotoxy(50, 11);
    printf("鬼�� 瞪");
    gotoxy(120, 11);
    printf("鬼�� ��");
}
void DrawBg(int color, int bgcolor)
{
    setcolor(color, bgcolor);
    gotoxy(30, 5); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");//0
    gotoxy(30, 6); printf("早                                                                                                                   早");//1
    gotoxy(30, 7); printf("早                                                                                                                   早");//1
    gotoxy(30, 8); printf("早                                                                                                                   早");//1
    gotoxy(30, 9); printf("早                                                                                                                   早");//1
    gotoxy(30, 10); printf("早                                                                                                                   早");//1
    gotoxy(30, 11); printf("早                                                                                                                   早");//1
    gotoxy(30, 12); printf("早                                                                                                                   早");//1
    gotoxy(30, 13); printf("早                                                                                                                   早");//1
    gotoxy(30, 14); printf("早                                                                                                                   早");//1
    gotoxy(30, 15); printf("早                                                                                                                   早");//1
    gotoxy(30, 16); printf("早                                                                                                                   早");//1
    gotoxy(30, 17); printf("早                                                                                                                   早");//1
    gotoxy(30, 18); printf("早                                                                                                                   早");//1
    gotoxy(30, 19); printf("早                                                                                                                   早");//1
    gotoxy(30, 20); printf("早                                                                                                                   早");//1
    gotoxy(30, 21); printf("早                                                                                                                   早");//1
    gotoxy(30, 22); printf("早                                                                                                                   早");//1
    gotoxy(30, 23); printf("早                                                                                                                   早");//1
    gotoxy(30, 24); printf("早                                                                                                                   早");//1
    gotoxy(30, 25); printf("早                                                                                                                   早");//1
    gotoxy(30, 26); printf("早                                                                                                                   早");//1
    gotoxy(30, 27); printf("早                                                                                                                   早");//1
    gotoxy(30, 28); printf("早                                                                                                                   早");//1
    gotoxy(30, 29); printf("早                                                                                                                   早");//1
    gotoxy(30, 30); printf("早                                                                                                                   早");//1
    gotoxy(30, 31); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
    if (ReinForce_Select != GOOUT) {
        SetUp();
        Print_ReinForce_Item();
        ReinForce_Before();
        ReinForce_After();
        Print_ReinForce_Need();
        Print_ReinForce_Got();
    }
}

void DrawLog()
{
    gotoxy(30, 33); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");//0
    gotoxy(30, 34); printf("早                                                                                                                   早");//1
    gotoxy(30, 35); printf("早                                                                                                                   早");//1
    gotoxy(30, 36); printf("早                                                                                                                   早");//1
    gotoxy(30, 37); printf("早                                                                                                                   早");//1
    gotoxy(30, 38); printf("早                                                                                                                   早");//1
    gotoxy(30, 39); printf("早                                                                                                                   早");//1
    gotoxy(30, 40); printf("早                                                                                                                   早");//1
    gotoxy(30, 41); printf("早                                                                                                                   早");//1
    gotoxy(30, 42); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void ReinForce_RANK() {
    for (int x = 40; x < 139; x++) {
        for (int y = 38; y < 39; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    if (equipmentRank[ReinForce_Select] < LEGENDARY) {
        int random_var = rand() % 100 + 1;
        if (random_var < equipRankUpgarde[0][equipmentRank[ReinForce_Select]]) {
            gotoxy(60, 38);
            setcolor(C_GREEN_, C_BLACK);
            printf("鬼�倍� 撩奢ж樟蝗棲棻!");
            setcolor(C_WHITE, C_BLACK);
            money -= equipRankUpgarde[1][equipmentRank[ReinForce_Select]];
            enhancementStone1 -= equipRankUpgarde[2][equipmentRank[ReinForce_Select]];
            enhancementStone2 -= equipRankUpgarde[3][equipmentRank[ReinForce_Select]];
            enhancementStone3 -= equipRankUpgarde[4][equipmentRank[ReinForce_Select]];
            equipmentRank[ReinForce_Select]++;
            equipmentLevel[ReinForce_Select] -= 3;
            if (equipmentLevel[ReinForce_Select] < 1)equipmentLevel[ReinForce_Select] = 1;
        }
        else {
            gotoxy(60, 38);
            setcolor(C_RED_, C_BLACK);
            printf("鬼�倍� 褒ぬц蝗棲棻!");
            setcolor(C_WHITE, C_BLACK);
            money -= equipRankUpgarde[1][equipmentRank[ReinForce_Select]];
            enhancementStone1 -= equipRankUpgarde[2][equipmentRank[ReinForce_Select]];
            enhancementStone2 -= equipRankUpgarde[3][equipmentRank[ReinForce_Select]];
            enhancementStone3 -= equipRankUpgarde[4][equipmentRank[ReinForce_Select]];
        }
    }
}
void ReinForce() {
    for (int x = 40; x < 139; x++) {
        for (int y = 38; y < 39; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    int random_var = rand() % 100 + 1;
    if (random_var < (double)equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1] * (double)JangGiBAEK[ReinForce_Select] * 0.05 + (double)equipReinForce[5 * equipmentRank[ReinForce_Select]][equipmentLevel[ReinForce_Select] - 1]) {
        gotoxy(60, 38);
        setcolor(C_GREEN_, C_BLACK);
        printf("鬼�倍� 撩奢ж樟蝗棲棻!");
        setcolor(C_WHITE, C_BLACK);
        money -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 1][equipmentLevel[ReinForce_Select] - 1];
        enhancementStone1 -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 2][equipmentLevel[ReinForce_Select] - 1];
        enhancementStone2 -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 3][equipmentLevel[ReinForce_Select] - 1];
        enhancementStone3 -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 4][equipmentLevel[ReinForce_Select] - 1];
        equipmentLevel[ReinForce_Select]++;
        JangGiBAEK[ReinForce_Select] = 0;
    }
    else {
        gotoxy(60, 38);
        setcolor(C_RED_, C_BLACK);
        printf("鬼�倍� 褒ぬц蝗棲棻!");
        setcolor(C_WHITE, C_BLACK);
        money -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 1][equipmentLevel[ReinForce_Select] - 1];
        enhancementStone1 -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 2][equipmentLevel[ReinForce_Select] - 1];
        enhancementStone2 -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 3][equipmentLevel[ReinForce_Select] - 1];
        enhancementStone3 -= equipReinForce[5 * equipmentRank[ReinForce_Select] + 4][equipmentLevel[ReinForce_Select] - 1];
        JangGiBAEK[ReinForce_Select]++;
    }
}
void ReinForceLoading() {
    setcolor(C_WHITE, C_BLACK);
    for (int x = 40; x < 145; x++) {
        for (int y = 38; y < 39; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
    int Sleep_time = 100;
    int tmp = 0;
    while (1) {
        // 羹溘, 葆釭 綠徽
        int ratioMp = (int)tmp / (100.0f / 90.0f);
        // 葆釭 轎溘
        setcolor(C_WHITE, C_BLACK);
        gotoxy(80, 36); printf("鬼�� 霞ч");
        gotoxy(40, 38);
        setcolor(C_WHITE, C_BLUE_);
        for (int i = 0; i < ratioMp; i++)
            printf(" ");
        setcolor(C_WHITE, C_GRAY);
        for (int i = ratioMp; i < 89; i++)
            printf(" ");
        setcolor(C_WHITE, C_BLACK);
        printf("%6d %%", tmp);
        Sleep(130 / Sleep_time);
        if (tmp == 100)break;
        tmp++;
    }
}
//賅濠 褐嫦 鼠晦 煎粽 つ鎬
void DrawHat(int color, int bgcolor) {
    setcolor(color, bgcolor);
    gotoxy(10, 5); printf("旨收收收收收收收收收旬");//0
    gotoxy(10, 6); printf("早   賅濠  早");//1
    gotoxy(10, 7); printf("曲收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawRobe(int color, int bgcolor) {
    setcolor(color, bgcolor);
    gotoxy(10, 11); printf("旨收收收收收收收收收旬");//0
    gotoxy(10, 12); printf("早   煎粽  早");//1
    gotoxy(10, 13); printf("曲收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawWeapon(int color, int bgcolor) {
    setcolor(color, bgcolor);
    gotoxy(10, 17); printf("旨收收收收收收收收收旬");//0
    gotoxy(10, 18); printf("早   鼠晦  早");//1
    gotoxy(10, 19); printf("曲收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawShoe(int color, int bgcolor) {
    setcolor(color, bgcolor);
    gotoxy(10, 23); printf("旨收收收收收收收收收旬");//0
    gotoxy(10, 24); printf("早   褐嫦  早");//1
    gotoxy(10, 25); printf("曲收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawPalZZi(int color, int bgcolor) {
    setcolor(color, bgcolor);
    gotoxy(10, 29); printf("旨收收收收收收收收收旬");//0
    gotoxy(10, 30); printf("早   つ鎬  早");//1
    gotoxy(10, 31); printf("曲收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}
void DrawBACK(int color, int bgcolor) {
    setcolor(color, bgcolor);
    gotoxy(10, 35); printf("旨收收收收收收收收收旬");//0
    gotoxy(10, 36); printf("早  釭陛晦 早");//1
    gotoxy(10, 37); printf("曲收收收收收收收收收旭");
    setcolor(C_WHITE, C_BLACK);
}