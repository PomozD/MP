using System;

namespace test1lab
{
    class Program
    {
        static int GetRandom()
        {
            //Создание объекта для генерации чисел
            Random rnd = new Random(0);

            //Получить случайное число 
            int value = rnd.Next();

            return value;

        }
        static void Main(string[] args)
        {

            Console.WriteLine(GetRandom());
            
        }
    }
}
