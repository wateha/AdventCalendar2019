#include "AcDayFour.h"

AcDayFour::AcDayFour()
{
    std::cout << "--- Day 4: Secure Container ---" << std::endl;
    std::cout << "Solution A: " << countPasswords(402328, 864247) << std::endl;
    std::cout << "Solution B: " << countPasswords(402328, 864247, false) << std::endl << std::endl;
}

int AcDayFour::countPasswords(int begin, int end, bool solutionA)
{
    int passwords{};
    for (int i = begin; i < end + 1; i++) {
        int tmp{ i };
        int a[6]{};
        for (int p = 5; p >= 0; p--) {
            int pwr = (int)(std::pow(10, p));
            a[p] = (i - (i % pwr))/pwr;
            i = i % pwr;
        }

        bool trip{ false };
        bool doublet{ false };
        int store{};

        for (int count = 5; count > 0; count--) {
            if (a[count] <= a[count-1]) {
                if (!solutionA) {
                    if (a[count] == a[count - 1]) {
                        if (store == a[count] ) {
                            trip = false;
                        }
                        else {
                            if (trip) {
                                doublet = true;
                            }
                            if (count == 1) {
                                doublet = true;
                            }
                            trip = true;
                        }
                        store = a[count-1];
                    }
                    else {
                        if (count == 1 && trip) {
                            doublet = true;
                        }
                    }
                }
                else {
                    if (a[count] == a[count - 1]) {
                        trip = true;
                    }
                }
            }
            else {
                trip = false;
                doublet = false;
                break;
            }
        }

        if (doublet) {
            passwords++;
        }
        
        i = tmp;
    }
    return passwords;
}