# tabulatedProperties

By Luka Denies
MSc student at Delft University of Technology

OpenFOAM addition to use tabulated properties for thermophysical properties
Implemented:
- equationOfState (rho, psi, Z, cpMcv)
- thermo (cp, ha, hs)
- transport (mu, kappa, alphah)

Requires a table in pressure and temperature for:
- density (rho, psi, Z)
- specific heat (cp, alphah)
- enthalpy (h)
- viscosity (mu)
- thermal conductivity (kappa, alphah)

To be added soon:
- Tutorial case
- Support for putting property tables in case/constant directory instead of root

