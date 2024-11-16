#include <iostream>
#include "BitArray.h"
#include "gtest/gtest.h"

#define ASSERT_THROW(statement,expected_exception)

//проверка, что операция побитового AND (&) работает корректно для класса BitArray
TEST (BitArray, AND) {
   BitArray array(10, 0);
    array[5] = true;
    array[9] = true;

    BitArray cmp(10, 0);

    cmp.set();
    array &= cmp;
    ASSERT_EQ("0000010001", array.to_string());

    cmp.reset();
    array &= cmp;
    ASSERT_EQ("0000000000", array.to_string());
}

//проверка, что операция побитового OR (|) работает корректно для класса BitArray.
TEST (BitArray, OR) {
    BitArray array(10, 0);
    array[5] = true;
    array[9] = true;

    BitArray cmp(10, 0);

    array |= cmp;
    ASSERT_EQ("0000010001", array.to_string());

    cmp.set();
    array |= cmp;
    ASSERT_EQ("1111111111", array.to_string());
}

//проверка, что операция побитового OR (|) работает корректно для класса BitArray.
TEST (BitArray, XOR) {
    BitArray array(10, 0);
    array[5] = true;
    array[9] = true;

    BitArray cmp(10, 0);

    array ^= cmp;
    ASSERT_EQ("0000010001", array.to_string());

    cmp.set();
    array ^= cmp;
    ASSERT_EQ("1111101110", array.to_string());
}

//проверка на функциональность индексации и получения значения отдельного бита в классе BitArray
TEST (BitArray, EquiatingTest) {
    BitArray array(8, 154); //10011010

    bool a = array[3];

    ASSERT_EQ(true, a);
}

//проверка на функциональность присваивания значения отдельному биту в классе BitArray.
TEST (BitArray, AssignTest) {
    BitArray array(8, 154); //10011010

    bool a = array[1];
    ASSERT_EQ(false, a);

    array[1] = true;
    a = array[1];
    ASSERT_EQ(true, a);
}

//проверка на функциональность управления памятью в классе BitArray
TEST (BitArray, MemoryTest) {
    BitArray array(8, 154);

    ASSERT_EQ(1, array.bytes());

    array[33] = true;
    ASSERT_EQ(2, array.bytes());

}

//проверка на добавление нового бита в конец массива
TEST(BitArray, MemoryTriggered) {
    BitArray array(32, 0);

    array.push_back(true);

    ASSERT_EQ("000000000000000000000000000000001", array.to_string());
}

//проверка на изменение размера массива
TEST (BitArray, ExpandTest) {
    BitArray array(33, 0);
    array.resize(34);

    string str;
    int count = 0;
    while (count < 34) {
        str += "0";
        count++;
    }

    ASSERT_EQ(str, array.to_string());
}


//проверка на установку всех битов в массиве в значение true (1)
TEST(BitArray, SetNoOperands) {
    BitArray array(33, 0);

    string allTrue;
    int cnt = 0;
    while(cnt != 33) {
        allTrue += "1";
        cnt++;
    }

    array.set();
    ASSERT_EQ(allTrue, array.to_string());
}

//проверка на устанавку биоа в массиве в заданное значение
TEST(BitArray, SetWithOperands) {
    BitArray array(33, 0);

    string str;
    str += "1";
    int cnt = 1;
    while(cnt != 33) {
        str += "0";
        cnt++;
    }

    array.set(0, true);
    ASSERT_EQ(str, array.to_string());

    array.set();
    string str2;
    cnt = 0;
    while(cnt != 32) {
        str2 += "1";
        cnt++;
    }
    str2 += "0";

    array.set(32, false);
    ASSERT_EQ(str2, array.to_string());
}

//проверка оператора побитового сдвига влево (>>=) в классе BitArray
TEST (BitArray, LeftShiftTest) {
    BitArray array(32, 1);
    array <<= 31;

    string str = "10000000000000000000000000000000";

    ASSERT_EQ(str, array.to_string());
}

TEST (BitArray, RightShiftTestWithoutChanging) {
    BitArray array(4, 1);
    ASSERT_EQ("0100", (array>>1).to_string());
}

//проверка смены местами содержимого двух объектов BitArray.
TEST (BitArray, SwapTest) {
    BitArray array1(6, 1);
    BitArray array2(4, 1);

    array1.swap(array2);

    ASSERT_EQ("1000", array1.to_string());
    ASSERT_EQ("100000", array2.to_string());

}

//проверка преобразования содержимого массива битов в строку
TEST(ToStringTest, allZeros) {
    BitArray array(33, 0);

    string str;
    int cnt = 0;
    while(cnt != 33) {
        str += "0";
        cnt++;
    }

    ASSERT_EQ(str, array.to_string());
}

TEST(BitArrayTest, ResizeDecrease) {
    BitArray array(32, 1); 

    array.resize(16, false);
    
    ASSERT_EQ(array.size(), 16);
  
    for (int i = 0; i < 16; ++i) {
        ASSERT_EQ(array[i], 1);
    }
} 

