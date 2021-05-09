#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
int const level_MAX = 10;
int const hp_maximun = 999;
int event_counter = 0;
int antidote = 0;

int checksmith(int hp) {
    int yes = 0;
    int a[49] = { 4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985 };
    for (int j = 0; j < 49; j++)
        if (a[j] == hp) { yes = 1; break; }
    if (yes) return 1;
    else return 0;

}
void hp_increase_with_1_lv(int& hp_MAX) {
    hp_MAX = hp_MAX + 100;
    if (hp_MAX > hp_maximun) hp_MAX = hp_maximun;
}

void using_gil_to_revived(int& hp, int& gil, int hp_MAX, int& case_6, int& mushroom, int& DevilWings, int& fakeArmor) {
    case_6 = 0;
    mushroom = 0;
    fakeArmor = 0;
    DevilWings = 0;
    knight woundedKnight;
    woundedKnight.HP = hp;
    woundedKnight.gil = gil;
    callPhoenix(woundedKnight, hp_MAX);
    hp = woundedKnight.HP;
    gil = woundedKnight.gil;

}
bool checkfibonacci(int hp)
{
    int a = 0;
    int b = 1;
    if (hp == a || hp == b) return true;
    int c = a + b;
    while (c < hp)
    {
        if (c == hp) return true;
        a = b;
        b = c;
        c = a + b;
    }
    return false;
}
void poisoned_case(int& case_6, int& antidote, int& mushroom, int& DevilWings, int& fakeArmor) {
    if (case_6 > 0 && case_6 < 7) { case_6++; }
    if (case_6 > 6) case_6 = 0;
    if (mushroom > 0 && mushroom < 7) { mushroom++; }
    if (mushroom > 6) mushroom = 0;
    if (fakeArmor > 0 && fakeArmor < 8) { fakeArmor++; }
    if (fakeArmor > 7) { fakeArmor = 0; }
    if (antidote > 0 && (case_6 > 0 || mushroom > 0 || DevilWings > 0)) {
        antidote = antidote - 1;
        case_6 = 0;
        mushroom = 0;
        DevilWings = 0;
        fakeArmor = 0;
    }
}
void Durian_counter(int& case_9) {
    if (case_9 > 0 && case_9 < 4) case_9++;
    if (case_9 > 3) case_9 = 0;
}
void Odin_counter(int& case_11, int& fakeOdin) {
    if (case_11 > 0 && case_11 < 7) case_11++;
    if (case_11 < 10 && case_11 > 6) case_11 = 0;
    if (fakeOdin > 0 && fakeOdin < 7) fakeOdin++;
    if (fakeOdin < 10 && fakeOdin > 6) fakeOdin = 0;
}
void meetFakeOdinCount(int& fakeOdin, int& meetFakeOdin) {
    if (fakeOdin == 5)
        meetFakeOdin += 1;
    //else if()
}
void Nina_counter(int& case_8) {
    if (case_8 > 0 && case_8 < 7) case_8++;
    if (case_8 > 6) case_8 = 0;
}

void Lionheart_vounter(int& Lionheart, int case_8, int Paladin) {
    if (Lionheart == 1 && Paladin == 1) {
        Lionheart = 1;
    }
    else if (Lionheart == 1 && (case_8 > 0 && case_8 < 6)) {
        Lionheart = 1;
    }
    else Lionheart = 0;
}

