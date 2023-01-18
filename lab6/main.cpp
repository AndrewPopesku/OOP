#include "graphics.cpp"
#include "TPervisna.cpp"
#include "TPohidna.cpp"
#include "TPolinom.cpp"

void executeAll(TFunction *mas[], int size, double start, double end, double step)
{
    for (int i = 0; i < size; i++)
    {
        mas[i]->equation(start, end, step);
        mas[i]->draw(start, end);
    }
}

int main()
{
    drawCoordinatePlane();

    TPolinom poly;
    poly.input();
    TPohidna deriv = poly;
    TPervisna integ = poly;

    double start, end, step;
    cout << "\n\n\n-Enter parameters to tabulate function-\n" << endl;
    cout << "start(x): ";
    cin >> start;
    
    cout << "end(x): ";
    cin >> end;

    cout << "step(x): ";
    cin >> step;
    
    poly.draw(start, end);
    poly.draw(-2, 5);

    // deriv.output();
    // deriv.equation(-2, 5, 1);
    // deriv.draw(-2, 5);
    // deriv.draw(-2, 5);

    TFunction *mas[3] = {&poly, &deriv, &integ};
    deriv.output();
    executeAll(mas, 3, start, end, step);

    getch();
    closegraph();
    return 0;
}