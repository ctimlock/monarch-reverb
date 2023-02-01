*-----------------------------------------------------------------------
* Filename:		G12M.inc  V3  3/7/97
* Simulator:		PSpice
* Device type:		Loudspeaker
* Device model:		Celestion G12M
*
* Author:		Duncan Munro
* Date:			29/6/97
* Copyright:		(C)1997 DDS
*
* The model reflects the change of impedance as presented to
* the amplifier with frequency.
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* The model is not endorsed or supported by Celestion.  All trademarks
* acknowledged.
*
* Email queries to duncan@muffy.demon.co.uk
*
* Pins   A  Terminal 1
*        B  Terimal 2
*
*-----------------------------------------------------------------------

.SUBCKT G12M A B
R_RL          A       $N_0002  7.5  
R_RD1         $N_0002 $N_0003  12  
L_LD1         $N_0003 $N_0002  20mH  
C_CD1         $N_0002 $N_0003  225u  
R_RD2         $N_0003 $N_0004  0.5  
C_CD2         $N_0003 $N_0004  50u  
L_LD2         $N_0004 $N_0003  100uH  
L_LD3         B       $N_0004  100uH  
R_RD3	      B       $N_0004  20
.ENDS 