int Eternal_Love(int case_95, int case_96, int case_97, int Arthur, int Lancelot, int Guinevere) {
    if (case_96 == 1 && case_97 == 1) return 1;
    else if (Arthur == 1 && case_97 == 1) return 1;
    else if (Lancelot == 1 && case_97 == 1) return 1;
    else if (Guinevere == 1 && case_96 == 1) return 1;
    else return 0;

}
void Mode(int mode, int& H95, int& H96, int& H97) {
    if (mode == 1) {
        H95 = hash(95);
        H96 = hash(96);
        H97 = hash(97);
        if ((H95 > H96) && (H95 > H97) && (H96 > H97))
        {
            H95 = 3;
            H96 = 2;
            H97 = 1;
        }
        else if ((H95 > H96) && (H95 > H97) && (H97 > H96))
        {
            H95 = 3;
            H96 = 1;
            H97 = 2;
        }
        else if ((H96 > H95) && (H96 > H97) && (H95 > H97))
        {
            H95 = 2;
            H96 = 3;
            H97 = 1;
        }
        else if ((H96 > H95) && (H96 > H97) && (H97 > H95))
        {
            H95 = 1;
            H96 = 3;
            H97 = 2;
        }
        else if ((H97 > H96) && (H97 > H95) && (H96 > H95))
        {
            H95 = 1;
            H96 = 2;
            H97 = 3;
        }
        else if ((H97 > H96) && (H95 > H95) && (H95 > H96))
        {
            H95 = 2;
            H96 = 1;
            H97 = 3;
        }
    }
}
int prime_number(int& n) {
    int i, flag = 0;

    for (i = 2; i <= n / 2; ++i) {
        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (n == 1) {
        return 0;
    }
    if (flag == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int DragonKnightCheck(int initialHP) {
    float x = 1, y = 1, z = 1;
    while (x < initialHP + 1) {
        y = 1;
        while (y < initialHP + 1 - x) {
            z = initialHP - y - x;
            if ((z * z) == (x * x + y * y)) {
                return 1;
            }
            y++;
        }
        x++;
    }
    return 0;
}

float sumOfDivisor(int num)
{
    int sum = num;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum;
};

bool Friendly_number(int knightHP, int knightGil)
{
    if (sumOfDivisor(knightHP) / knightHP == sumOfDivisor(knightGil) / knightGil)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int ArthurTie(int case_98, int Arthur, int& hp, int& gil, int win_counter)
{
    if (Arthur == 1 && case_98 < 1) {
        hp = hp;
        gil = gil;
        return 0;
    }
    else if (Arthur == 1 && case_98 == 1) {
        return 1;
    }
    //else {
    //    return 0;
    //}
}
int SumOfSquNum(int givno)
{
    int SumOfSqr = 0;
    while (givno)
    {
        SumOfSqr += (givno % 10) * (givno % 10);
        givno /= 10;
    }
    return SumOfSqr;
}
bool isLucky(int n)
{
    // Create an array of size 10 and initialize all 
    // elements as false. This array is used to check 
    // if a digit is already seen or not. 
    bool arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = false;

    // Traverse through all digits of given number 
    while (n > 0)
    {
        // Find the last digit 
        int digit = n % 10;

        // If digit is already seen, return false 
        if (arr[digit])
            return false;

        // Mark this digit as seen 
        arr[digit] = true;

        // REmove the last digit from number 
        n = n / 10;
    }
    return true;
}
void case_1(int& fight, int hp_MAX, int& hp, int& gil, int level, int gil_earned, float baseDamage, int i, int case_98, int  case_6, int case_11, int case_14, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int& Princess_case, int Paladin, int fakeOdin, int fakeArmor, int mushroom) {
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (case_6 > 0 || mushroom > 0) {
        float damage = baseDamage * levelO * 10;
        hp = hp - damage;
    }
    if ((level >= levelO || Lionheart != 0 || Lancelot == 1 || Paladin == 1 || 0 < case_11 && case_11 < 7 || Tie == 1) && (fakeOdin <= 0 || fakeOdin > 6)) {
        gil = gil + gil_earned;
        if (gil > 999) gil = 999;
        win_counter++;
    }
    //else if (case_14 == 1 && level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Princess_case < 1) {
    //    lose_counter++;
    //}
    else if (0 < fakeArmor && fakeArmor < 8 || 0 < fakeOdin && fakeOdin <= 6 || level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Princess_case < 1) 
    {
        float damage = baseDamage * levelO * 10;
        if (case_14 == 0) {
            hp = hp - damage;
            //if (case_6 > 0) hp = hp + damage;
            lose_counter++;
        }
        else
            lose_counter++;
    }
}
void case_2(int mushroom, int& fight, int hp_MAX, int& hp, int& gil, int level, int gil_earned, float baseDamage, int i, int case_98, int  case_6, int case_11, int case_14, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int& Princess_case, int Paladin, int fakeOdin, int fakeArmor ) {
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (case_6 > 0 || mushroom > 0) {
        float damage = baseDamage * levelO * 10;
        hp = hp - damage;
    }
    if ((level >= levelO || Lionheart != 0 || Lancelot == 1 || Paladin == 1 || 0 < case_11 && case_11 < 7 || Tie == 1) && (fakeOdin <= 0 || fakeOdin > 6)) {
        gil = gil + gil_earned;
        if (gil > 999) gil = 999;
        win_counter++;
    }
    else if (0 < fakeArmor && fakeArmor < 8 || 0 < fakeOdin && fakeOdin <= 6 || level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Princess_case < 1)
    {
        float damage = baseDamage * levelO * 10;
        if (case_14 == 0) {
            hp = hp - damage;
            //if (case_6 > 0) hp = hp + damage;
            lose_counter++;
        }
        else
            lose_counter++;
    }
    if (Princess_case == 1 && level < levelO) {
        float damage = baseDamage * levelO * 10;
        hp = hp - hp / 4;
        if (case_6 > 0) hp = hp + damage;
        lose_counter++;
    }

}
void case_3(int mushroom, int& fight, int hp_MAX, int& hp, int& gil, int level, int gil_earned, float baseDamage, int i, int case_98, int  case_6, int case_11, int case_14, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int& Princess_case, int Paladin, int fakeOdin, int fakeArmor, int& antidote)
{
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (case_6 > 0 || mushroom > 0) {
        float damage = baseDamage * levelO * 10;
        hp = hp - damage;
    }
    if ((level >= levelO || Lionheart != 0 || Lancelot == 1 || Paladin == 1 || 0 < case_11 && case_11 < 7 || Tie == 1) && (fakeOdin <= 0 || fakeOdin > 6)) {
        gil = gil + gil_earned;
        if (gil > 999) gil = 999;
        win_counter++;
        antidote++;
    }
    else if (0 < fakeArmor && fakeArmor < 8 || 0 < fakeOdin && fakeOdin <= 6 || level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Princess_case < 1)
    {
        float damage = baseDamage * levelO * 10;
        if (case_14 == 0) {
            hp = hp - damage;
            //if (case_6 > 0) hp = hp + damage;
            lose_counter++;
        }
        else
            lose_counter++;
    }
}
void case_4(int mushroom, int& fight, int hp_MAX, int& hp, int& gil, int level, int gil_earned, float baseDamage, int i, int case_98, int  case_6, int case_11, int case_14, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int& Princess_case, int Paladin, int fakeOdin, int fakeArmor) {
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (case_6 > 0 || mushroom > 0) {
        float damage = baseDamage * levelO * 10;
        hp = hp - damage;
    }
    if ((level >= levelO || Lionheart != 0 || Lancelot == 1 || Paladin == 1 || 0 < case_11 && case_11 < 7 || Tie == 1) && (fakeOdin <= 0 || fakeOdin > 6)) {
        gil = gil + gil_earned;
        if (gil > 999) gil = 999;
        win_counter++;
    }
    else if (0 < fakeArmor && fakeArmor < 8 || 0 < fakeOdin && fakeOdin <= 6 || level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Princess_case < 1)
    {
        float damage = baseDamage * levelO * 10;
        if (case_14 == 0) {
            hp = hp - damage;
            //if (case_6 > 0) hp = hp + damage;
            lose_counter++;
        }
        else
            lose_counter++;
    }
}
void case_5(int mushroom, int& fight, int hp_MAX, int& hp, int& gil, int level, int gil_earned, float baseDamage, int i, int case_98, int  case_6, int case_11, int case_14, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int& Princess_case, int Paladin, int fakeOdin, int fakeArmor, int& DevilWings) {
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (case_6 > 0 || mushroom > 0) {
        float damage = baseDamage * levelO * 10;
        hp = hp - damage;
    }
    if ((level >= levelO || Lionheart != 0 || Lancelot == 1 || Paladin == 1 || Tie == 1) && (fakeOdin <= 0 || fakeOdin > 6)) {
        gil = gil + gil_earned;
        if (gil > 999) gil = 999;
        win_counter++;
        DevilWings = 5;
    }
    else if (0 < case_11 && case_11 < 7) {
        gil = gil + gil_earned;
        if (gil > 999) gil = 999;
        win_counter++;
    }
    else if (0 < fakeArmor && fakeArmor < 8 || 0 < fakeOdin && fakeOdin < 7 || level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Princess_case < 1)
    {
        float damage = baseDamage * levelO * 10;
        if (case_14 == 0) {
            hp = hp - damage;
            //if (case_6 > 0) hp = hp + damage;
            lose_counter++;
        }
        else
            lose_counter++;
    }
}
int case_6_Tornbery(int& fight, int& hp, int& level, int& gil, int i, int case_98, int case_6, int case_11, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int Paladin, int Dragon_Knight, int fakeOdin, int fakeArmor)
{
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (case_6 > 0) {
        return case_6;
    }
    else if (level >= levelO || (case_11 > 0 && case_11 < 6) || Tie == 1 || Lionheart == 1 && Dragon_Knight < 1 && Paladin < 0) {
        level++;
        if (level > level_MAX) level = 10;
        win_counter++;
        return 0;
    }
    else if ((Dragon_Knight == 1 || Paladin == 1) && level < levelO && Lionheart < 1 && (case_11 > 6 && case_11 < 0)) {
        lose_counter++;
        return 0;
    }
    else if ((0 < fakeArmor && fakeArmor < 8) || (0 < fakeOdin && fakeOdin < 7) || (level < levelO && Arthur < 1 && Lancelot < 1 && Paladin < 1 && Lionheart < 1 && Dragon_Knight < 1)) {
        //float damage = baseDamage * levelO * 10;
        //hp = hp - damage;
        lose_counter++;
        return 1;  // poisoned
    }
}
void case_7_Queen(int& fight, int hp, int level, int& gil, int i, int case_11, int case_15, int case_98, int Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int Guinevere, int& fakeArmor, int& case_14) {
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;
    bool checkfibo = checkfibonacci(hp);
    int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    if (Tie == 0) {
        hp = hp;
        gil = gil;
    }
    if (checkfibo || (case_11 > 0 && case_11 < 6) || Lionheart == 1 || Tie == 1)
    {
        if (case_14 == 1) {
            fakeArmor = 0;
            gil = gil * 2;
            if (gil > 999) gil = 999;
            win_counter++;
        }
        else
        {
            gil = gil * 2;
            if (gil > 999) gil = 999;
            win_counter++;
            fakeArmor = 1;
        }

    }
    else if ((!checkfibo || (case_11 < 0 && case_11 > 6) || Arthur < 1 || Lionheart < 1) && Guinevere < 1 && case_15 < 1) {
        if (case_14 == 1) {
            hp = hp / 2;
            gil = gil / 2;
            case_14 = 0;
            lose_counter++;
        }
        else
        {
            hp = hp / 2;
            gil = gil / 2;
            lose_counter++;
        }
    }
    else if ((!checkfibo || (case_11 < 0 && case_11 > 6) || Arthur < 1 || Lionheart < 1) && (Guinevere == 1 || case_15 == 1)) {
        if (Guinevere == 1) {
            gil = gil / 2;
            lose_counter++;
        }
        else if (case_15 == 1)
        {
            gil = gil + 50;
            lose_counter++;
        }
    }
}
int case_8_Nina_de_Rings(int& fight, int hp_MAX, int& hp, int level, int& gil, int i, int& case_6, int& case_8, int case_11, int case_15, int case_98, int& Lionheart, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int Guinevere, int Paladin, int& fakeArmor, int& case_14) {
    //fight = 0;
    bool happy = isLucky(hp);
    bool friendly = Friendly_number(hp, gil);
    if (happy && Guinevere < 1)
    {
        if (gil >= 50 && !friendly)
        {
            gil = gil - 50;
            fakeArmor = 0;
            case_6 = 0;
            hp = hp + (gil - 50);
            if (gil >= hp_MAX - hp) {
                hp = hp_MAX;
                gil = gil - (hp_MAX - hp);
                return 1;
            }
            else {
                hp = hp + gil;
                gil = 0;
                return 1;
            }
        }
        else if (friendly) {
            hp = hp_MAX;
            fakeArmor = 0;
            case_6 = 0;
            Lionheart = 1;
            return 1;
        }

    }
    //else if (friendly) {
    //    Lionheart = 1;
    //    return 1;
    //}
    else if (Guinevere == 1) {
        gil = gil + 50;
        if (gil > 999) gil = 999;
        return 1;
    }
    else return case_8;
}
int case_9_Durian_Garden(int& fight, int hp_MAX, int& hp, int& nPetal, int& case_6, int case_15,int& case_11, int& mushroom, int& ignore)
{
    //fight = 0;
    if (ignore == 0) {
        if (case_15 == 0) {
            hp = hp_MAX;
            nPetal = nPetal + 20;
            if (nPetal > 99) nPetal = 99;
            case_6 = 0;
            mushroom = 0;
            return 1;
        }
        else
        {
            ignore = 1;
            return 1;
        }

        if (case_11 != 0) {
            case_11 = 0;
        }
    }

}
void case_10_mushroom(int& fight, int& hp, int& gil, int hp_MAX, int case_11, int case_6, int case_14, int antidote, int Paladin, int mushroom, int& DevilWings, int& fakeArmor)
{
    //fight = 0;
    if (case_11 == 0 ) {
        if (case_6 > 0) {
            hp = 0;
            //using_gil_to_revived(hp, gil, hp_MAX, case_6, mushroom, DevilWings, fakeArmor);
        }
        else
            mushroom = 1;
    }
    else
        mushroom = 0;
}
int case_11_Odin(int& fight, int case_9, int& case_11, int& meetFakeOdin, int& fakeOdin)
{
    //fight = 0;

    if (meetFakeOdin > 0 && meetFakeOdin < 4) {
        if (fakeOdin == 0) {
            //meetFakeOdin++;
            fakeOdin = 1;
            return 0;
        }
    }
    else if (meetFakeOdin > 3) {
        fakeOdin = 0;
        return 0;
    }

    else
    {
        if (case_11 == 0 && meetFakeOdin == 0) {
            return 1;
        }
        if (case_11 > 0 && meetFakeOdin == 0) {
            return case_11;
        }
    }
    if (0 < case_9 && case_9 < 4) {
        //if (case_11 > 3) {
        return 0;
    }
    else
    {
        return 1;
    }
}
void case_12_Merlin(int& fight, int& case_6, int& hp_MAX, int& hp, int& fakeArmor, int& GoldCoin) {
    fight = 1;
    case_6 = 0;
    fakeArmor = 0;
    hp = hp_MAX;
    GoldCoin += 1;

}
int case_13_Omega_Weapon(int& fight, int& hp_MAX, int hp, int level, int case_98, int& gil, int case_13, int case_14, int& win_counter, int& lose_counter, int Dragon_Knight, int Lionheart) {
    fight = 1;
    if (case_13 == 1) {
        return 1;
    }
    else if ((case_98 == 1 && level == 10) || (Dragon_Knight == 1 && Lionheart == 1)) {
        gil = 999;
        hp_MAX = hp_MAX + 100 * (10 - level);
        if (hp_MAX > hp_maximun) hp_MAX = hp_maximun;
        level = 10;
        win_counter++;
        return 1;
    }
    else if ((case_98 == 0 || level < 10) && case_14 == 1) {
        lose_counter++;
        return 0;
    }
    else {
        hp = 0;
        lose_counter++;
        return 0;
    }
}
int case_14_Hades(int& fight, int fakeOdin, int fakeArmor, int& meetFakeOdin, int& GoldCoin, int& hp, int& gil, int& level, int i, int& case_11, int& case_14, int case_15, int case_95, int case_96, int case_97,int case_98, int Lionheart, int Eternal_Love_int, int prime, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int Guinevere, int Dragon_Knight, int Paladin) {
    fight = 1;
    float b = i % 10;
    float levelO = i > 6 ? (b > 5 ? b : 5) : b;    
    //int Tie = ArthurTie(case_98, Arthur, hp, gil, win_counter);
    //if (Tie == 0) {
    //    hp = hp;
    //    gil = gil;
    //}
    if (case_11 != 0) {
        case_11 = 0;
        meetFakeOdin = 1;
        //hp = 0;
    }
    if (fakeArmor == 0)
    {
        if ((level >= levelO || Lionheart != 0 || case_15 != 0 || Eternal_Love_int != 0 && prime != 0 || Arthur == 1 && case_11 != 0 || Dragon_Knight == 1 && case_11 != 0) && fakeOdin == 0) {
            if (case_15 != 0) {
                case_15 -= 1;
                win_counter++;
                gil = 0;
                return 1;
            }
            else
            {
                win_counter++;
                gil = 0;
                return 1;
            }

        }
        else 
        {
            if (GoldCoin != 0 || Paladin == 1 || case_14 != 0)
            {
                
                if (GoldCoin != 0) {
                    GoldCoin -= 1;
                    lose_counter++;
                    return 0;
                }
                
                if (Paladin == 1) {
                    lose_counter++;
                    return 0;
                }
                if (case_14 == 1) {
                    lose_counter++;
                    return 1;
                }
               
            }
            else
                hp = 0;
        }
        
    }
   
    else
    {
        if (( Lionheart != 0 || case_15 != 0 || Eternal_Love_int != 0 && prime != 0 || Arthur == 1 && case_11 != 0 || Dragon_Knight == 1 && case_11 != 0) && fakeOdin == 0)
        {
            if (Lionheart != 0) {
                win_counter++;
                gil = 0;
                return 0;
            }
            else if (case_15 == 1)
            {
                case_15 = 0;
                win_counter++;
                gil = 0;
                return 0;
            }
            else
            {
                win_counter++;
                gil = 0;
                return 0;
            }

        }
        else
        {
            if (GoldCoin != 0 || Paladin == 1 || case_14 != 0)
            {

                if (GoldCoin != 0) {
                    GoldCoin -= 1;
                    lose_counter++;
                    return 0;
                }

                if (Paladin == 1) {
                    lose_counter++;
                    return 0;
                }
                if (case_14 == 1) {
                    lose_counter++;
                    return 1;
                }
            }
            else
                hp = 0;
        }
    }
    //if (Paladin == 1)
    //{
    //    if (level < levelO && Lionheart == 0 && case_15 == 0 && (Eternal_Love_int == 0 && prime == 0) && (Arthur < 1 && (case_11 < 0 && case_11 > 6)) && (Dragon_Knight < 1 && (case_11 < 0 && case_11 > 6))) {
    //        return 0;
    //    }
    //    else
    //        case_15 = 0;
    //    win_counter++;
    //    gil = 0;
    //    return 1;
    //}

}
int case_15_SH(int& fight, int& case_15)
{
    //fight = 0;
    if (case_15 == 0) return 1;
    else
        return case_15;
}
int case_16(int& fight, int i, int level, int nEvent, int Lancelot, int Dragon_Knight)
{
    //fight = 0;
    int b = i % 10;
    if (level > b || Dragon_Knight == 1 || Lancelot == 1)
    {
        return 1;
    }
    else
        return 2;
}
int case_17_RevDoor(int& case_17, int NotYetCase_17) {
    //RevDoor = 1;
    //fight = 0;
    if(case_17 == 0 && NotYetCase_17 == 0) return 1;
    else return 0;
}
int case_95_shield(int& fight, int H95, int H96, int H97, int case_95, int case_96, int case_97) {
    //fight = 0;
    if ((H95 == 1) || (H95 == 0)) return 1;
    else if ((H95 == 2) && (H96 == 1)) { if (case_96) return 1; }
    else if ((H95 == 2) && (H97 == 1)) { if (case_97) return 1; }
    else if ((H95 == 3) && (H96 == 2)) { if (case_96) return 1; }
    else if ((H95 == 3) && (H97 == 2)) { if (case_97) return 1; }
    //return 1;
}
int case_96_spear(int& fight, int H95, int H96, int H97, int case_95, int case_96, int case_97) {
    //fight = 0;
    if ((H96 == 1) || (H96 == 0)) return 1;
    else if ((H96 == 2) && (H95 == 1)) { if (case_97) return 1; }
    else if ((H96 == 2) && (H97 == 1)) { if (case_95) return 1; }
    else if ((H96 == 3) && (H95 == 2)) { if (case_97) return 1; }
    else if ((H96 == 3) && (H97 == 2)) { if (case_95) return 1; }
    //return 1;
}
int case_97_hair(int& fight, int H95, int H96, int H97, int case_95, int case_96, int case_97) {
    //fight = 0;
    if ((H97 == 1) || (H97 == 0)) return 1;
    else if ((H97 == 2) && (H96 == 1)) { if (case_96) return 1; }
    else if ((H97 == 2) && (H95 == 1)) { if (case_95) return 1; }
    else if ((H97 == 3) && (H96 == 2)) { if (case_96) return 1; }
    else if ((H97 == 3) && (H95 == 2)) { if (case_95) return 1; }
    //return 1;
}
int case_98_sword(int& fight, int case_95, int case_96, int case_97, int case_98) {
    //fight = 0;
    if (case_98 == 1 || (case_95 == 1 && case_96 == 1 && case_97 == 1)) { return 1; }
    else { return 0; }
}
int case_99_Ultimecia(int& fight, int& hp, int case_98, int case_6, int case_14, int Lionheart, int& win_counter, int& lose_counter, int Guinevere)
{
    fight = 1;
    if ((case_98 < 1 && (case_6 > 0 && case_14 == 1)) && Guinevere == 0 && Lionheart < 1) {
        lose_counter++;
        if (hp > 2) {
            hp = hp / 3;
        }
        else hp = 1;
        return 0;
    }
    if ((case_98 < 1 && (case_6 > 0 && case_14 == 0)) && Guinevere == 0 && Lionheart < 1) {
        lose_counter++;
        if (hp > 8) {
            hp = hp / 9;
        }
        else hp = 1;
        return 0;
    }
    else if (case_98 < 1 && ((case_6 < 1 && case_14 == 1) || Guinevere == 1) && Lionheart << 1) {
        lose_counter++;
        if (hp > 3) {
            hp = hp = hp / 4;
        }
        else hp = 1;
        return 0;
    }
    else if (case_98 < 1 && case_6 < 1 && case_14 == 0 && Guinevere == 0 && Lionheart < 1) {
        lose_counter++;
        if (hp > 2) {
            hp = hp / 3;
        }
        else hp = 1;
        return 0;
    }
    else if ((case_98 > 0 || Lionheart == 1) && case_6 > 1) {
        if (hp > 2) {
            hp = hp / 3;
        }
        else hp = 1;
        win_counter++;
        return 1;
    }

    else if (case_98 > 0 || Lionheart == 1) {
        win_counter++;
        
        return 1;
    }
}

void fight_in_castle_ith(int& ALive, int& NotYetCase_17, int& RevDoor, int& case_17, int& H95, int& H96, int& H97, int& ignore, int& DevilWingsDone, int& temp, int& fight, int prime, int& GoldCoin, int& meetFakeOdin, int& mushroom, int mode, knight& theKnight, int arrEvent[], int nEvent, int& nPetal, int& hp_MAX, int& win_counter, int& lose_counter, int& case_6, int& case_8, int& case_9, int& case_11, int& case_13, int& case_14, int& case_15, int& case_95, int& case_96, int& case_97, int& case_98, int& case_99, int& Lionheart, int& Eternal_Love_int, int Arthur, int Lancelot, int Guinevere, int Paladin, int Dragon_Knight, int& fakeOdin, int& fakeArmor, int& antidote, int& DevilWings)
{
    
    int k = 0;
    int Princess_case = 0;
    if (case_17 == 1 && theKnight.HP < 1) {
        k = RevDoor + 1;
        using_gil_to_revived(theKnight.HP, theKnight.gil, hp_MAX, case_6, mushroom, DevilWings, fakeArmor);
        case_17 = 0;
    }
    if (case_17 == 1 && NotYetCase_17 == 1 && ALive == 0) {
        k = RevDoor + 1;
    }
    if (DevilWingsDone == 1) {
        k = temp + 1;
    }
    while (k < nEvent)
    {
        poisoned_case(case_6, antidote, mushroom, DevilWings, fakeArmor);
        Durian_counter(case_9);
        meetFakeOdinCount(fakeOdin, meetFakeOdin);
        Odin_counter(case_11,fakeOdin);
        Nina_counter(case_8);
        Lionheart_vounter(Lionheart, case_8, Paladin);
        Eternal_Love_int = Eternal_Love(case_95, case_96, case_97, Arthur, Lancelot, Guinevere);
        switch (arrEvent[k])
        {
        case 1: {
            case_1(fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 1.0, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor, mushroom);
            k++;
            break;
        }
        case 2: {
            if (Guinevere == 1) {
                Princess_case = 1;
            }
            case_2(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 1.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor);
            k++;
            Princess_case = 0;
            break;
        }
        case 3: {

            case_3(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 4.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor, antidote);
            k++;
            break;
        }
        case 4: {

            case_4(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 4.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor);
            k++;
            break;
        }
        case 5: {
            // can sưa chưa lui castle
            case_5(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 4.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor, DevilWings);
            temp = k;
            k++;
            break;
        }
        case 6: {
            case_6 = case_6_Tornbery(fight, theKnight.HP, theKnight.level, theKnight.gil, k + 1, case_98, case_6, case_11, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Paladin, Dragon_Knight, fakeOdin, fakeArmor);
            k++;
            break;
        }
        case 7:
        {
            case_7_Queen(fight, theKnight.HP, theKnight.level, theKnight.gil, k + 1, case_11, case_15, case_98, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, fakeArmor, case_14);
            k++;
            break;
        }
        case 8:
        {
            case_8_Nina_de_Rings(fight, hp_MAX, theKnight.HP, theKnight.level, theKnight.gil, k + 1, case_6, case_8, case_11, case_15, case_98, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeArmor, case_14);
            k++;
            break;
        }
        case 9:
        {
            case_9 = case_9_Durian_Garden(fight, hp_MAX, theKnight.HP, nPetal, case_6, case_15,case_11,mushroom,ignore);
            k++;
            break;
        }
        case 10:
        {
            case_10_mushroom(fight, theKnight.HP, theKnight.gil, hp_MAX, case_11, case_6, case_14, antidote, Paladin, mushroom, DevilWings, fakeArmor);
            k++;
            break;
        }
        case 11:
        {
            case_11 = case_11_Odin(fight, case_9, case_11, meetFakeOdin, fakeOdin);
            k++;
            break;
        }
        case 12:
        {
            case_12_Merlin(fight, case_6, hp_MAX, theKnight.HP, fakeArmor, GoldCoin);
            k++;
            break;
        }
        case 13:
        {
            case_13 = case_13_Omega_Weapon(fight, hp_MAX, theKnight.HP, theKnight.level, case_98, theKnight.gil, case_13, case_14, win_counter, lose_counter, Dragon_Knight, Lionheart);
            k++;
            break;
        }
        case 14:
        {
            //int& fight, int fakeOdin, int fakeArmor, int& meetFakeOdin, int& GoldCoin, int& hp, int& gil, int& level, int i, int& case_11, int& case_14, int case_15, int case_95, int case_96, int case_97,int case_98, int Lionheart, int Eternal_Love_int, int prime, int& win_counter, int& lose_counter, int Arthur, int Lancelot, int Guinevere, int Dragon_Knight, int Paladin) {
 
            case_14 = case_14_Hades(fight, fakeOdin, fakeArmor, meetFakeOdin, GoldCoin, theKnight.HP, theKnight.gil, theKnight.level, k + 1, case_11, case_14, case_15, case_95, case_96, case_97, case_98, Lionheart, Eternal_Love_int, prime, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Dragon_Knight, Paladin);
            k++;
            break;
        }
        case 15:
        {
            case_15 = case_15_SH(fight,case_15);
            k++;
            break;
        }
        case 16: {
            int a = case_16(fight, k + 1, theKnight.level, nEvent, Lancelot, Dragon_Knight);
            if (a == 1) k++;
            else if (a == 2) k = nEvent;
            break;
        }
        case 17: {
            case_17 = case_17_RevDoor(case_17,NotYetCase_17);
            RevDoor = k;
            k ++;
            break;

        }
        case 95: {
            case_95 = case_95_shield(fight, H95, H96, H97, case_95, case_96, case_97);
            k++;
            break;
        }
        case 96: {
            case_96 = case_96_spear(fight, H95, H96, H97, case_95, case_96, case_97);
            k++;
            break;
        }
        case 97: {
            case_97 = case_97_hair(fight, H95, H96, H97, case_95, case_96, case_97);
            k++;
            break;
        }
        case 98: {
            case_98 = case_98_sword(fight, case_95, case_96, case_97, case_98);
            k++;
            break;
        }
        case 99: {
            case_99 = case_99_Ultimecia(fight, theKnight.HP, case_98, case_6, case_14, Lionheart, win_counter, lose_counter, Guinevere);
            k++;
            break;
        }
        }
        if (case_17 == 1 && NotYetCase_17 == 0) {
            break;
        }
        if (theKnight.HP < 1) {   //    mất  hết máu
            if (case_17 == 1) {
                break;
            }
            else {
                using_gil_to_revived(theKnight.HP, theKnight.gil, hp_MAX, case_6, mushroom, DevilWings, fakeArmor);
                if (theKnight.HP < 1) break;
            }
            
            
        }
        nPetal = nPetal - 1;

        if (Arthur == 1 && nPetal < 0) nPetal = 0;
        event_counter++;
        if (case_99 == 1) break;
        if (nPetal < 1 && Arthur == 0) break;
        if (DevilWings != 0) break;
        //if (DevilWings == 0) DoneDevilWings = 1;
        //if (DevilWings == 0 && DoneDevilWings == 1 || k == 0 && MeetDevilWings == 1 && 0 < DevilWings < 6) {
        //    break;
        //}
    }

}
void reverge_fight_in_castle_ith(int ALive, int& NotYetCase_17, int& RevDoor, int& case_17, int& H95, int& H96, int& H97, int& ignore, int& temp, int& fight, int prime, int& GoldCoin, int& meetFakeOdin, int& mushroom, int mode, knight& theKnight, int arrEvent[], int nEvent, int& nPetal, int& hp_MAX, int& win_counter, int& lose_counter, int& case_6, int& case_8, int& case_9, int& case_11, int& case_13, int& case_14, int& case_15, int& case_95, int& case_96, int& case_97, int& case_98, int& case_99, int& Lionheart, int& Eternal_Love_int, int Arthur, int Lancelot, int Guinevere, int Paladin, int Dragon_Knight, int& fakeOdin, int& fakeArmor, int& antidote, int& DevilWings)
{


    int k = temp - 1;
    int Princess_case = 0;
    if (case_17 == 1 && theKnight.HP < 1) {
        k = RevDoor + 1;
        using_gil_to_revived(theKnight.HP, theKnight.gil, hp_MAX, case_6, mushroom, DevilWings, fakeArmor);
        case_17 = 0;
    }
    /*if (case_17 == 1 && NotYetCase_17 == 1) {
        k = RevDoor + 1;
    }*/
    while (k >= 0)
    {
        poisoned_case(case_6, antidote, mushroom, DevilWings, fakeArmor);
        Durian_counter(case_9);
        meetFakeOdinCount(fakeOdin, meetFakeOdin);
        Odin_counter(case_11,fakeOdin);
        Nina_counter(case_8);
        Lionheart_vounter(Lionheart, case_8, Paladin);
        Eternal_Love_int = Eternal_Love(case_95, case_96, case_97, Arthur, Lancelot, Guinevere);

        switch (arrEvent[k])
        {
        case 1: {
            case_1(fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 1.0, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor, mushroom);
            DevilWings--;
            k--;
            break;
        }
        case 2: {
            if (Guinevere == 1) {
                Princess_case = 1;
            }
            case_2(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 1.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor);
            DevilWings--;
            k--;
            Princess_case = 0;
            break;
        }
        case 3: {

            case_3(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 4.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor, antidote);
            k--;
            DevilWings--;
            break;
        }
        case 4: {

            case_4(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 4.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor);
            k--;
            break;
        }
        case 5: {
            // can sưa chưa lui castle
            case_5(mushroom, fight, hp_MAX, theKnight.HP, theKnight.gil, theKnight.level, 100, 4.5, k + 1, case_98, case_6, case_11, case_14, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeOdin, fakeArmor, DevilWings);
            //temp = k;
            DevilWings--;
            k--;
            break;
        }
        case 6: {
            case_6 = case_6_Tornbery(fight, theKnight.HP, theKnight.level, theKnight.gil, k + 1, case_98, case_6, case_11, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Paladin, Dragon_Knight, fakeOdin, fakeArmor);
            k--;
            DevilWings--;
            break;
        }
        case 7:
        {
            case_7_Queen(fight, theKnight.HP, theKnight.level, theKnight.gil, k + 1, case_11, case_15, case_98, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, fakeArmor, case_14);
            k--;
            DevilWings--;
            break;
        }
        case 8:
        {
            case_8_Nina_de_Rings(fight, hp_MAX, theKnight.HP, theKnight.level, theKnight.gil, k + 1, case_6, case_8, case_11, case_15, case_98, Lionheart, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Paladin, fakeArmor, case_14);
            k--;
            DevilWings--;
            break;
        }
        case 9:
        {
            case_9 = case_9_Durian_Garden(fight, hp_MAX, theKnight.HP, nPetal, case_6, case_15,case_11,mushroom,ignore);
            k--;
            DevilWings--;
            break;
        }
        case 10:
        {
            case_10_mushroom(fight, theKnight.HP, theKnight.gil, hp_MAX, case_11, case_6, case_14, antidote, Paladin, mushroom, DevilWings, fakeArmor);
            k--;
            DevilWings--;
            break;
        }
        case 11:
        {
            case_11 = case_11_Odin(fight, case_9, case_11, meetFakeOdin, fakeOdin);
            k--;
            DevilWings--;
            break;
        }
        case 12:
        {
            case_12_Merlin(fight, case_6, hp_MAX, theKnight.HP, fakeArmor, GoldCoin);
            k--;
            DevilWings--;
            break;
        }
        case 13:
        {
            case_13 = case_13_Omega_Weapon(fight, hp_MAX, theKnight.HP, theKnight.level, case_98, theKnight.gil, case_13, case_14, win_counter, lose_counter, Dragon_Knight, Lionheart);
            k--;
            DevilWings--;
            break;
        }
        case 14:
        {
            case_14 = case_14_Hades(fight, fakeOdin, fakeArmor, meetFakeOdin, GoldCoin, theKnight.HP, theKnight.gil, theKnight.level, k + 1, case_11, case_14, case_15, case_95, case_96, case_97, case_98, Lionheart, Eternal_Love_int, prime, win_counter, lose_counter, Arthur, Lancelot, Guinevere, Dragon_Knight, Paladin);
            k--;
            DevilWings--;
            break;
        }
        case 15:
        {
            case_15 = case_15_SH(fight,case_15);
            k--;
            DevilWings--;
            break;
        }
        case 16: {
            int a = case_16(fight, k + 1, theKnight.level, nEvent, Lancelot, Dragon_Knight);
            if (a == 1) k--;
            else if (a == 2) k = nEvent;
            DevilWings--;
            break;
        }
        case 17: {
            case_17 = case_17_RevDoor(case_17, NotYetCase_17);
            RevDoor = k;
            //k++;
            k = k;
            break;

        }
        case 95: {
            case_95 = case_95_shield(fight, H95, H96, H97, case_95, case_96, case_97);
            k--;
            DevilWings--;
            break;
        }
        case 96: {
            case_96 = case_96_spear(fight, H95, H96, H97, case_95, case_96, case_97);
            k--;
            DevilWings--;
            break;
        }
        case 97: {
            case_97 = case_97_hair(fight, H95, H96, H97, case_95, case_96, case_97);
            k--;
            DevilWings--;
            break;
        }
        case 98: {
            case_98 = case_98_sword(fight, case_95, case_96, case_97, case_98);
            k--;
            DevilWings--;
            break;
        }
        case 99: {
            case_99 = case_99_Ultimecia(fight, theKnight.HP, case_98, case_6, case_14, Lionheart, win_counter, lose_counter, Guinevere);
            k--;
            DevilWings--;
            break;
        }
        }
        
        if (case_17 == 1 && NotYetCase_17 == 0) {
            break;
        }
        if (theKnight.HP < 1) {   //    mất  hết máu
            if (case_17 == 1) {
                break;
            }
            else {
                using_gil_to_revived(theKnight.HP, theKnight.gil, hp_MAX, case_6, mushroom, DevilWings, fakeArmor);
                if (theKnight.HP < 1) break;
            }


        }
        nPetal = nPetal - 1;
        if (Arthur == 1 && nPetal < 0) nPetal = 0;
        event_counter++;
        if (case_99 == 1) break;
        if (nPetal < 1 && Arthur == 0) break;
        if (DevilWings == 0) break;

    }

}
report* walkthrough(knight& theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
    
    report* pReturn;
    int hp_MAX = theKnight.HP;
    int win_counter = 0;
    int lose_counter = 0;
    int case_5 = 0, case_7 = 0, case_6 = 0, case_8 = 0, case_9 = 0, case_11 = 0, case_13 = 0, case_14 = 0, case_15 = 0;
    int case_95 = 0, case_96 = 0, case_97 = 0, case_98 = 0, case_99 = 0, case_17 = 0;
    int H95 = 0, H96 = 0, H97 = 0;
    int DevilWings = 0;
    int Katana = 0;
    int fight = 0;
    int addk = 0;
    int temp = 0;
    int temp2 = 0;
    int temp3 = 0;
    int NotYetCase_17 = 0;
    int MeetDevilWings = 0;
    int DevilWingsDone = 0;
    int RevivePos = 0;
    int meetFakeOdin = 0;
    int fakeOdin = 0;
    int fakeArmor = 0;
    int ignore = 0;
    int RevDoor = 0;
    int Antidote = 0;
    int GoldCoin = 0;
    int Lionheart = 0;
    int mushroom = 0;
    int Eternal_Love = 0;
    int Arthur = 0;
    int ALive = 0;
    int Lancelot = 0;
    int Guinevere = 0;
    int prime = prime_number(theKnight.HP);
    int Paladin = checksmith(theKnight.HP);
    int Dragon_Knight = DragonKnightCheck(theKnight.HP);

    int bFlag;
    Mode(mode, H95, H96, H97);
    if (theKnight.HP == 999) {
        case_98 = 1;
        Arthur = 1;
        while (theKnight.HP > 0) {
            for (int i = 0; i < nCastle; i++) {
                fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore,DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                //fight = 0;
                if (DevilWings != 0)
                {
                    temp2 = temp;
                    for (int k = i; k >= 0; k--)
                    {
                        for (int j = temp; j > 0; j--)
                        {
                            reverge_fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[k].arrEvent, arrCastle[k].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                            if (DevilWings > 0 && k > 0) {
                                temp = arrCastle[k - 1].nEvent;
                                if (fight != 0) {
                                    theKnight.level++;
                                    if (theKnight.level > level_MAX) theKnight.level = 10;
                                    else hp_increase_with_1_lv(hp_MAX);
                                }
                                break;
                            }
                            else if (DevilWings > 0 && k == 0) {
                                DevilWings = 0;
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }
                            if (DevilWings == 0) {
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }

                        }
                    }
                    if (DevilWings == 0)
                    {
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        DevilWingsDone = 0;
                    }
                }
                if (case_17 == 1) {
                    
                    if (theKnight.HP < 1) {
                        i = temp;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                           
                    }
                    else if(ALive == 0){
                        temp3 = i;
                        NotYetCase_17 = 1;
                        ALive = 1;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        
                    }
                }
                //fight = 0;
                if (case_99 == 1) break;
                if (theKnight.HP < 1) break;
                if (fight != 0) {
                    theKnight.level++;
                    if (theKnight.level > level_MAX) theKnight.level = 10;
                    else hp_increase_with_1_lv(hp_MAX);
                }
            }
            fight = 0;
            if (case_99 == 1) break;
            if (theKnight.HP < 1) break;
        }
    }
    else if (theKnight.HP == 888) {
        case_96 = 1;
        Lancelot = 1;
        while (nPetal > 0) {
            for (int i = 0; i < nCastle; i++) {
                fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                
                if (DevilWings != 0)
                {
                    temp2 = temp;
                    for (int k = i; k >= 0; k--)
                    {
                        for (int j = temp; j > 0; j--)
                        {
                            reverge_fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[k].arrEvent, arrCastle[k].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                            if (DevilWings > 0 && k > 0) {
                                temp = arrCastle[k - 1].nEvent;
                                if (fight != 0) {
                                    theKnight.level++;
                                    if (theKnight.level > level_MAX) theKnight.level = 10;
                                    else hp_increase_with_1_lv(hp_MAX);
                                }
                                break;
                            }
                            else if (DevilWings > 0 && k == 0) {
                                DevilWings = 0;
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }
                            if (DevilWings == 0) {
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }

                        }
                    }
                    if (DevilWings == 0)
                    {
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        DevilWingsDone = 0;
                    }
                }
                if (case_17 == 1) {

                    if (theKnight.HP < 1) {
                        i = temp;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                    else if (ALive == 0) {
                        temp3 = i;
                        NotYetCase_17 = 1;
                        ALive = 1;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                }
                //fight = 0;
                if (nPetal == 0) break;
                if (case_99 == 1) break;
                if (theKnight.HP < 1) break;
                if (fight != 0) {
                    theKnight.level++;
                    if (theKnight.level > level_MAX) theKnight.level = 10;
                    else hp_increase_with_1_lv(hp_MAX);
                }

            }
            fight = 0;
            if (case_99 == 1) break;
            if (theKnight.HP < 1) break;
        }
    }
    else if (theKnight.HP == 777) {
        case_97 = 1;
        Guinevere = 1;
        while (nPetal > 0) {
            for (int i = 0; i < nCastle; i++) {
                fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                
                if (DevilWings != 0)
                {
                    temp2 = temp;
                    for (int k = i; k >= 0; k--)
                    {
                        for (int j = temp; j > 0; j--)
                        {
                            reverge_fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[k].arrEvent, arrCastle[k].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                            if (DevilWings > 0 && k > 0) {
                                temp = arrCastle[k - 1].nEvent;
                                if (fight != 0) {
                                    theKnight.level++;
                                    if (theKnight.level > level_MAX) theKnight.level = 10;
                                    else hp_increase_with_1_lv(hp_MAX);
                                }
                                break;
                            }
                            else if (DevilWings > 0 && k == 0) {
                                DevilWings = 0;
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }
                            if (DevilWings == 0) {
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }

                        }
                    }
                    if (DevilWings == 0)
                    {
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        DevilWingsDone = 0;
                    }
                }
                if (case_17 == 1) {

                    if (theKnight.HP < 1) {
                        i = temp;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                    else if (ALive == 0) {
                        temp3 = i;
                        NotYetCase_17 = 1;
                        ALive = 1;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                }
                //fight = 0;
                if (nPetal == 0) break;
                if (case_99 == 1) break;
                if (theKnight.HP < 1) break;
                if (fight != 0) {
                    theKnight.level++;
                    if (theKnight.level > level_MAX) theKnight.level = 10;
                    else hp_increase_with_1_lv(hp_MAX);
                }

            }
            fight = 0;
            if (case_99 == 1) break;
            if (theKnight.HP < 1) break;
        }
    }
    else if (Paladin == 1) {
        case_95 = 1;
        while (nPetal > 0) {
            for (int i = 0; i < nCastle; i++) {
                fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                
                if (DevilWings != 0)
                {
                    temp2 = temp;
                    for (int k = i; k >= 0; k--)
                    {
                        for (int j = temp; j > 0; j--)
                        {
                            reverge_fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[k].arrEvent, arrCastle[k].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                            if (DevilWings > 0 && k > 0) {
                                temp = arrCastle[k - 1].nEvent;
                                if (fight != 0) {
                                    theKnight.level++;
                                    if (theKnight.level > level_MAX) theKnight.level = 10;
                                    else hp_increase_with_1_lv(hp_MAX);
                                }
                                break;
                            }
                            else if (DevilWings > 0 && k == 0) {
                                DevilWings = 0;
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }
                            if (DevilWings == 0) {
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }

                        }
                    }
                    if (DevilWings == 0)
                    {
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        DevilWingsDone = 0;
                    }
                }
                if (case_17 == 1) {

                    if (theKnight.HP < 1) {
                        i = temp;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                    else if (ALive == 0) {
                        temp3 = i;
                        NotYetCase_17 = 1;
                        ALive = 1;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                }
                //fight = 0;
                if (nPetal == 0) break;
                if (case_99 == 1) break;
                if (theKnight.HP < 1) break;
                if (fight != 0) {
                    theKnight.level++;
                    if (theKnight.level > level_MAX) theKnight.level = 10;
                    else hp_increase_with_1_lv(hp_MAX);
                }

            }
            fight = 0;
            if (case_99 == 1) break;
            if (theKnight.HP < 1) break;

        }

    }
    else if (Dragon_Knight == 1 && theKnight.HP != 888) {
        while (nPetal > 0) {
            for (int i = 0; i < nCastle; i++) {
                fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp,fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                
                if (DevilWings != 0)
                {
                    temp2 = temp;
                    for (int k = i; k >= 0; k--)
                    {
                        for (int j = temp; j > 0; j--)
                        {
                            reverge_fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[k].arrEvent, arrCastle[k].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                            if (DevilWings > 0 && k > 0) {
                                temp = arrCastle[k - 1].nEvent;
                                if (fight != 0) {
                                    theKnight.level++;
                                    if (theKnight.level > level_MAX) theKnight.level = 10;
                                    else hp_increase_with_1_lv(hp_MAX);
                                }
                                break;
                            }
                            else if (DevilWings > 0 && k == 0) {
                                DevilWings = 0;
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }
                            if (DevilWings == 0) {
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }

                        }
                    }
                    if (DevilWings == 0)
                    {
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        DevilWingsDone = 0;
                    }
                }
                if (case_17 == 1) {

                    if (theKnight.HP < 1) {
                        i = temp;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                    else if (ALive == 0) {
                        temp3 = i;
                        NotYetCase_17 = 1;
                        ALive = 1;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                }
                if (nPetal == 0) break;
                if (case_99 == 1) break;
                if (theKnight.HP < 1) break;
                if (fight != 0) {
                    theKnight.level++;
                    if (theKnight.level > level_MAX) theKnight.level = 10;
                    else hp_increase_with_1_lv(hp_MAX);
                }
            }
            fight = 0;
            if (case_99 == 1) break;
            if (theKnight.HP < 1) break;

        }

    }
    else
    {
        while (nPetal > 0) 
        {
            for (int i = 0; i < nCastle; i++) 
            {
                fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                if (DevilWings != 0)
                {
                    temp2 = temp;
                    for (int k = i; k >= 0; k--)
                    {
                        for (int j = temp; j > 0; j--)
                        {
                            reverge_fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[k].arrEvent, arrCastle[k].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                            if (DevilWings > 0 && k > 0) {
                                temp = arrCastle[k-1].nEvent;
                                if (fight != 0) {
                                    theKnight.level++;
                                    if (theKnight.level > level_MAX) theKnight.level = 10;
                                    else hp_increase_with_1_lv(hp_MAX);
                                }
                                break;
                            }
                            else if (DevilWings > 0 && k == 0) {
                                DevilWings = 0;
                                temp = temp2;
                                DevilWingsDone = 1;
                                break;
                            }
                            if (DevilWings == 0) { 
                                temp = temp2;
                                DevilWingsDone = 1;
                                break; 
                            }
                            
                        }
                    }
                    if (DevilWings == 0) 
                    {
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);
                        DevilWingsDone = 0;
                    }
                }
                if (case_17 == 1) {

                    if (theKnight.HP < 1) {
                        i = temp;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                    else if (ALive == 0) {
                        temp3 = i;
                        NotYetCase_17 = 1;
                        ALive = 1;
                        fight_in_castle_ith(ALive, NotYetCase_17, RevDoor, case_17, H95, H96, H97, ignore, DevilWingsDone, temp, fight, prime, GoldCoin, meetFakeOdin, mushroom, mode, theKnight, arrCastle[i].arrEvent, arrCastle[i].nEvent, nPetal, hp_MAX, win_counter, lose_counter, case_6, case_8, case_9, case_11, case_13, case_14, case_15, case_95, case_96, case_97, case_98, case_99, Lionheart, Eternal_Love, Arthur, Lancelot, Guinevere, Paladin, Dragon_Knight, fakeOdin, fakeArmor, antidote, DevilWings);

                    }
                }
                if (nPetal == 0) break;
                if (case_99 == 1) break;
                if (theKnight.HP < 1) break;
                if (fight != 0) {
                    theKnight.level++;
                    if (theKnight.level > level_MAX) theKnight.level = 10;
                    else hp_increase_with_1_lv(hp_MAX);
                }
            }
            fight = 0;
            if (case_99 == 1) break;
            if (theKnight.HP < 1) break;
        }

    }

    bFlag = 1;
    if (case_99 < 0) bFlag = 0;

    // success or failure?	
    pReturn = (bFlag) ? new report : NULL;
    // tra ve pReturn
    if (pReturn != NULL) {
        pReturn->nPetal = nPetal;
        pReturn->nWin = win_counter;
        pReturn->nLose = lose_counter;
    }

    // std::cout << pReturn->nPetal << " " << pReturn->nWin << " " << pReturn->nLose;
    return pReturn;
}