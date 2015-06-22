/* 
 * Copyright (C) 2015 Antoine Joux, Vanessa Vitse and Titouan Coladon
 * 
 * This file is part of F4.
 * 
 * F4 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * F4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with F4.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *  \file check-cyclic6-64bits.cpp
 *  \example check-cyclic6-64bits.cpp
 *  \brief Library check tests.
 *  \ingroup examples
 *  \author Vanessa VITSE, Antoine JOUX, Titouan COLADON
 */

#include <iostream>
#include <string>
#include <vector>
#include <libf4.h>

using namespace std;

int main (int argc, char **argv)
{
    cout << "#########################################################" << endl;
    cout << "#                 CHECK CYCLIC6 64 BITS                 #" << endl;
    cout << "#########################################################" << endl << endl;
    
    // Create polynomial array
    vector<string> polynomialArray;
    
    // Create variable name array
    vector<string> variableName;
    for(int i = 0; i < 6; i++)
    {
        variableName.push_back('x'+to_string(i));
    }
    
    // Fill the polynomial array
    polynomialArray.emplace_back("x0+x1+x2+x3+x4+x5");
    polynomialArray.emplace_back("x0*x1+x1*x2+x2*x3+x3*x4+x0*x5+x4*x5");
    polynomialArray.emplace_back("x0*x1*x2+x1*x2*x3+x2*x3*x4+x0*x1*x5+x0*x4*x5+x3*x4*x5");
    polynomialArray.emplace_back("x0*x1*x2*x3+x1*x2*x3*x4+x0*x1*x2*x5+x0*x1*x4*x5+x0*x3*x4*x5+x2*x3*x4*x5");
    polynomialArray.emplace_back("x0*x1*x2*x3*x4+x0*x1*x2*x3*x5+x0*x1*x2*x4*x5+x0*x1*x3*x4*x5+x0*x2*x3*x4*x5+x1*x2*x3*x4*x5");
    polynomialArray.emplace_back("x0*x1*x2*x3*x4*x5-1");
    
    // Compute a reduce groebner basis
    vector<string> basisLong = groebnerBasisF4(4294967291LL, 6, variableName, polynomialArray, 1, 0);
    
    // Fill reference vectors
    vector<string> groebnerBasisCyclic6Long;

    groebnerBasisCyclic6Long.push_back("(1*x0^1) + (1*x1^1) + (1*x2^1) + (1*x3^1) + (1*x4^1) + (1*x5^1)");
    groebnerBasisCyclic6Long.push_back("(1*x1^2) + (1*x1^1*x3^1) + (-1*x2^1*x3^1) + (1*x1^1*x4^1) + (-1*x3^1*x4^1) + (2*x1^1*x5^1) + (1*x2^1*x5^1) + (1*x3^1*x5^1) + (1*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x2^2) + (1*x2^1*x3^2) + (2147483641*x1^1*x2^1*x4^1) + (2147483644*x2^2*x4^1) + (3*x1^1*x3^1*x4^1) + (2147483644*x2^1*x3^1*x4^1) + (4*x3^2*x4^1) + (2147483644*x2^1*x4^2) + (1*x3^1*x4^2) + (3*x1^1*x2^1*x5^1) + (1*x2^2*x5^1) + (2147483644*x1^1*x3^1*x5^1) + (-4*x2^1*x3^1*x5^1) + (-3*x3^2*x5^1) + (-2147483642*x2^1*x4^1*x5^1) + (3*x3^1*x4^1*x5^1) + (1*x4^2*x5^1) + (-1*x1^1*x5^2) + (-4*x3^1*x5^2) + (2*x4^1*x5^2) + (-1*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x2^3) + (1840700265*x2^1*x3^2) + (1840700267*x3^3) + (-1840700265*x1^1*x2^1*x4^1) + (-1227133510*x2^2*x4^1) + (613566755*x1^1*x3^1*x4^1) + (-1840700265*x2^1*x3^1*x4^1) + (-1840700271*x3^2*x4^1) + (-1840700271*x1^1*x4^2) + (-1227133510*x2^1*x4^2) + (-613566755*x3^1*x4^2) + (1840700267*x4^3) + (1227133510*x1^1*x2^1*x5^1) + (613566758*x2^2*x5^1) + (-1227133510*x1^1*x3^1*x5^1) + (-613566755*x3^2*x5^1) + (613566755*x1^1*x4^1*x5^1) + (613566755*x2^1*x4^1*x5^1) + (-1227133516*x3^1*x4^1*x5^1) + (-1840700265*x1^1*x5^2) + (-1227133513*x2^1*x5^2) + (1840700271*x3^1*x5^2) + (1227133510*x4^1*x5^2) + (1*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x2^1*x3^1) + (1*x2^1*x3^2) + (2147483643*x1^1*x2^1*x4^1) + (2147483644*x2^2*x4^1) + (1*x1^1*x3^1*x4^1) + (2147483645*x2^1*x3^1*x4^1) + (2*x3^2*x4^1) + (2147483644*x2^1*x4^2) + (1*x3^1*x4^2) + (1*x1^1*x2^1*x5^1) + (1*x2^2*x5^1) + (-2147483645*x1^1*x3^1*x5^1) + (-1*x2^1*x3^1*x5^1) + (-1*x3^2*x5^1) + (-1*x1^1*x4^1*x5^1) + (2147483645*x2^1*x4^1*x5^1) + (1*x3^1*x4^1*x5^1) + (1*x2^1*x5^2) + (-1*x3^1*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x2^2*x3^1) + (2*x1^1*x2^1*x4^1) + (-2*x1^1*x3^1*x4^1) + (1*x2^1*x3^1*x4^1) + (-2*x3^2*x4^1) + (-2*x1^1*x2^1*x5^1) + (-1*x2^2*x5^1) + (2*x1^1*x3^1*x5^1) + (3*x2^1*x3^1*x5^1) + (2*x3^2*x5^1) + (-3*x2^1*x4^1*x5^1) + (-1*x3^1*x4^1*x5^1) + (-1*x2^1*x5^2) + (2*x3^1*x5^2) + (-1*x4^1*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x3^2) + (-1840700267*x2^1*x3^2) + (-1840700267*x3^3) + (-306783378*x1^1*x2^1*x4^1) + (-920350134*x2^2*x4^1) + (-613566756*x1^1*x3^1*x4^1) + (-306783378*x2^1*x3^1*x4^1) + (1840700268*x3^2*x4^1) + (1840700266*x1^1*x4^2) + (-920350134*x2^1*x4^2) + (613566756*x3^1*x4^2) + (-1840700268*x4^3) + (-1227133512*x1^1*x2^1*x5^1) + (-613566756*x2^2*x5^1) + (-920350133*x1^1*x3^1*x5^1) + (613566757*x3^2*x5^1) + (-613566756*x1^1*x4^1*x5^1) + (1533916889*x2^1*x4^1*x5^1) + (1227133511*x3^1*x4^1*x5^1) + (1840700268*x1^1*x5^2) + (1227133511*x2^1*x5^2) + (-1840700267*x3^1*x5^2) + (-1227133512*x4^1*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x3^3) + (1997659205*x4^4) + (-466120469*x2^1*x3^2*x5^1) + (-499414795*x3^3*x5^1) + (1781246112*x1^1*x2^1*x4^1*x5^1) + (1698010317*x2^2*x4^1*x5^1) + (-1365067125*x1^1*x3^1*x4^1*x5^1) + (1298478456*x2^1*x3^1*x4^1*x5^1) + (1265184170*x3^2*x4^1*x5^1) + (466120515*x1^1*x4^2*x5^1) + (-1348419965*x2^1*x4^2*x5^1) + (499414792*x3^1*x4^2*x5^1) + (399531852*x4^3*x5^1) + (133177285*x1^1*x2^1*x5^2) + (216413080*x2^2*x5^2) + (-1248537017*x1^1*x3^1*x5^2) + (-349590353*x2^1*x3^1*x5^2) + (99882973*x3^2*x5^2) + (1464950090*x1^1*x4^1*x5^2) + (33294302*x2^1*x4^1*x5^2) + (-1448302904*x3^1*x4^1*x5^2) + (1198595525*x4^2*x5^2) + (-1231889860*x1^1*x5^3) + (-2014306363*x2^1*x5^3) + (-682533575*x3^1*x5^3) + (133177284*x4^1*x5^3) + (-2030953533*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x3^4) + (-1198595523*x4^4) + (-456607833*x2^1*x3^2*x5^1) + (2140349144*x3^3*x5^1) + (-1191461007*x1^1*x2^1*x4^1*x5^1) + (1619530862*x2^2*x4^1*x5^1) + (-285379888*x1^1*x3^1*x4^1*x5^1) + (2104676701*x2^1*x3^1*x4^1*x5^1) + (-1740817321*x3^2*x4^1*x5^1) + (456607766*x1^1*x4^2*x5^1) + (-1277074985*x2^1*x4^2*x5^1) + (-913215617*x3^1*x4^2*x5^1) + (741987692*x4^3*x5^1) + (1576723861*x1^1*x2^1*x5^2) + (-1234268008*x2^2*x5^2) + (1669472367*x1^1*x3^1*x5^2) + (-649239256*x2^1*x3^1*x5^2) + (185496917*x3^2*x5^2) + (164093422*x1^1*x4^1*x5^2) + (-1983390201*x2^1*x4^1*x5^2) + (-2076138712*x3^1*x4^1*x5^2) + (-1148654039*x4^2*x5^2) + (1904910770*x1^1*x5^3) + (-877543155*x2^1*x5^3) + (1391226970*x3^1*x5^3) + (1576723861*x4^1*x5^3) + (-499414789*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x3^2*x4^1) + (-1227133509*x2^1*x3^2*x5^1) + (-1227133510*x3^3*x5^1) + (1227133509*x1^1*x2^1*x4^1*x5^1) + (-613566758*x2^2*x4^1*x5^1) + (-1840700267*x1^1*x3^1*x4^1*x5^1) + (1227133507*x2^1*x3^1*x4^1*x5^1) + (1227133515*x3^2*x4^1*x5^1) + (1227133518*x1^1*x4^2*x5^1) + (-613566758*x2^1*x4^2*x5^1) + (1840700267*x3^1*x4^2*x5^1) + (-1227133510*x4^3*x5^1) + (613566756*x1^1*x2^1*x5^2) + (-1840700268*x2^2*x5^2) + (-613566757*x1^1*x3^1*x5^2) + (1*x2^1*x3^1*x5^2) + (1840700272*x3^2*x5^2) + (-1840700268*x1^1*x4^1*x5^2) + (-1840700274*x2^1*x4^1*x5^2) + (-613566752*x3^1*x4^1*x5^2) + (-1*x4^2*x5^2) + (1227133509*x1^1*x5^3) + (-613566755*x2^1*x5^3) + (-1227133513*x3^1*x5^3) + (613566755*x4^1*x5^3) + (-1*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x3^3*x4^1) + (-1598127364*x4^4) + (618323080*x2^1*x3^2*x5^1) + (-214034919*x3^3*x5^1) + (47563321*x1^1*x2^1*x4^1*x5^1) + (-806198175*x2^2*x4^1*x5^1) + (1460193755*x1^1*x3^1*x4^1*x5^1) + (863274174*x2^1*x3^1*x4^1*x5^1) + (-2116567492*x3^2*x4^1*x5^1) + (-618323107*x1^1*x4^2*x5^1) + (342455863*x2^1*x4^2*x5^1) + (-1626665345*x3^1*x4^2*x5^1) + (784794681*x4^3*x5^1) + (-658751908*x1^1*x2^1*x5^2) + (195009588*x2^2*x5^2) + (692046233*x1^1*x3^1*x5^2) + (1997659199*x2^1*x3^1*x5^2) + (1269940487*x3^2*x5^2) + (1343663628*x1^1*x4^1*x5^2) + (2059491523*x2^1*x4^1*x5^2) + (2140349139*x3^1*x4^1*x5^2) + (2047600684*x4^2*x5^2) + (2028575369*x1^1*x5^3) + (875164982*x2^1*x5^3) + (1650447017*x3^1*x5^3) + (-658751907*x4^1*x5^3) + (765769366*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x2^1*x4^2) + (1198595523*x4^4) + (-1384092449*x2^1*x3^2*x5^1) + (313917875*x3^3*x5^1) + (-546978117*x1^1*x2^1*x4^1*x5^1) + (-392397345*x2^2*x4^1*x5^1) + (-328186868*x1^1*x3^1*x4^1*x5^1) + (-1695632158*x2^1*x3^1*x4^1*x5^1) + (718206049*x3^2*x4^1*x5^1) + (-47563313*x1^1*x4^2*x5^1) + (356724857*x2^1*x4^2*x5^1) + (95126630*x3^1*x4^2*x5^1) + (1712279319*x4^3*x5^1) + (59454143*x1^1*x2^1*x5^2) + (-95126628*x2^2*x5^2) + (-1158166707*x1^1*x3^1*x5^2) + (-66588641*x2^1*x3^1*x5^2) + (1859725592*x3^2*x5^2) + (2085651336*x1^1*x4^1*x5^2) + (1369823455*x2^1*x4^1*x5^2) + (-1707522986*x3^1*x4^1*x5^2) + (1148654043*x4^2*x5^2) + (-64210475*x1^1*x5^3) + (-42806983*x2^1*x5^3) + (347212194*x3^1*x5^3) + (59454143*x4^1*x5^3) + (499414801*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x2^2*x4^2) + (799063682*x4^4) + (-718206047*x2^1*x3^2*x5^1) + (413800835*x3^3*x5^1) + (1816918610*x1^1*x2^1*x4^1*x5^1) + (556490777*x2^2*x4^1*x5^1) + (-2059491512*x1^1*x3^1*x4^1*x5^1) + (1051149251*x2^1*x3^1*x4^1*x5^1) + (751500370*x3^2*x4^1*x5^1) + (-713449719*x1^1*x4^2*x5^1) + (1055905578*x2^1*x4^2*x5^1) + (-4756328*x3^1*x4^2*x5^1) + (-85613967*x4^3*x5^1) + (175984263*x1^1*x2^1*x5^2) + (1436412095*x2^2*x5^2) + (-908459304*x1^1*x3^1*x5^2) + (432826159*x2^1*x3^1*x5^2) + (-737231375*x3^2*x5^2) + (-927484632*x1^1*x4^1*x5^2) + (1935826897*x2^1*x4^1*x5^2) + (1588614701*x3^1*x4^1*x5^2) + (-2097542165*x4^2*x5^2) + (-1678984997*x1^1*x5^3) + (-2073760510*x2^1*x5^3) + (-518440127*x3^1*x5^3) + (175984263*x4^1*x5^3) + (332943201*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x3^1*x4^2) + (799063682*x4^4) + (917971969*x2^1*x3^2*x5^1) + (-813332676*x3^3*x5^1) + (896568476*x1^1*x2^1*x4^1*x5^1) + (-57075978*x2^2*x4^1*x5^1) + (1110603392*x1^1*x3^1*x4^1*x5^1) + (-585028768*x2^1*x3^1*x4^1*x5^1) + (1978633881*x3^2*x4^1*x5^1) + (1229511679*x1^1*x4^2*x5^1) + (-1705144822*x2^1*x4^2*x5^1) + (1120116055*x3^1*x4^2*x5^1) + (834736168*x4^3*x5^1) + (789551019*x1^1*x2^1*x5^2) + (1743195473*x2^2*x5^2) + (1341285465*x1^1*x3^1*x5^2) + (1148654043*x2^1*x3^1*x5^2) + (-328186869*x3^2*x5^2) + (-2052357017*x1^1*x4^1*x5^2) + (-1336529136*x2^1*x4^1*x5^2) + (-456607817*x3^1*x4^1*x5^2) + (49941480*x4^2*x5^2) + (979804276*x1^1*x5^3) + (-1971499383*x2^1*x5^3) + (401910006*x3^1*x5^3) + (789551019*x4^1*x5^3) + (1764598964*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x3^1*x4^2) + (799063682*x4^4) + (304405212*x2^1*x3^2*x5^1) + (-1426899432*x3^3*x5^1) + (794307350*x1^1*x2^1*x4^1*x5^1) + (1783624290*x2^2*x4^1*x5^1) + (190253258*x1^1*x3^1*x4^1*x5^1) + (1460193752*x2^1*x3^1*x4^1*x5^1) + (1160544872*x3^2*x4^1*x5^1) + (1127250553*x1^1*x4^2*x5^1) + (-2011928199*x2^1*x4^2*x5^1) + (-822845338*x3^1*x4^2*x5^1) + (-1926314233*x4^3*x5^1) + (380506515*x1^1*x2^1*x5^2) + (-608810425*x2^2*x5^2) + (1750329970*x1^1*x3^1*x5^2) + (1864481924*x2^1*x3^1*x5^2) + (1307991147*x3^2*x5^2) + (-1541051387*x1^1*x4^1*x5^2) + (-109395625*x2^1*x4^1*x5^2) + (-47563313*x3^1*x4^1*x5^2) + (-2097542165*x4^2*x5^2) + (1593371032*x1^1*x5^3) + (2016684530*x2^1*x5^3) + (504171132*x3^1*x5^3) + (380506515*x4^1*x5^3) + (1764598964*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x4^5) + (-998829613*x4^4*x5^1) + (642104597*x2^1*x3^2*x5^2) + (-57075997*x3^3*x5^2) + (-225925475*x1^1*x2^1*x4^1*x5^2) + (71345145*x2^2*x4^1*x5^2) + (-135555547*x1^1*x3^1*x4^1*x5^2) + (-1774111357*x2^1*x3^1*x4^1*x5^2) + (390018947*x3^2*x4^1*x5^2) + (73722749*x1^1*x4^2*x5^2) + (520818463*x2^1*x4^2*x5^2) + (2000037342*x3^1*x4^2*x5^2) + (-506549446*x4^3*x5^2) + (-1702766827*x1^1*x2^1*x5^3) + (-2000037447*x2^2*x5^3) + (1902532900*x1^1*x3^1*x5^3) + (-1614774524*x2^1*x3^1*x5^3) + (-1379335920*x3^2*x5^3) + (2028575252*x1^1*x4^1*x5^3) + (1312747400*x2^1*x4^1*x5^3) + (2002415181*x3^1*x4^1*x5^3) + (1548185775*x4^2*x5^3) + (-1940583052*x1^1*x5^4) + (-577894194*x2^1*x5^4) + (1824053456*x3^1*x5^4) + (-1702766828*x4^1*x5^4) + (299649019*x5^5)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x3^2*x5^3) + (954437176*x3^3*x5^3) + (954437174*x1^1*x2^1*x4^1*x5^3) + (-2147483645*x2^2*x4^1*x5^3) + (238609290*x1^1*x3^1*x4^1*x5^3) + (-238609300*x2^1*x3^1*x4^1*x5^3) + (-715827884*x3^2*x4^1*x5^3) + (1431655765*x1^1*x4^2*x5^3) + (-2147483645*x2^1*x4^2*x5^3) + (1908874345*x3^1*x4^2*x5^3) + (954437176*x4^3*x5^3) + (1670265061*x1^1*x2^1*x5^4) + (477218589*x2^2*x5^4) + (715827880*x1^1*x3^1*x5^4) + (-2147483642*x2^1*x3^1*x5^4) + (-1431655764*x3^2*x5^4) + (-715827878*x1^1*x4^1*x5^4) + (1908874355*x2^1*x4^1*x5^4) + (-477218587*x3^1*x4^1*x5^4) + (-1*x1^1*x5^5) + (1908874354*x2^1*x5^5) + (-1431655765*x3^1*x5^5) + (1670265061*x4^1*x5^5) + (-1670265058*x5^6) + (-1670265058*1)");
    groebnerBasisCyclic6Long.push_back("(1*x4^4*x5^3) + (-925619704*x1^1*x3^1*x4^1*x5^4) + (-347531325*x2^1*x3^1*x4^1*x5^4) + (231809272*x3^2*x4^1*x5^4) + (-1407707859*x1^1*x4^2*x5^4) + (-1248394433*x2^1*x4^2*x5^4) + (1295690180*x3^1*x4^2*x5^4) + (1659447643*x4^3*x5^4) + (-27808756*x1^1*x2^1*x5^5) + (-27808756*x2^2*x5^5) + (-28278375*x1^1*x3^1*x5^5) + (-344192157*x2^1*x3^1*x5^5) + (-895723998*x3^2*x5^5) + (-581636219*x1^1*x4^1*x5^5) + (-15965212*x2^1*x4^1*x5^5) + (298644244*x3^1*x4^1*x5^5) + (-897628340*x4^2*x5^5) + (1173837710*x1^1*x5^6) + (41321834*x2^1*x5^6) + (1874822073*x3^1*x5^6) + (796515064*x4^1*x5^6) + (1061898305*x5^7) + (1797213203*x1^1) + (1831335025*x2^1) + (-184226549*x3^1) + (-1108672346*x4^1) + (273626766*x5^1)");
    groebnerBasisCyclic6Long.push_back("(1*x3^3*x5^4) + (-1180255133*x1^1*x3^1*x4^1*x5^4) + (1418012237*x2^1*x3^1*x4^1*x5^4) + (-868463054*x3^2*x4^1*x5^4) + (1471229779*x1^1*x4^2*x5^4) + (2066287790*x2^1*x4^2*x5^4) + (-116295967*x3^1*x4^2*x5^4) + (1963257094*x4^3*x5^4) + (78808900*x1^1*x2^1*x5^5) + (78808900*x2^2*x5^5) + (1776369655*x1^1*x3^1*x5^5) + (-1228463938*x2^1*x3^1*x5^5) + (979202456*x3^2*x5^5) + (-390366185*x1^1*x4^1*x5^5) + (-1338733771*x2^1*x4^1*x5^5) + (535618738*x3^1*x4^1*x5^5) + (2077479114*x4^2*x5^5) + (-1444034061*x1^1*x5^6) + (-135235120*x2^1*x5^6) + (1453621035*x3^1*x5^6) + (-1966191876*x4^1*x5^6) + (-1266811874*x5^7) + (-311752955*x1^1) + (-545440498*x2^1) + (2079318257*x3^1) + (413257558*x4^1) + (-1304259791*x5^1)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x2^1*x4^1*x5^4) + (1687465103*x1^1*x3^1*x4^1*x5^4) + (-629062438*x2^1*x3^1*x4^1*x5^4) + (550488342*x3^2*x4^1*x5^4) + (-2125414023*x1^1*x4^2*x5^4) + (-196043970*x2^1*x4^2*x5^4) + (1741465251*x3^1*x4^2*x5^4) + (-1628769299*x4^3*x5^4) + (-2032752929*x1^1*x2^1*x5^5) + (-2032752928*x2^2*x5^5) + (-390992277*x1^1*x3^1*x5^5) + (819706396*x2^1*x3^1*x5^5) + (1672908544*x3^2*x5^5) + (642992909*x1^1*x4^1*x5^5) + (2132770551*x2^1*x4^1*x5^5) + (-482714254*x3^1*x4^1*x5^5) + (-378079205*x4^2*x5^5) + (-644636398*x1^1*x5^6) + (-593531925*x2^1*x5^6) + (-1598717052*x3^1*x5^6) + (1000724241*x4^1*x5^6) + (1203185626*x5^7) + (-1431629677*x1^1) + (957837184*x2^1) + (-843497767*x3^1) + (-39208794*x4^1) + (-1656708503*x5^1)");
    groebnerBasisCyclic6Long.push_back("(1*x2^2*x4^1*x5^4) + (1864773369*x1^1*x3^1*x4^1*x5^4) + (1574268292*x2^1*x3^1*x4^1*x5^4) + (1005279040*x3^2*x4^1*x5^4) + (-440484583*x1^1*x4^2*x5^4) + (-2004187633*x2^1*x4^2*x5^4) + (997171191*x3^1*x4^2*x5^4) + (-230838840*x4^3*x5^4) + (189610912*x1^1*x2^1*x5^5) + (189610911*x2^2*x5^5) + (1528845571*x1^1*x3^1*x5^5) + (-1029508666*x2^1*x3^1*x5^5) + (-650130326*x3^2*x5^5) + (-996357278*x1^1*x4^1*x5^5) + (1295815427*x2^1*x4^1*x5^5) + (368265271*x3^1*x4^1*x5^5) + (-2114598346*x4^2*x5^5) + (-867023044*x1^1*x5^6) + (1117943674*x2^1*x5^6) + (-26483545*x3^1*x5^6) + (-1704479054*x4^1*x5^6) + (826530768*x5^7) + (-1279364947*x1^1) + (-385498358*x2^1) + (438230664*x3^1) + (-1259830985*x4^1) + (1592440514*x5^1)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x3^1*x4^1*x5^5) + (1683290832*x4^3*x5^5) + (485062860*x2^1*x3^1*x5^6) + (-247769641*x3^2*x5^6) + (284425752*x1^1*x4^1*x5^6) + (-339329140*x2^1*x4^1*x5^6) + (-129774420*x3^1*x4^1*x5^6) + (-1187843008*x4^2*x5^6) + (-330369794*x1^1*x5^7) + (-1276966522*x2^1*x5^7) + (66485505*x3^1*x5^7) + (-1873137503*x4^1*x5^7) + (-354693991*x5^8) + (-1557098296*x1^1*x2^1) + (-1557098296*x2^2) + (911781129*x1^1*x3^1) + (60239119*x2^1*x3^1) + (-1944797375*x3^2) + (895438466*x1^1*x4^1) + (-704240061*x2^1*x4^1) + (-2130438165*x3^1*x4^1) + (1875102645*x4^2) + (-204177258*x1^1*x5^1) + (1398906147*x2^1*x5^1) + (556310489*x3^1*x5^1) + (-1323399698*x4^1*x5^1) + (-1645844359*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x3^1*x4^1*x5^5) + (1017051085*x4^3*x5^5) + (2105593648*x2^1*x3^1*x5^6) + (493068675*x3^2*x5^6) + (-1150597341*x1^1*x4^1*x5^6) + (-182981141*x2^1*x4^1*x5^6) + (1627685383*x3^1*x4^1*x5^6) + (-504341395*x4^2*x5^6) + (-1004961187*x1^1*x5^7) + (526903866*x2^1*x5^7) + (1643136023*x3^1*x5^7) + (-1407958971*x4^1*x5^7) + (225535626*x5^8) + (401900780*x1^1*x2^1) + (401900780*x2^2) + (-1060659726*x1^1*x3^1) + (-1360276025*x2^1*x3^1) + (-149651831*x3^2) + (-1894640495*x1^1*x4^1) + (398170478*x2^1*x4^1) + (1900693313*x3^1*x4^1) + (-1849478079*x4^2) + (413990678*x1^1*x5^1) + (-281708487*x2^1*x5^1) + (812462050*x3^1*x5^1) + (1808388348*x4^1*x5^1) + (1365741235*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x3^2*x4^1*x5^5) + (597555237*x4^3*x5^5) + (1187695136*x2^1*x3^1*x5^6) + (2056398085*x3^2*x5^6) + (2121910977*x1^1*x4^1*x5^6) + (1812595996*x2^1*x4^1*x5^6) + (-1684616852*x3^1*x4^1*x5^6) + (852729969*x4^2*x5^6) + (174978938*x1^1*x5^7) + (-1799550986*x2^1*x5^7) + (-2116508561*x3^1*x5^7) + (570342973*x4^1*x5^7) + (-1517938974*x5^8) + (-1865509575*x1^1*x2^1) + (-1865509575*x2^2) + (-1331622743*x1^1*x3^1) + (-860140594*x2^1*x3^1) + (136666031*x3^2) + (1993217802*x1^1*x4^1) + (-264864047*x2^1*x4^1) + (-1215754790*x3^1*x4^1) + (141467270*x4^2) + (-1092975399*x1^1*x5^1) + (-1377296939*x2^1*x5^1) + (1908302999*x3^1*x5^1) + (270562929*x4^1*x5^1) + (-1127102599*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x4^2*x5^5) + (-2101121601*x4^3*x5^5) + (908978910*x2^1*x3^1*x5^6) + (-2004180921*x3^2*x5^6) + (851133876*x1^1*x4^1*x5^6) + (1458837549*x2^1*x4^1*x5^6) + (153053214*x3^1*x4^1*x5^6) + (1106673334*x4^2*x5^6) + (-541918276*x1^1*x5^7) + (1092704541*x2^1*x5^7) + (-50978270*x3^1*x5^7) + (-896104537*x4^1*x5^7) + (674959643*x5^8) + (-1663442483*x1^1*x2^1) + (-1663442483*x2^2) + (189869606*x1^1*x3^1) + (1304822917*x2^1*x3^1) + (1586457940*x3^2) + (1175872345*x1^1*x4^1) + (965918147*x2^1*x4^1) + (-1623329919*x3^1*x4^1) + (127342720*x4^2) + (-11515069*x1^1*x5^1) + (-2131654931*x2^1*x5^1) + (1741658909*x3^1*x5^1) + (7769232*x4^1*x5^1) + (-658364394*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x4^2*x5^5) + (515758230*x4^3*x5^5) + (709596647*x2^1*x3^1*x5^6) + (104923197*x3^2*x5^6) + (-174615908*x1^1*x4^1*x5^6) + (312817571*x2^1*x4^1*x5^6) + (-26835334*x3^1*x4^1*x5^6) + (126120584*x4^2*x5^6) + (1075347090*x1^1*x5^7) + (1808375477*x2^1*x5^7) + (1918191686*x3^1*x5^7) + (-580767905*x4^1*x5^7) + (-179259938*x5^8) + (-1403956732*x1^1*x2^1) + (-1403956732*x2^2) + (-2014123347*x1^1*x3^1) + (2017866334*x2^1*x3^1) + (-268470775*x3^2) + (-1964766982*x1^1*x4^1) + (-343602006*x2^1*x4^1) + (-1301228178*x3^1*x4^1) + (256638171*x4^2) + (187148588*x1^1*x5^1) + (-126989638*x2^1*x5^1) + (-1957658120*x3^1*x5^1) + (-2126339684*x4^1*x5^1) + (544820412*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x3^1*x4^2*x5^5) + (1196255216*x4^3*x5^5) + (79866895*x2^1*x3^1*x5^6) + (1846089070*x3^2*x5^6) + (348093311*x1^1*x4^1*x5^6) + (-2053860903*x2^1*x4^1*x5^6) + (1719713246*x3^1*x4^1*x5^6) + (-1675731860*x4^2*x5^6) + (1905441952*x1^1*x5^7) + (1093441521*x2^1*x5^7) + (987156409*x3^1*x5^7) + (101438208*x4^1*x5^7) + (-119392759*x5^8) + (-1244745926*x1^1*x2^1) + (-1244745926*x2^2) + (-534133845*x1^1*x3^1) + (-1171143890*x2^1*x3^1) + (-1692620139*x3^2) + (1963360558*x1^1*x4^1) + (1942968881*x2^1*x4^1) + (236268418*x3^1*x4^1) + (-1522924340*x4^2) + (1856951241*x1^1*x5^1) + (669457009*x2^1*x5^1) + (-703851510*x3^1*x5^1) + (-636696433*x4^1*x5^1) + (948312886*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x2^1*x5^6) + (-1894535088*x2^1*x3^1*x5^6) + (-1894535089*x3^2*x5^6) + (-2019967814*x1^1*x4^1*x5^6) + (380464388*x2^1*x4^1*x5^6) + (-1514070701*x3^1*x4^1*x5^6) + (380464388*x4^2*x5^6) + (1839332785*x1^1*x5^7) + (1112328879*x2^1*x5^7) + (-55202304*x3^1*x5^7) + (380464388*x4^1*x5^7) + (-1461645874*x5^8) + (-133913940*x1^1*x2^1) + (-133913939*x2^2) + (537044505*x1^1*x3^1) + (-2028449029*x2^1*x3^1) + (-1894535089*x3^2) + (-1927914381*x1^1*x4^1) + (472517821*x2^1*x4^1) + (-1422017268*x3^1*x4^1) + (472517821*x4^2) + (1705418844*x1^1*x5^1) + (1555931212*x2^1*x5^1) + (-189116245*x3^1*x5^1) + (472517821*x4^1*x5^1) + (-1329120674*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x2^2*x5^6) + (208905748*x2^1*x3^1*x5^6) + (208905748*x3^2*x5^6) + (-1862792524*x1^1*x4^1*x5^6) + (-1653886776*x2^1*x4^1*x5^6) + (-1444981028*x3^1*x4^1*x5^6) + (-1653886776*x4^2*x5^6) + (-1171598194*x1^1*x5^7) + (1871124948*x2^1*x5^7) + (-962692446*x3^1*x5^7) + (-1653886776*x4^1*x5^7) + (1900387625*x5^8) + (142047971*x1^1*x2^1) + (142047970*x2^2) + (-1759530000*x1^1*x3^1) + (350953719*x2^1*x3^1) + (208905748*x3^2) + (1386455679*x1^1*x4^1) + (1595361427*x2^1*x4^1) + (1804267175*x3^1*x4^1) + (1595361427*x4^2) + (-1029550223*x1^1*x5^1) + (-1946315153*x2^1*x5^1) + (-820644475*x3^1*x5^1) + (1595361427*x4^1*x5^1) + (-1345289533*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x3^1*x5^6) + (1462241047*x2^1*x3^1*x5^6) + (1462241047*x3^2*x5^6) + (278590596*x1^1*x4^1*x5^6) + (1740831643*x2^1*x4^1*x5^6) + (-1091894601*x3^1*x4^1*x5^6) + (1740831643*x4^2*x5^6) + (-26733191*x1^1*x5^7) + (159060004*x2^1*x5^7) + (1435507856*x3^1*x5^7) + (1740831643*x4^1*x5^7) + (110999778*x5^8) + (1120710898*x1^1*x2^1) + (1120710898*x2^2) + (640406228*x1^1*x3^1) + (-1712015346*x2^1*x3^1) + (1462241047*x3^2) + (1188015052*x1^1*x4^1) + (-1644711192*x2^1*x4^1) + (-182470145*x3^1*x4^1) + (-1644711192*x4^2) + (1093977707*x1^1*x5^1) + (-938240753*x2^1*x5^1) + (-1738748537*x3^1*x5^1) + (-1644711192*x4^1*x5^1) + (-1837993648*x5^2)");
    groebnerBasisCyclic6Long.push_back("(1*x4^3*x5^6) + (754326188*x4^1*x5^8) + (993565504*x2^1*x3^2) + (-1049250737*x3^3) + (96417887*x1^1*x2^1*x4^1) + (-982995600*x2^2*x4^1) + (-1638842165*x1^1*x3^1*x4^1) + (-1933766379*x2^1*x3^1*x4^1) + (-2116032240*x3^2*x4^1) + (1628529739*x1^1*x4^2) + (-1392641539*x2^1*x4^2) + (1454771822*x3^1*x4^2) + (-1552736377*x4^3) + (961340404*x1^1*x2^1*x5^1) + (2040753891*x2^2*x5^1) + (-2139749407*x1^1*x3^1*x5^1) + (-949223798*x2^1*x3^1*x5^1) + (316064356*x3^2*x5^1) + (351640726*x1^1*x4^1*x5^1) + (-178914057*x2^1*x4^1*x5^1) + (453471840*x3^1*x4^1*x5^1) + (1230742652*x4^2*x5^1) + (740662816*x1^1*x5^2) + (-1955679440*x2^1*x5^2) + (-1579805275*x3^1*x5^2) + (-99769133*x4^1*x5^2) + (-2042816261*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x3^1*x5^7) + (1882206254*x4^1*x5^8) + (1486396123*x2^1*x3^2) + (-1326386868*x3^3) + (-1503239616*x1^1*x2^1*x4^1) + (-1699039635*x2^2*x4^1) + (-1564293786*x1^1*x3^1*x4^1) + (1854836009*x2^1*x3^1*x4^1) + (353704438*x3^2*x4^1) + (-288435991*x1^1*x4^2) + (-1174800991*x2^1*x4^2) + (920050114*x3^1*x4^2) + (-625296622*x4^3) + (1244277626*x1^1*x2^1*x5^1) + (1440077645*x2^2*x5^1) + (2105375775*x1^1*x3^1*x5^1) + (1183221092*x2^1*x3^1*x5^1) + (450550173*x3^2*x5^1) + (-1103217064*x1^1*x4^1*x5^1) + (-433707930*x2^1*x4^1*x5^1) + (1265332324*x3^1*x4^1*x5^1) + (-997947866*x4^2*x5^1) + (1109533056*x1^1*x5^2) + (602137017*x2^1*x5^2) + (1490605816*x3^1*x5^2) + (435813188*x4^1*x5^2) + (1482184300*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x3^2*x5^7) + (-34287554*x4^1*x5^8) + (-630838830*x2^1*x3^2) + (47693306*x3^3) + (-1436039497*x1^1*x2^1*x4^1) + (-1614738711*x2^2*x4^1) + (1538686919*x1^1*x3^1*x4^1) + (120435747*x2^1*x3^1*x4^1) + (746937197*x3^2*x4^1) + (-1408066407*x1^1*x4^2) + (1820332803*x2^1*x4^2) + (1723444505*x3^1*x4^2) + (-1198388595*x4^3) + (-401610892*x1^1*x2^1*x5^1) + (-222911678*x2^2*x5^1) + (1333690970*x1^1*x3^1*x5^1) + (498673061*x2^1*x3^1*x5^1) + (1222063087*x3^2*x5^1) + (-1447639410*x1^1*x4^1*x5^1) + (-382319587*x2^1*x4^1*x5^1) + (-53148672*x3^1*x4^1*x5^1) + (-55942405*x4^2*x5^1) + (1820978317*x1^1*x5^2) + (1650700221*x2^1*x5^2) + (-1034470611*x3^1*x5^2) + (1013201863*x4^1*x5^2) + (678532143*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x4^1*x5^7) + (-911327093*x4^1*x5^8) + (-157688449*x2^1*x3^2) + (395724768*x3^3) + (-299478879*x1^1*x2^1*x4^1) + (-1534561268*x2^2*x4^1) + (-798968858*x1^1*x3^1*x4^1) + (1548740495*x2^1*x3^1*x4^1) + (455448543*x3^2*x4^1) + (180245907*x1^1*x4^2) + (1267092854*x2^1*x4^2) + (850099231*x3^1*x4^2) + (-285514784*x4^3) + (-480584370*x1^1*x2^1*x5^1) + (754498019*x2^2*x5^1) + (-1683441489*x1^1*x3^1*x5^1) + (-45115156*x2^1*x3^1*x5^1) + (-1437241391*x3^2*x5^1) + (-1808045473*x1^1*x4^1*x5^1) + (360491954*x2^1*x4^1*x5^1) + (901659359*x3^1*x4^1*x5^1) + (-243622151*x4^2*x5^1) + (595305870*x1^1*x5^2) + (-1018744154*x2^1*x5^2) + (-1730705014*x3^1*x5^2) + (277351036*x4^1*x5^2) + (553413201*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x4^1*x5^7) + (936591607*x4^1*x5^8) + (-1756399296*x2^1*x3^2) + (957731300*x3^3) + (-68661036*x1^1*x2^1*x4^1) + (366979947*x2^2*x4^1) + (-211010256*x1^1*x3^1*x4^1) + (-1895826740*x2^1*x3^1*x4^1) + (1147043274*x3^2*x4^1) + (-493646264*x1^1*x4^2) + (-1461990356*x2^1*x4^2) + (1448369882*x3^1*x4^2) + (-268499905*x4^3) + (-1989924180*x1^1*x2^1*x5^1) + (1869402128*x2^2*x5^1) + (1960148158*x1^1*x3^1*x5^1) + (920951667*x2^1*x3^1*x5^1) + (1053461473*x3^2*x5^1) + (1265459945*x1^1*x4^1*x5^1) + (158032092*x2^1*x4^1*x5^1) + (170879182*x3^1*x4^1*x5^1) + (849970423*x4^2*x5^1) + (-462366367*x1^1*x5^2) + (-2140523016*x2^1*x5^2) + (-149696522*x3^1*x5^2) + (-625640446*x4^1*x5^2) + (-1580836695*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x3^1*x4^1*x5^7) + (1398571282*x4^1*x5^8) + (349320620*x2^1*x3^2) + (24491114*x3^3) + (-547827577*x1^1*x2^1*x4^1) + (842365152*x2^2*x4^1) + (-242977515*x1^1*x3^1*x4^1) + (-967398857*x2^1*x3^1*x4^1) + (1319942062*x3^2*x4^1) + (232665572*x1^1*x4^2) + (-1607390348*x2^1*x4^2) + (703152779*x3^1*x4^2) + (1346366553*x4^3) + (-1293517294*x1^1*x2^1*x5^1) + (1611257268*x2^2*x5^1) + (7734030*x1^1*x3^1*x5^1) + (983511361*x2^1*x3^1*x5^1) + (960309275*x3^2*x5^1) + (781137509*x1^1*x4^1*x5^1) + (465331027*x2^1*x4^1*x5^1) + (-727643637*x3^1*x4^1*x5^1) + (-1560985937*x4^2*x5^1) + (1062785275*x1^1*x5^2) + (-452441125*x2^1*x5^2) + (-291315346*x3^1*x5^2) + (222353537*x4^1*x5^2) + (-324829490*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x4^2*x5^7) + (-1423835795*x4^1*x5^8) + (-684977372*x2^1*x3^2) + (-764380392*x3^3) + (1018228067*x1^1*x2^1*x4^1) + (631998952*x2^2*x4^1) + (1457479240*x1^1*x3^1*x4^1) + (-14909658*x2^1*x3^1*x4^1) + (-2104344228*x3^2*x4^1) + (-532831766*x1^1*x4^2) + (2109070633*x2^1*x4^2) + (-342832144*x3^1*x4^2) + (-178785074*x4^3) + (-121896816*x1^1*x2^1*x5^1) + (264332299*x2^2*x5^1) + (-1409313195*x1^1*x3^1*x5^1) + (1003963448*x2^1*x3^1*x5^1) + (-781051781*x3^2*x5^1) + (-1465685480*x1^1*x4^1*x5^1) + (1368150567*x2^1*x4^1*x5^1) + (677717002*x3^1*x4^1*x5^1) + (954637944*x4^2*x5^1) + (1054019950*x1^1*x5^2) + (-1092303865*x2^1*x5^2) + (-78028105*x3^1*x5^2) + (534980552*x4^1*x5^2) + (-79402984*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x5^8) + (-137150216*x4^1*x5^8) + (1771607386*x2^1*x3^2) + (190772531*x3^3) + (698301476*x1^1*x2^1*x4^1) + (2130988668*x2^2*x4^1) + (-287708636*x1^1*x3^1*x4^1) + (481745703*x2^1*x3^1*x4^1) + (-1307228477*x3^2*x4^1) + (810181167*x1^1*x4^2) + (838889204*x2^1*x4^2) + (451320872*x3^1*x4^2) + (1648895867*x4^3) + (541037493*x1^1*x2^1*x5^1) + (-891649699*x2^2*x5^1) + (-1107684507*x1^1*x3^1*x5^1) + (1994694661*x2^1*x3^1*x5^1) + (593287560*x3^2*x5^1) + (-1495590501*x1^1*x4^1*x5^1) + (618209083*x2^1*x4^1*x5^1) + (1934878848*x3^1*x4^1*x5^1) + (-223773090*x4^2*x5^1) + (841463507*x1^1*x5^2) + (-1987129130*x2^1*x5^2) + (157088527*x3^1*x5^2) + (1905321159*x4^1*x5^2) + (-1580834875*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x5^8) + (818086815*x2^1*x3^2) + (-613567089*x3^3) + (-818084940*x1^1*x2^1*x4^1) + (1840704519*x2^2*x4^1) + (-1636180576*x1^1*x3^1*x4^1) + (2045223833*x2^1*x3^1*x4^1) + (2045217763*x3^2*x4^1) + (613564757*x1^1*x4^2) + (1840704519*x2^1*x4^2) + (204519314*x3^1*x4^2) + (-613567089*x4^3) + (-1124873631*x1^1*x2^1*x5^1) + (511304201*x2^2*x5^1) + (-1738437903*x1^1*x3^1*x5^1) + (715829020*x2^1*x3^1*x5^1) + (1636179209*x3^2*x5^1) + (-920350209*x1^1*x4^1*x5^1) + (511307426*x2^1*x4^1*x5^1) + (-1738443970*x3^1*x4^1*x5^1) + (2147482006*x4^2*x5^1) + (1329395211*x1^1*x5^2) + (1124874546*x2^1*x5^2) + (-1329392871*x3^1*x5^2) + (-1124873651*x4^1*x5^2) + (-1431653920*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x3^1*x5^8) + (137150216*x4^1*x5^8) + (1909788803*x2^1*x3^2) + (-804339949*x3^3) + (2062756976*x1^1*x2^1*x4^1) + (1857203655*x2^2*x4^1) + (1514837084*x1^1*x3^1*x4^1) + (-2015659979*x2^1*x3^1*x4^1) + (1920785818*x3^2*x4^1) + (-196618384*x1^1*x4^2) + (-1145664172*x2^1*x4^2) + (-1678460180*x3^1*x4^2) + (2032504006*x4^3) + (-234256591*x1^1*x2^1*x5^1) + (-28703270*x2^2*x5^1) + (-1346580051*x1^1*x3^1*x5^1) + (152791223*x2^1*x3^1*x5^1) + (-1820418712*x3^2*x5^1) + (575240219*x1^1*x4^1*x5^1) + (608927981*x2^1*x4^1*x5^1) + (2053295507*x3^1*x4^1*x5^1) + (-1923713786*x4^2*x5^1) + (1919588038*x1^1*x5^2) + (1680350008*x2^1*x5^2) + (1376831866*x3^1*x5^2) + (-1598540284*x4^1*x5^2) + (1580838539*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x5^9) + (1840708530*x2^1*x3^2) + (1840701517*x3^3) + (306768021*x1^1*x2^1*x4^1) + (920334068*x2^2*x4^1) + (613576430*x1^1*x3^1*x4^1) + (306778461*x2^1*x3^1*x4^1) + (-1840682310*x3^2*x4^1) + (-1840692771*x1^1*x4^2) + (920334068*x2^1*x4^2) + (-613555607*x3^1*x4^2) + (1840701517*x4^3) + (-920345463*x1^1*x2^1*x5^1) + (-1533911510*x2^2*x5^1) + (-1227138144*x1^1*x3^1*x5^1) + (2147479309*x2^1*x3^1*x5^1) + (-613571270*x3^2*x5^1) + (-1533916604*x1^1*x4^1*x5^1) + (613559962*x2^1*x4^1*x5^1) + (920368356*x3^1*x4^1*x5^1) + (-2147477413*x4^2*x5^1) + (306781240*x1^1*x5^2) + (920341926*x2^1*x5^2) + (-306790030*x3^1*x5^2) + (-920345355*x4^1*x5^2) + (-6929*x5^3)");
    groebnerBasisCyclic6Long.push_back("(1*x3^2*x4^2) + (799063682*x4^4) + (-309161545*x2^1*x3^2*x5^1) + (-2040466189*x3^3*x5^1) + (-23781656*x1^1*x2^1*x4^1*x5^1) + (-670642733*x2^2*x4^1*x5^1) + (1417386768*x1^1*x3^1*x4^1*x5^1) + (642104747*x2^1*x3^1*x4^1*x5^1) + (-1089199902*x3^2*x4^1*x5^1) + (309161542*x1^1*x4^2*x5^1) + (-171227930*x2^1*x4^2*x5^1) + (813332680*x3^1*x4^2*x5^1) + (1755086302*x4^3*x5^1) + (1403117774*x1^1*x2^1*x5^2) + (2049978851*x2^2*x5^2) + (727718713*x1^1*x3^1*x5^2) + (-998829604*x2^1*x3^1*x5^2) + (1512513396*x3^2*x5^2) + (-1745573640*x1^1*x4^1*x5^2) + (1117737888*x2^1*x4^1*x5^2) + (-1070174577*x3^1*x4^1*x5^2) + (-2097542163*x4^2*x5^2) + (-2088029501*x1^1*x5^3) + (-437582493*x2^1*x5^3) + (1322260141*x3^1*x5^3) + (1403117774*x4^1*x5^3) + (1764598965*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x1^1*x4^3) + (-499414801*x4^4) + (-599297762*x2^1*x3^2*x5^1) + (1198595523*x3^3*x5^1) + (-982182442*x1^1*x2^1*x4^1*x5^1) + (-1498244404*x2^2*x4^1*x5^1) + (-1448302923*x1^1*x3^1*x4^1*x5^1) + (1464950086*x2^1*x3^1*x4^1*x5^1) + (1831187605*x3^2*x4^1*x5^1) + (1315125642*x1^1*x4^2*x5^1) + (1947717725*x2^1*x4^2*x5^1) + (-482767639*x3^1*x4^2*x5^1) + (2047600685*x4^3*x5^1) + (-33294321*x1^1*x2^1*x5^2) + (482767641*x2^2*x5^2) + (133177281*x1^1*x3^1*x5^2) + (982182441*x2^1*x3^1*x5^2) + (332943201*x3^2*x5^2) + (-1082065404*x1^1*x4^1*x5^2) + (-1797893285*x2^1*x4^1*x5^2) + (-1964364886*x3^1*x4^1*x5^2) + (1847834765*x4^2*x5^2) + (2097542166*x1^1*x5^3) + (-749122203*x2^1*x5^3) + (1781246125*x3^1*x5^3) + (-33294321*x4^1*x5^3) + (-1997659205*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x2^1*x4^3) + (-99882960*x4^4) + (-242572905*x2^1*x3^2*x5^1) + (-741987705*x3^3*x5^1) + (2073760511*x1^1*x2^1*x4^1*x5^1) + (-1219999013*x2^2*x4^1*x5^1) + (385262845*x1^1*x3^1*x4^1*x5^1) + (-872786817*x2^1*x3^1*x4^1*x5^1) + (-2088029505*x3^2*x4^1*x5^1) + (1674228665*x1^1*x4^2*x5^1) + (328186872*x2^1*x4^2*x5^1) + (946509958*x3^1*x4^2*x5^1) + (-142689943*x4^3*x5^1) + (54697809*x1^1*x2^1*x5^2) + (-946509958*x2^2*x5^2) + (-1752708132*x1^1*x3^1*x5^2) + (-233060241*x2^1*x3^1*x5^2) + (680155398*x3^2*x5^2) + (-829979838*x1^1*x4^1*x5^2) + (-114151958*x2^1*x4^1*x5^2) + (1693253989*x3^1*x4^1*x5^2) + (-1348419963*x4^2*x5^2) + (-1605261860*x1^1*x5^3) + (-1070174574*x2^1*x5^3) + (1522026064*x3^1*x5^3) + (54697809*x4^1*x5^3) + (-399531840*x5^4)");
    groebnerBasisCyclic6Long.push_back("(1*x3^1*x4^3) + (699180722*x4^4) + (1084443568*x2^1*x3^2*x5^1) + (285379886*x3^3*x5^1) + (1845456600*x1^1*x2^1*x4^1*x5^1) + (-356724858*x2^2*x4^1*x5^1) + (-1469706413*x1^1*x3^1*x4^1*x5^1) + (-1151032205*x2^1*x3^1*x4^1*x5^1) + (-518440126*x3^2*x4^1*x5^1) + (347212191*x1^1*x4^2*x5^1) + (-456607820*x2^1*x4^2*x5^1) + (-694424388*x3^1*x4^2*x5^1) + (385262846*x4^3*x5^1) + (-1507757068*x1^1*x2^1*x5^2) + (694424390*x2^2*x5^2) + (508927466*x1^1*x3^1*x5^2) + (-1231889845*x2^1*x3^1*x5^2) + (-261598230*x3^2*x5^2) + (-837114335*x1^1*x4^1*x5^2) + (2026197194*x2^1*x4^1*x5^2) + (9512661*x3^1*x4^1*x5^2) + (-1298478484*x4^2*x5^2) + (1112981559*x1^1*x5^3) + (741987704*x2^1*x5^3) + (-1246158836*x3^1*x5^3) + (-1507757068*x4^1*x5^3) + (-1498244403*x5^4)");

    /* 64 bits */
    bool testCyclic6 = true;
    size_t i = 0;
    while(i < basisLong.size() && testCyclic6 == true )
    {
        testCyclic6 = testCyclic6 && (groebnerBasisCyclic6Long[i].compare(basisLong[i])==0);
        i++;
    }
    if(testCyclic6==true)
    {
        cout << "Test cyclic6 64 bits pass" << endl;
        return 0;
    }
    else
    {
        cout << "Test cyclic6 64 bits failed" << endl;
        return -1;
    }
}


