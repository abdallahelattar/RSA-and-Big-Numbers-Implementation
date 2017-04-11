#include <iostream>
#include <string>
#include <stack>

using namespace std;

//2048 bits equals 617 digits
//2 digits per element makes them 309
class LongNumbers
{
    
public:
    const int Size2048 = 309;
    
    struct BigNum
    {
        int Num[309] = {};
        bool negative = false;
    };
    
    
    struct DivResult
    {
        BigNum Result;
        BigNum Remainder;
    };
    
    struct ArrayOfArray
    {
        BigNum Result;
        BigNum Count;
    };
    
    
    BigNum StringToArray(string input)
    {
        BigNum final;
        bool neg = false;
        
        if(input[0] == 'P' || input[0] == 'p' || input[0] == 'Q' || input[0] == 'q' || input[0] == 'E' || input[0] == 'e')
        {
            input.erase(0,2);
        }
        
        if(input[0] == '-')
        {
            neg = true;
            input.erase(0,1);
            
        }
        
        reverse(begin(input), end(input));
        
        int val = 0, itr = 1, Out = 0;
        for(int i=0; i< input.size(); i++)
        {
            val += (input[i]-'0')*itr;
            itr *= 10;
            if(itr == 100)
            {
                final.Num[Out] = val;
                Out++;
                itr = 1;
                val = 0;
            }
        }
        
        if(val != 0 )
            final.Num[Out] = val;
        
        final.negative = neg;
        return final;
    }
    
    BigNum CopyOf(BigNum input)
    {
        BigNum Result;
        Result.negative = input.negative;
        for(int i = 0; i < 309; i++)
            Result.Num[i] = input.Num[i];
        return Result;
    }
    
    BigNum AddFront(BigNum input, int val)
    {
        BigNum Result;
        Result.negative = input.negative;
        for(int i = 0; i < 308; i++)
            Result.Num[i+1] = input.Num[i];
        
        Result.Num[0] = val;
        return Result;
    }
    
    string ToPrint(BigNum input)
    {
        string out;
        bool Entered = false;
        if(input.negative == true)
            out += "-";
        
        reverse(begin(input.Num), end(input.Num));
        int i;
        for(i = 0; i < Size2048; i++)
        {
            if(input.Num[i] != 0)
                break;
        }
        int itr = 10, val = 0;
        for(int j =0; j < 2; j++)
        {
            val = input.Num[i] / itr;
            if(val != 0)
            {
                input.Num[i] = input.Num[i] - val*itr;
                out += (val+'0');
                Entered = true;
                
            }
            else
            {
                if(Entered)
                {
                    input.Num[i] = input.Num[i] - val*itr;
                    out += (val+'0');
                    
                }
            }
            itr /= 10;
        }
        
        i++;
        for(i; i < Size2048; i++)
        {
            int itr = 10, val = 0;
            for(int j =0; j < 2; j++)
            {
                val = input.Num[i] / itr;
                input.Num[i] = input.Num[i] - val*itr;
                out += (val+'0');
                itr /= 10;
            }
        }
        return out;
        
        
    }
    
    
    bool EqualZero(BigNum input)
    {
        for(int i =0; i < Size2048; i++)
        {
            if(input.Num[i] != 0)
                return false;
        }
        return true;
    }
    
    BigNum Add(BigNum first, BigNum second)
    {
        if(EqualZero(first))
            return second;
        
        if(EqualZero(second))
            return first;
        
        BigNum Result;
        int val = 0, carry = 0;
        bool BothNegative = false;
        
        if(first.negative && second.negative)
            BothNegative = true;
        
        else if(first.negative)
        {
            first.negative = false;
            Result = Sub(second, first);
            return Result;
        }
        else if(second.negative)
        {
            second.negative = false;
            Result = Sub(first, second);
            return Result;
        }
        int i = 0;
        for(i ; i < Size2048; i++)
        {
            val = (first.Num[i] + second.Num[i] + carry ) % 100;
            carry = (first.Num[i] + second.Num[i] + carry ) / 100;
            Result.Num[i] = val;
        }
        
        if(carry != 0)
            Result.Num[i] = carry;
        
        
        Result.negative = BothNegative;
        return Result;
        
    }
    
