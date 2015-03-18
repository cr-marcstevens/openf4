/* 
 * Copyright (C) 2010 Antoine Joux and Vanessa Vitse 

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

/**
 *  \file benchmark-int.cpp
 *  \example benchmark-int.cpp
 *  \brief Benchmark with integer type coefficients.
 *  \ingroup benchmark
 *  \author Vanessa VITSE, Antoine JOUX, Titouan COLADON
 */

#include <iostream>
#include "../include/ideal.h"

using namespace F4;
using namespace std;

// Global variable
int F4::VERBOSE=3;

int main (int argc, char **argv)
{
    cout << "#########################################################" << endl;
    cout << "#                     BENCHMARK INT                     #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Init element-prime tools
    typedef ElementPrime<int> eltType;
    ElementPrime<int>::setModulo(65521);
    
    // Time
    clock_t start;
    
    // Number of generator
    int nbGen;
    
    // File
    ofstream file("benchmark-int.txt");
    if (file)
    {
        file << "Benchmark for ideal with integer type coefficient." << endl << endl << endl;
    }
    
    
    cout << "#########################################################" << endl;
    cout << "#                         CYCLIC 6                      #" << endl;
    cout << "#########################################################" << endl << endl;
        
    // Time 
    start=clock();
    
    // Init monomial tools
    Monomial::initMonomial(6,11,2,10);
    
    // Create polynomial array
    vector<Polynomial<eltType>> polCyclic6;
    
    // Fill the polynomial array
    polCyclic6.emplace_back("x0+x1+x2+x3+x4+x5");
    polCyclic6.emplace_back("x0*x1+x1*x2+x2*x3+x3*x4+x0*x5+x4*x5");
    polCyclic6.emplace_back("x0*x1*x2+x1*x2*x3+x2*x3*x4+x0*x1*x5+x0*x4*x5+x3*x4*x5");
    polCyclic6.emplace_back("x0*x1*x2*x3+x1*x2*x3*x4+x0*x1*x2*x5+x0*x1*x4*x5+x0*x3*x4*x5+x2*x3*x4*x5");
    polCyclic6.emplace_back("x0*x1*x2*x3*x4+x0*x1*x2*x3*x5+x0*x1*x2*x4*x5+x0*x1*x3*x4*x5+x0*x2*x3*x4*x5+x1*x2*x3*x4*x5");
    polCyclic6.emplace_back("x0*x1*x2*x3*x4*x5-1");

    // Create cyclic6 ideal;
    Ideal<eltType> cyclic6(polCyclic6);
    
    // Compute a reduced groebner basis;
    nbGen=cyclic6.f4();

    if (file)
    {
        file << "Cyclic 6 : " << (clock()-start)*1000/CLOCKS_PER_SEC << " ms                   (" << nbGen << " generators)" << endl << endl;
    }
    
    // Free monomial tools
    Monomial::freeMonomial();
    
    
    
    cout << "#########################################################" << endl;
    cout << "#                         CYCLIC 7                      #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Time 
    start=clock();
    
    // Init monomial tools
    Monomial::initMonomial(7,13,2,12);
    
    // Create polynomial array
    vector<Polynomial<eltType>> polCyclic7;
    
    // Fill the polynomial array
    polCyclic7.emplace_back("x0+x1+x2+x3+x4+x5+x6");
    polCyclic7.emplace_back("x0*x1+x1*x2+x2*x3+x3*x4+x4*x5+x0*x6+x5*x6");
    polCyclic7.emplace_back("x0*x1*x2+x1*x2*x3+x2*x3*x4+x3*x4*x5+x0*x1*x6+x0*x5*x6+x4*x5*x6");
    polCyclic7.emplace_back("x0*x1*x2*x3+x1*x2*x3*x4+x2*x3*x4*x5+x0*x1*x2*x6+x0*x1*x5*x6+x0*x4*x5*x6+x3*x4*x5*x6");
    polCyclic7.emplace_back("x0*x1*x2*x3*x4+x1*x2*x3*x4*x5+x0*x1*x2*x3*x6+x0*x1*x2*x5*x6+x0*x1*x4*x5*x6+x0*x3*x4*x5*x6+x2*x3*x4*x5*x6");
    polCyclic7.emplace_back("x0*x1*x2*x3*x4*x5+x0*x1*x2*x3*x4*x6+x0*x1*x2*x3*x5*x6+x0*x1*x2*x4*x5*x6+x0*x1*x3*x4*x5*x6+x0*x2*x3*x4*x5*x6+x1*x2*x3*x4*x5*x6");
    polCyclic7.emplace_back("x0*x1*x2*x3*x4*x5*x6-1");

    // Create cyclic7 ideal;
    Ideal<eltType> cyclic7(polCyclic7);
    
    // Compute a reduced groebner basis;
    nbGen=cyclic7.f4();
    if (file)
    {
        file << "Cyclic 7 : " << (clock()-start)*1000/CLOCKS_PER_SEC << " ms                   (" << nbGen << " generators)" << endl << endl;
    }
    
    // Free monomial tools
    Monomial::freeMonomial();
    
    
    
    cout << "#########################################################" << endl;
    cout << "#                         CYCLIC 8                      #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Time 
    start=clock();
    
    // Init monomial tools
    Monomial::initMonomial(8,15,2,14);
    
    // Create polynomial array
    vector<Polynomial<eltType>> polCyclic8;
    
    // Fill the polynomial array
    polCyclic8.emplace_back("x0+x1+x2+x3+x4+x5+x6+x7");
    polCyclic8.emplace_back("x0*x1+x1*x2+x2*x3+x3*x4+x4*x5+x5*x6+x0*x7+x6*x7");
    polCyclic8.emplace_back("x0*x1*x2+x1*x2*x3+x2*x3*x4+x3*x4*x5+x4*x5*x6+x0*x1*x7+x0*x6*x7+x5*x6*x7");
    polCyclic8.emplace_back("x0*x1*x2*x3+x1*x2*x3*x4+x2*x3*x4*x5+x3*x4*x5*x6+x0*x1*x2*x7+x0*x1*x6*x7+x0*x5*x6*x7+x4*x5*x6*x7");
    polCyclic8.emplace_back("x0*x1*x2*x3*x4+x1*x2*x3*x4*x5+x2*x3*x4*x5*x6+x0*x1*x2*x3*x7+x0*x1*x2*x6*x7+x0*x1*x5*x6*x7+x0*x4*x5*x6*x7+x3*x4*x5*x6*x7");
    polCyclic8.emplace_back("x0*x1*x2*x3*x4*x5+x1*x2*x3*x4*x5*x6+x0*x1*x2*x3*x4*x7+x0*x1*x2*x3*x6*x7+x0*x1*x2*x5*x6*x7+x0*x1*x4*x5*x6*x7+x0*x3*x4*x5*x6*x7+x2*x3*x4*x5*x6*x7");
    polCyclic8.emplace_back("x0*x1*x2*x3*x4*x5*x6+x0*x1*x2*x3*x4*x5*x7+x0*x1*x2*x3*x4*x6*x7+x0*x1*x2*x3*x5*x6*x7+x0*x1*x2*x4*x5*x6*x7+x0*x1*x3*x4*x5*x6*x7+x0*x2*x3*x4*x5*x6*x7+x1*x2*x3*x4*x5*x6*x7");
    polCyclic8.emplace_back("x0*x1*x2*x3*x4*x5*x6*x7-1");

    // Create cyclic8 ideal;
    Ideal<eltType> cyclic8(polCyclic8);
    
    // Compute a reduced groebner basis;
    nbGen=cyclic8.f4();
    if (file)
    {
        file << "Cyclic 8 : " << (clock()-start)*1000/CLOCKS_PER_SEC << " ms                   (" << nbGen << " generators)" << endl << endl;
    }
    
    // Free monomial tools
    Monomial::freeMonomial();
    
    
    
    cout << "#########################################################" << endl;
    cout << "#                         KATSURA 9                     #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Time 
    start=clock();
    
    // Init monomial tools
    Monomial::initMonomial(9,11,2,10);
    
    // Create polynomial array
    vector<Polynomial<eltType>> polKatsura9;
    
    // Fill the polynomial array
    polKatsura9.emplace_back("x0+2*x1+2*x2+2*x3+2*x4+2*x5+2*x6+2*x7+2*x8-1");
    polKatsura9.emplace_back("x0^2+2*x1^2+2*x2^2+2*x3^2+2*x4^2+2*x5^2+2*x6^2+2*x7^2+2*x8^2-x0");
    polKatsura9.emplace_back("2*x0*x1+2*x1*x2+2*x2*x3+2*x3*x4+2*x4*x5+2*x5*x6+2*x6*x7+2*x7*x8-x1");
    polKatsura9.emplace_back("x1^2+2*x0*x2+2*x1*x3+2*x2*x4+2*x3*x5+2*x4*x6+2*x5*x7+2*x6*x8-x2");
    polKatsura9.emplace_back("2*x1*x2+2*x0*x3+2*x1*x4+2*x2*x5+2*x3*x6+2*x4*x7+2*x5*x8-x3");
    polKatsura9.emplace_back("x2^2+2*x1*x3+2*x0*x4+2*x1*x5+2*x2*x6+2*x3*x7+2*x4*x8-x4");
    polKatsura9.emplace_back("2*x2*x3+2*x1*x4+2*x0*x5+2*x1*x6+2*x2*x7+2*x3*x8-x5");
    polKatsura9.emplace_back("x3^2+2*x2*x4+2*x1*x5+2*x0*x6+2*x1*x7+2*x2*x8-x6");
    polKatsura9.emplace_back("2*x3*x4+2*x2*x5+2*x1*x6+2*x0*x7+2*x1*x8-x7");

    // Create katsura9 ideal;
    Ideal<eltType> katsura9(polKatsura9);
    
    // Compute a reduced groebner basis;
    nbGen=katsura9.f4();
    if (file)
    {
        file << "Katsura 9 : " << (clock()-start)*1000/CLOCKS_PER_SEC << " ms                   (" << nbGen << " generators)" << endl << endl;
    }
    
    // Free monomial tools
    Monomial::freeMonomial();
    
    
    
    cout << "#########################################################" << endl;
    cout << "#                         KATSURA 10                    #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Time
    start=clock();
    
    // Init monomial tools
    Monomial::initMonomial(10,12,2,11);
    
    // Create polynomial array
    vector<Polynomial<eltType>> polKatsura10;
    
    // Fill the polynomial array
    polKatsura10.emplace_back("x0+2*x1+2*x2+2*x3+2*x4+2*x5+2*x6+2*x7+2*x8+2*x9-1");
    polKatsura10.emplace_back("x0^2+2*x1^2+2*x2^2+2*x3^2+2*x4^2+2*x5^2+2*x6^2+2*x7^2+2*x8^2+2*x9^2-x0");
    polKatsura10.emplace_back("2*x0*x1+2*x1*x2+2*x2*x3+2*x3*x4+2*x4*x5+2*x5*x6+2*x6*x7+2*x7*x8+2*x8*x9-x1");
    polKatsura10.emplace_back("x1^2+2*x0*x2+2*x1*x3+2*x2*x4+2*x3*x5+2*x4*x6+2*x5*x7+2*x6*x8+2*x7*x9-x2");
    polKatsura10.emplace_back("2*x1*x2+2*x0*x3+2*x1*x4+2*x2*x5+2*x3*x6+2*x4*x7+2*x5*x8+2*x6*x9-x3");
    polKatsura10.emplace_back("x2^2+2*x1*x3+2*x0*x4+2*x1*x5+2*x2*x6+2*x3*x7+2*x4*x8+2*x5*x9-x4");
    polKatsura10.emplace_back("2*x2*x3+2*x1*x4+2*x0*x5+2*x1*x6+2*x2*x7+2*x3*x8+2*x4*x9-x5");
    polKatsura10.emplace_back("x3^2+2*x2*x4+2*x1*x5+2*x0*x6+2*x1*x7+2*x2*x8+2*x3*x9-x6");
    polKatsura10.emplace_back("2*x3*x4+2*x2*x5+2*x1*x6+2*x0*x7+2*x1*x8+2*x2*x9-x7");
    polKatsura10.emplace_back("x4^2+2*x3*x5+2*x2*x6+2*x1*x7+2*x0*x8+2*x1*x9-x8");

    // Create katsura10 ideal;
    Ideal<eltType> katsura10(polKatsura10);
    
    // Compute a reduced groebner basis;
    nbGen=katsura10.f4();
    if (file)
    {
        file << "Katsura 10 : " << (clock()-start)*1000/CLOCKS_PER_SEC << " ms                   (" << nbGen << " generators)" << endl << endl;
    }
    
    // Free monomial tools
    Monomial::freeMonomial();
    
    
    
    cout << "#########################################################" << endl;
    cout << "#                         KATSURA 11                    #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Time
    start=clock();
    
    // Init monomial tools
    Monomial::initMonomial(11,13,2,12);
    
    // Create polynomial array
    vector<Polynomial<eltType>> polKatsura11;
    
    // Fill the polynomial array
    polKatsura11.emplace_back("x0+2*x1+2*x2+2*x3+2*x4+2*x5+2*x6+2*x7+2*x8+2*x9+2*x10-1");
    polKatsura11.emplace_back("x0^2+2*x1^2+2*x2^2+2*x3^2+2*x4^2+2*x5^2+2*x6^2+2*x7^2+2*x8^2+2*x9^2+2*x10^2-x0");
    polKatsura11.emplace_back("2*x0*x1+2*x1*x2+2*x2*x3+2*x3*x4+2*x4*x5+2*x5*x6+2*x6*x7+2*x7*x8+2*x8*x9+2*x9*x10-x1");
    polKatsura11.emplace_back("x1^2+2*x0*x2+2*x1*x3+2*x2*x4+2*x3*x5+2*x4*x6+2*x5*x7+2*x6*x8+2*x7*x9+2*x8*x10-x2");
    polKatsura11.emplace_back("2*x1*x2+2*x0*x3+2*x1*x4+2*x2*x5+2*x3*x6+2*x4*x7+2*x5*x8+2*x6*x9+2*x7*x10-x3");
    polKatsura11.emplace_back("x2^2+2*x1*x3+2*x0*x4+2*x1*x5+2*x2*x6+2*x3*x7+2*x4*x8+2*x5*x9+2*x6*x10-x4");
    polKatsura11.emplace_back("2*x2*x3+2*x1*x4+2*x0*x5+2*x1*x6+2*x2*x7+2*x3*x8+2*x4*x9+2*x5*x10-x5");
    polKatsura11.emplace_back("x3^2+2*x2*x4+2*x1*x5+2*x0*x6+2*x1*x7+2*x2*x8+2*x3*x9+2*x4*x10-x6");
    polKatsura11.emplace_back("2*x3*x4+2*x2*x5+2*x1*x6+2*x0*x7+2*x1*x8+2*x2*x9+2*x3*x10-x7");
    polKatsura11.emplace_back("x4^2+2*x3*x5+2*x2*x6+2*x1*x7+2*x0*x8+2*x1*x9+2*x2*x10-x8");
    polKatsura11.emplace_back("2*x4*x5+2*x3*x6+2*x2*x7+2*x1*x8+2*x0*x9+2*x1*x10-x9");

    // Create katsura11 ideal;
    Ideal<eltType> katsura11(polKatsura11);
    
    // Compute a reduced groebner basis;
    nbGen=katsura11.f4();
    if (file)
    {
        file << "Katsura 11 : " << (clock()-start)*1000/CLOCKS_PER_SEC << " ms                   (" << nbGen << " generators)" << endl << endl;
    }
    
    // Free monomial tools
    Monomial::freeMonomial();
    
    return 0;
}

