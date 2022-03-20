#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Student
{

    std::string name;
    std::string surname;
    int album_number;
    std::vector<float> grades;
public:

    Student(std::string n,std::string s,int alb=0, std::vector<float>g={})
    {
        name = n;
        surname = s;
        album_number = alb;
        grades = g;
    }

    bool add_grade(float grade)
    {
        if (grade >= 2.0 && grade <= 5.0)
        {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    float calculate_grade()
    {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    void set_name(std::string new_name)
    {
        name = new_name;
    }

    void set_surname(std::string new_surname)
    {
        surname = new_surname;
    }

    bool set_album(int new_album)
    {
        if (new_album<1000000)
        {
            album_number = new_album;
            return true;
        }
        return false;
    }

    void display()
    {
        std::cout << "Name: " << name<< "\nSurname: " << surname<< "\nAlbum number: " << album_number
                  << "\nGrades: ";
        for(auto g: grades)
        {
            std::cout << g << " \n";
        }
    }

    void passed()
    {
        int g_2 = 0;
        for(auto g: grades)
        {
            if(g == 0)
              g_2 ++;
        }
        if(g_2 > 2)
        std::cout << "Failed" << std::endl;
        else{
        std::cout << "Passed!" << std::endl;
        }
    }

};


class Complex
{
    double real;
    double imaginary;
public:
    Complex(double r=0,double i=0)
    {
        real=r;
        imaginary=i;
    }

    void set_rl(double rl)
    {
        real=rl;
    }

    void set_im(double im)
    {
        imaginary=im;
    }

    void print()
    {
        if(imaginary>=0)
            std::cout << real << '+' << imaginary << 'i' << std::endl;
        else
            std::cout << real <<  imaginary << 'i' << std::endl;
    }

    Complex add(Complex x)
    {
        Complex res;
        res.set_rl(real+x.real);
        res.set_im(imaginary+x.imaginary);
        return res;
    }

};

int main()
{
    Student student1{"Kamal", "Azeez", (150834),{5.0,4.5,3.5,3.0,2.0}};
    student1.display();
    student1.add_grade(5.5);
    float mean = student1.calculate_grade();
    std::cout<<"average grade is: " << mean << std::endl;
    std::cout << student1.calculate_grade() << std::endl;
    student1.passed();



    Complex a(1.0, -2.0);
    Complex b(3.14);
    b.set_im(-5);
    Complex c = a.add(b);
    c.print();

    return 0;
}