    BigNum Sub(BigNum firstOriginal, BigNum second)
    {
        //Op1 - Op2 .. first - second
        if(EqualZero(second))
        {
            return firstOriginal;
        }
        if(EqualZero(firstOriginal))
        {
            second.negative = true;
            return second;
        }
        
        
        BigNum Result, tempResult, first;
        first = CopyOf(firstOriginal);
        int val = 0, NextToMe = 0;
        bool LastNum = false;
        
        
        if(second.negative)
        {
            if(first.negative)
            {
                first.negative = false;
                second.negative = false;
                Result = Sub(second, first);
                return Result;
            }
            else
            {
                second.negative = false;
                Result = Add(first, second);
                return Result;
            }
        }
        else
        {
            if(first.negative)
            {
                first.negative = false;
                second.negative = false;
                Result = Add(first, second);
                Result.negative = true;
                return Result;
            }
        }
        
        
        int i = 0;
        for(i; i < Size2048; i++)
        {
            if(LastNum)
                break;
            if(first.Num[i] >= second.Num[i])
            {
                val = first.Num[i] - second.Num[i];
                Result.Num[i] = val;
            }
            else
            {
                if(i == Size2048)
                    LastNum = true;
                
                int temp = i;
                while(temp < 308)
                {
                    temp++;
                    NextToMe++;
                    if(first.Num[temp] != 0)
                    {
                        first.Num[temp] -= 1;
                        first.Num[i] = first.Num[i] + 100;
                        
                        NextToMe--;
                        
                        temp = i+1;
                        i--;
                        while(NextToMe != 0)
                        {
                            first.Num[temp] = 99;
                            NextToMe--;
                            temp++;;
                        }
                        break;
                    }
                    else if(first.Num[temp] == 0 && temp == 308)
                        LastNum = true;
                }
            }
        }
        
        if(LastNum == true)
        {
            Result = Sub(second, firstOriginal);
            Result.negative = true;
            return Result;
        }
        
        return Result;
        
    }
    
    BigNum Mul(BigNum first, BigNum second)
    {
        BigNum Result;
        
        if(EqualZero(first))
            return first;
        if(EqualZero(second))
            return second;
        
        
        int val = 0, carry = 0;
        bool neg = false;
        
        if(first.negative && second.negative)
        {
            first.negative = false;
            second.negative = false;
        }
        else if(first.negative)
        {
            first.negative = false;
            neg = true;
        }
        else if(second.negative)
        {
            second.negative = false;
            neg = true;
        }
        
        int i ,j;
        for(i = 0; i < Size2048; i++)
        {
            BigNum temp;
            for(j = 0; j < Size2048; j++)
            {
                val = ((first.Num[i] * second.Num[j]) + carry ) % 100;
                carry = ((first.Num[i] * second.Num[j]) + carry ) / 100;
                
                temp.Num[j] += val;
            }
            
            if(i!=0)
            {
                for(int k = 308; k != 0; k--)
                {
                    temp.Num[k] = temp.Num[k-i];
                }
                for(int k = 0; k < i; k++)
                {
                    temp.Num[k] = 0;
                }
            }
            Result = Add(Result, temp);
        }
        
        Result.negative = neg;
        return Result;
    }
    
    DivResult DivSmall(BigNum first, BigNum second)
    {
        DivResult Result;
        
        if(EqualZero(first))
        {
            Result.Result = first;
            Result.Remainder = first;
            return Result;
        }
        
        BigNum countArray, One, tempResult = first;
        One.Num[0] = 1;
        
        bool CheckNeg = tempResult.negative;
        do
        {
            tempResult = Sub(tempResult, second);
            CheckNeg = tempResult.negative;
            if(countArray.Num[0] != 99)
                countArray.Num[0] = countArray.Num[0]+1;
            else
                countArray = Add(countArray, One);
        }
        while(!CheckNeg);
        
        if(countArray.Num[0] != 0)
        {
            countArray.Num[0] = countArray.Num[0]-1;
            Result.Result = countArray;
        }
        else
            Result.Result = Sub(countArray, One);
        
        Result.Remainder = Add(tempResult, second);
        
        return Result;
    }
    
