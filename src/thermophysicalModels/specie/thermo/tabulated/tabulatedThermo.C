/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2012 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "tabulatedThermo.H"
#include "IOstreams.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class equationOfState>
Foam::tabulatedThermo<equationOfState>::tabulatedThermo(Istream& is)
:
    equationOfState(is),
    cpTable_(readScalar(is)),
    hTable(readScalar(is))
{
    is.check("tabulatedThermo::tabulatedThermo(Istream& is)");
}


template<class equationOfState>
Foam::tabulatedThermo<equationOfState>::tabulatedThermo(const dictionary& dict)
:
    equationOfState(dict),
    cpTable_ ("constant/cp"),   
    hTable ("constant/h")  
{
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class equationOfState>
void Foam::tabulatedThermo<equationOfState>::write(Ostream& os) const
{
    equationOfState::write(os);

    dictionary dict("thermodynamics");
    os  << indent << dict.dictName() << dict;
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class equationOfState>
Foam::Ostream& Foam::operator<<
(
    Ostream& os,
    const tabulatedThermo<equationOfState>& ct
)
{
    os  << static_cast<const equationOfState&>(ct) << tab
        << ct.cpTable << tab << ct.hTable;

    os.check("Ostream& operator<<(Ostream& os, const tabulatedThermo& ct)");
    return os;
}


// ************************************************************************* //
