#include <iostream>
#include <string>
using namespace std;

#define PI 3.14
#define COLOR_COST 1.6

class Shape
{
    private:
        string m_color;
        float m_amount;
        float m_area;
    public:
        //  impement...
        Shape(string col, float amount, float area) : m_color(col), m_amount(amount), m_area(area) {};
        virtual string name() = 0;
        int color_cost() { return m_area * m_amount * COLOR_COST; }
};

class Sphere : public Shape
{
    private:
        float diameters;
    public:
        // impement...
        Sphere(string color, float amount_color, float length)
         : Shape(color, amount_color, (length / 2) * (length / 2) * 4 * PI), diameters(length) {};
        string name() { return "Sphere"; }
};

class Square : public Shape
        {
        private:
            float edge;

        public:
            //  impement...
            Square(string color, float amount_color, float length)
                : Shape(color, amount_color, length * length), edge(length) {};
            string name() { return "Square"; }

};

int main()
{
    const Sphere sph1("yellow", 2.5, 3);
    Sphere sph2 = sph1;

    const Square sq1("black", 2, 1.5);

    Square sq2("white", 2.8, 1.9);
    sq2 = sq1;
    Shape *shapes[3];
    shapes[0] = &sph2;
    shapes[1] = new Square(sq2);
    shapes[2] = new Square("pink", 0.2, 3);

    for (int i = 0; i < 3; i++)
        cout << "To color " << shapes[i]->name() << " you need " << shapes[i]->color_cost() << " shekels. \n";

    delete shapes[1];
    delete shapes[2];

    return 0;
}