    DivResult DivLarge(BigNum first, BigNum second)
    {
        DivResult Result, tempResult;
        BigNum partOffirst, test;
        
        if(EqualZero(first))
        {
            Result.Result = first;
            Result.Remainder = first;
        }
        
        bool neg = false;
        
        if(first.negative && second.negative)
        {
            first.negative = false;
            second.negative = false;
        }
        else if(first.negative)
        {
            first.negative = false;
            neg = true;
        }
        else if(second.negative)
        {
            second.negative = false;
            neg = true;
        }
        
        reverse(begin(first.Num), end(first.Num));
        
        ///////
        int i = 0;
        while( i != 309)
        {
            do
            {
                partOffirst = AddFront(partOffirst, first.Num[i]);
                test = Sub(partOffirst, second);
                i++;
            }
            while(test.negative && i != 309);
            
            tempResult = DivSmall(partOffirst, second);
            Result.Result.Num[309-i] = tempResult.Result.Num[0];
            
            partOffirst = tempResult.Remainder;
        }
        ///////
        
        Result.Remainder = partOffirst;
        
        Result.Remainder.negative = neg;
        Result.Result.negative = neg;
        
        return Result;
    }
    
    
    
    BigNum PwrMod(BigNum firstOriginal, BigNum secondOriginal, BigNum Mod)
    {
        if(EqualZero(firstOriginal))
            return firstOriginal;
        
        if(EqualZero(secondOriginal))
        {
            BigNum hop;
            hop.Num[0] = 1;
            return hop;
        }
        
        BigNum first = CopyOf(firstOriginal);
        BigNum second = CopyOf(secondOriginal);
        stack<LongNumbers::ArrayOfArray> memory;
        LongNumbers::ArrayOfArray AoA;
        
        
        BigNum Result, tempResult, Count, tempCount , check, two;
        LongNumbers::DivResult DR;
        two.Num[0] = 2;
        tempCount.Num[0] = 1;
        tempResult = first;
        Result = first;
        
        do
        {
            DR = DivLarge(tempResult, Mod);
            Result = DR.Remainder;
            Count = tempCount;
            AoA.Result = Result;
            AoA.Count = Count;
            memory.push(AoA);
            
            
            tempCount = Mul(Count, two);
            tempResult = Mul(Result, Result);
            
            check = Sub(second, tempCount);
        }
        while(!check.negative);
        
        Result = *new BigNum;
        Result.Num[0] = 1;
        
        while(!EqualZero(second))
        {
            AoA = memory.top();
            
            if(!Sub(second, AoA.Count).negative)
            {
                Result = Mul(Result, AoA.Result);
                DR = DivLarge(Result, Mod);
                Result = DR.Remainder;
                
                second = Sub(second, AoA.Count);
            }
            
            memory.pop();
        }
        return Result;
    }
    
    
    bool IsPrime(BigNum input)
    {
        bool Result = false;
        LongNumbers::DivResult DR;
        BigNum n = CopyOf(input);
        BigNum One, two, a, NMinusOne, K, tempK, Q, test, Calc, power;
        One.Num[0] = 1;
        two.Num[0] = 2;
        a.Num[0] = 2; // a = 2
        
        //check if even num
        DR = DivLarge(n , two);
        if(EqualZero(DR.Remainder))
            return false;
        
        NMinusOne = Sub(n, One);
        
        do
        {
            Q = NMinusOne;
            K = tempK;
            
            DR = DivLarge(NMinusOne, two);
            NMinusOne = DR.Result;
            
            if(K.Num[0] != 99)
                tempK.Num[0] = K.Num[0]+1;
            else
                tempK = Add(K, One);
            
        }
        while(EqualZero(DR.Remainder));
        
        NMinusOne = Sub(n, One);
        
        Calc = PwrMod(a, Q, n);
        DR = DivLarge(Calc, n);
        
        if(EqualZero(Sub(DR.Remainder, One)) || EqualZero(Sub(DR.Remainder, NMinusOne)))
            return true;
        
        
        if(test.Num[0] != 99)
            test.Num[0] = test.Num[0]+1;
        else
            test = Add(test, One);
        
        
        while(!EqualZero(Sub(K, test)))
        {
            Calc = PwrMod(Calc, two, n);
            DR = DivLarge(Calc, n);
            
            if(EqualZero(Sub(DR.Remainder, One)))
            {
                Result = false;
                break;
            }
            else if(EqualZero(Sub(DR.Remainder, NMinusOne)))
            {
                Result = true;
                break;
            }
            
            
            if(test.Num[0] != 99)
                test.Num[0] = test.Num[0]+1;
            else
                test = Add(test, One);
        }
        
        
        return Result;
        
    }
    
