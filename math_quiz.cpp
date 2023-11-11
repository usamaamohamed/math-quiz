#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int RandomNumber(double &number ,int from, int to)
{
    //Function to generate a random number
    number = rand() % (to - from + 1) + from;
    return number;
}

int read_number_of_qusitons(int &questions_number)
{
    cout << "How Many Questions You Want To Answer? ";
    cin >> questions_number ;
    while (questions_number <= 0)
    {
        cout << "Questions number must be bigger than 0 ,Enter Again: ";
        cin >> questions_number ;
    }
    return questions_number;
}

int read_questions_level(int &questions_level)
{   
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "Which Questions Level you want? \n{ (1 for Easy) , (2 for  Mid) , (3 for Hard) , (4 for Mix) }: ";
    cin >> questions_level ;
    while (questions_level < 1 || questions_level > 4)
    {
        cout << "wrong choice you must choose (easy / mid / hard / mix) ,choose again: ";
        cin >> questions_level ;
    }
    return questions_level;
}

int read_operation_type(int &operation_type )
{
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "Enter which operation type you want to be answered? \n{1 for (+) , 2 for (-) , 3 for (*) , 4 for (/) , 5 for mix }: ";
    cin >> operation_type ;
    while (operation_type < 1 || operation_type > 5)
    {
        cout << "wrong choice you must choose (+ , - , * , /) ,choose again: ";
        cin >> operation_type ;
    }
    return operation_type;
}

enum en_QS_level {easy = 1, mid = 2 , hard = 3 , mix = 4 };

enum en_OP_type {add = 1, subtract = 2 , multiply = 3 , devide = 4 , Mix = 5 };

en_QS_level  QS_level(int questions_level ,int &from , int &to)
{
    switch (questions_level)
    {
    case en_QS_level::easy:
        from = 0;
        to = 10;
        return en_QS_level::easy;

    case en_QS_level::mid:
        from = 10;
        to = 100;
        return en_QS_level::mid;

    case en_QS_level::hard:
        from = 100;
        to = 1000;
        return en_QS_level::hard;

    case en_QS_level::mix:
        from = 0;
        to = 1000;
        return en_QS_level::mix;
    }
}

int generate_mix_operation(double &mix_operation )
{
    mix_operation = RandomNumber(mix_operation , 1 , 4);    
    return int(mix_operation);
}

en_OP_type OP_type(int operation_type , char &operation)
{
    switch (operation_type)
    {
    case en_OP_type::add:
        operation = '+';

        return en_OP_type(operation);

    case en_OP_type::subtract:
        operation = '-';
        return en_OP_type(operation);

    case en_OP_type::multiply:
        operation = '*';
        return en_OP_type(operation);

    case en_OP_type::devide:
        operation = '/';
        return en_OP_type(operation);

    case en_OP_type::Mix:

        double mix_operation = 1 ; 
        operation = OP_type( generate_mix_operation(mix_operation)  , operation);
        return en_OP_type(operation);
    }

}

int generate_numbers(double &number_1 , double &number_2 , int questions_level)
{
    int from =0 , to = 0;
    QS_level(questions_level ,from , to);
    number_1 = RandomNumber(number_1 , from , to);
    number_2 = RandomNumber(number_2 , from , to);
    return number_1 , number_2;
}

double question(int questions_level , int operation_type  ,int questions_number , int i ,double &real_answer )
{
    double number_1 = 0 , number_2 = 0;
    char operation = '+';

    operation = OP_type(operation_type , operation);
    generate_numbers(number_1 , number_2 , questions_level);

    cout << "----------------------------------------------------------------------\n";
    cout << "Question [" << i << "/" << questions_number << "]: " ;
    cout << number_1 <<" "<< operation <<" "<< number_2 << " = ";

    if (operation == '+')
    {
        real_answer = number_1 + number_2;
    }
    else if (operation == '-')
    {
        real_answer = number_1 - number_2;
    }
    else if (operation == '*')
    {
        real_answer = number_1 * number_2;
    }
    else if (operation == '/')
    {
        real_answer = round((number_1 / number_2)*100)/100;
    }
     
    return  real_answer;
}

void start_quiz(int questions_number , int questions_level , int operation_type  ) 
{
    double real_answer = 0;
    double your_answer = 0;
    int right_answers = 0; 

    for (int  i = 1; i <= questions_number; i++)
    {
        cout << "\n****************{ NOTE YOU SHOULD ROUND THE RESULT TO THE FIRST 2 DECIMAL POINTS } ****************\n";
        question(questions_level , operation_type , questions_number , i , real_answer );
        cin >> your_answer;
        if (your_answer == real_answer)
        {
            cout << "RIGHT ANSWER \n";
            right_answers++;
        }
        else
        {
            cout << "WRONG ANSWER\n";
            cout << "the right answer is " << real_answer << "\n";
        } 
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "you have " << right_answers << " answers right out of " << questions_number << "\n";

    double score = double(right_answers) / double(questions_number)*100;
    cout << "your score is " << score << endl;
    if (score >=50)
    {
        cout << "congratulations you passed the quiz successfully\n";
    }
    else cout << "you failed ,try again\n";
    
}

int main()
{
    srand((unsigned)time(NULL));

    int questions_number = 0;
    int questions_level  = 0;
    int operation_type   = 0;

    read_number_of_qusitons(questions_number);
    read_questions_level(questions_level);
    read_operation_type(operation_type);

    start_quiz(questions_number, questions_level , operation_type  );

    return 0;
}