using System;
using System.Diagnostics;

namespace lab1cs
{
    class Program
    {
        static int GetRandom()
        {
            //Создание объекта для генерации чисел
            Random rnd = new Random();

            //Получить случайное число 
            int value = rnd.Next(100);

            //Вернуть полученное значение
            return value;
        }
        static double dget(double rmin, double rmax) // получить случайное число
        {
            return ((double)GetRandom() / 100) * (rmax - rmin) + rmin;
        }
        static int iget(int rmin, int rmax)         // получить случайное число

        {
            return (int)dget((double)rmin, (double)rmax);
        }


        
        static void Main(string[] args)
        {
            int cycles = 100000;
            double av1 = 0, av2 = 0;
            Stopwatch stopwatch = new Stopwatch();
            for (int i = 0; i < 10; i++)
            {
                stopwatch.Start();                    // начало выполнения операции 
                for (int j = 0; j < cycles; j++)
                {
                    av1 += (double)iget(-100, 100); // сумма случайных чисел 
                    av2 += dget(-100, 100);         // сумма случайных чисел
                }
                stopwatch.Stop();                   // конец выполнения операции
                Console.WriteLine("количество циклов: " + cycles);
                Console.WriteLine("среднее значение (int): " + av1 / cycles);
                Console.WriteLine("среднее значение (double): " + av2 / cycles);
                Console.WriteLine("Продолжительность в секундах: " + stopwatch.ElapsedMilliseconds / 1000);
               cycles += 100000;
            }
        }
    }
}