    BigNum Inverse(BigNum input, BigNum mod)
    {
        BigNum Result, Q, A2, A3, B2, B3, T2, T3, Zero, One, temp;
        One.Num[0] = 1;
        
        A2 = CopyOf(Zero);
        A3 = CopyOf(mod);
        B2 = CopyOf(One);
        B3 = CopyOf(input);
        
        while(!EqualZero(B3) && !EqualZero(Sub(B3, One)))
        {
            Q = DivLarge(A3, B3).Result;
            T2 = Sub(A2, Mul(Q , B2));
            T3 = Sub(A3, Mul(Q , B3));
            
            A2 = CopyOf(B2);
            A3 = CopyOf(B3);
            
            B2 = CopyOf(T2);
            B3 = CopyOf(T3);
        }
        
        if(EqualZero(B3))
        {
            //no inverse
            //return 0
        }
        
        if(EqualZero(Sub(B3, One)))
        {
            while(B2.negative)
            {
                B2 = Add(B2, mod);
            }
            Result = B2;
            
            temp = Sub(Result, mod);
            while(!temp.negative)
            {
                Result = temp;
                temp = Sub(Result, mod);
            }
            
        }
        
        return Result;
    }
    
};

int main()
{
    LongNumbers MyNum;
    LongNumbers::BigNum PArray, QArray, EArray, DArray, NArray, PhiArray, One;
    string Pstr, Qstr, Estr, Operation, Print;
    LongNumbers::DivResult DR;
    One.Num[0] = 1;
    bool answer;
    
    cin >> Pstr;
    cin >> Qstr;
    cin >> Estr;
    
    PArray = MyNum.StringToArray(Pstr);
    QArray = MyNum.StringToArray(Qstr);
    EArray = MyNum.StringToArray(Estr);
    
    while(true)
    {
        cin >> Operation;
        
        if(Operation == "IsPPrime")
        {
            answer = MyNum.IsPrime(PArray);
            
            if(answer)
                cout << "Yes";
            else
                cout << "No";
            
            cout << endl;
        }
        else if (Operation == "IsQPrime")
        {
            answer = MyNum.IsPrime(QArray);
            
            if(answer)
                cout << "Yes";
            else
                cout << "No";
            
            cout << endl;
        }
        else if (Operation == "PrintN")
        {
            NArray = MyNum.Mul(PArray, QArray);
            Print = MyNum.ToPrint(NArray);
            cout << Print << endl;
        }
        else if (Operation == "PrintPhi")
        {
            LongNumbers::BigNum PMinusOne = MyNum.Sub(PArray, One);
            LongNumbers::BigNum QMinusOne = MyNum.Sub(QArray, One);
            PhiArray = MyNum.Mul(PMinusOne, QMinusOne);
            
            Print = MyNum.ToPrint(PhiArray);
            cout << Print << endl;
        }
        else if(Operation == "Quit")
        {
            break;
        }
        else if (Operation == "PrintD")
        {
            DArray = MyNum.Inverse(EArray, PhiArray);
            
            Print = MyNum.ToPrint(DArray);
            cout << Print << endl;
        }
        else
        {
            string msg, first = Operation.substr(0, 13);
            LongNumbers::BigNum msgArray, outArray;
            
            if(first == "EncryptPublic")
            {
                msg = Operation.substr(15, Operation.size() - 16);
                msgArray = MyNum.StringToArray(msg);
                
                outArray = MyNum.PwrMod(msgArray, EArray, NArray);
            }
            else if(first == "EncryptPrivat")
            {
                msg = Operation.substr(16, Operation.size() - 17);
                msgArray = MyNum.StringToArray(msg);
                
                outArray = MyNum.PwrMod(msgArray, DArray, NArray);
            }
            
            Print = MyNum.ToPrint(outArray);
            cout << Print << endl;
        }
        
    }
    return 0;
}














