*--------------------------------------------------------------------------
* Specialized tube model
*
*    Type           : 12AX7 ECC83 6N2P
*    Description    : Triode
*    Direct heated  : no
*    Screen present : no
*--------------------------------------------------------------------------
.subckt 12AX7GH P G K
Bp P K I=((0.001149607902m)+(0.0001063352726m)*V(G,K))*uramp((91.16514401)*V(G,K)+V(P,K)+(52.29904339))**1.5 * V(P,K)/(V(P,K)+(2.177964467))
Cgp G P 1.7pF
Cgk G K 1.6pF
Cpk P K 0.46pF
.ends 12AX7