#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB (1000000)

int main() 
{
  size_t i = 0;
  for (i = 0; i < 10; ++i) 
  {
    void* mem = malloc(MB * 10);
    memset(mem, 0, MB * 10);
    sleep(1);
  }
  return 0;
}
/*
I have MacOs
For ex2:
r-shakirova-x:week7 r-shakirova$ vm_stat 1 && ./ex2
Mach Virtual Memory Statistics: (page size of 4096 bytes)
    free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
   47687  1116540     8304  1106164        0  1518548   229459 5919477K  169848K 3561461K  846580K  137192K      536218   1694790  6370873   396495  759700K  928380K  154887K  2645241 1361012K 1370252K
   39966  1093355     8331  1106945        0  1548713   204080    17818        1     9594        0        0      536245   1672386  6370573   396383      300        0        0        0        0        0
   40028  1104847     8331  1105222        0  1539157   200353     9183        0     9407        0        0      536245   1682155  6370572   396383        1        0        0        0        0        0
   37035  1107704     8331  1105156        0  1539158   200435     9233        0     9466        0        0      536245   1684946  6370570   396383        2        0        0        0        0        0
   27278  1110151     8331  1105150        0  1546379   200767     9488        0     9701        0        0      536245   1687387  6370570   396383        0        0        0        0        0        0
   16841  1112575     8331  1105111        0  1554545   200757     9815        0    17510        0        0      536245   1689772  6370554   396383       16        0        0        0        0        0
   13833  1114807     8331  1105277        0  1555190   200767    10163        0    10337        0        0      536245   1692170  6370550   396447        4        0        0        0       64        0
  317252  1120144     3126  1114888        0  1542955   213239    11571        0    11962        0        4      531040   1707118  6370547    95400        3        0        0        2        0   297889
  427323  1113347     3180  1110035        0  1538946   238835     7859        0     8528        0        0      531102   1695460  6370517     1013       30        0       24        0      512    94518
  425156  1105090     3180  1109988        0  1547803   230407     8095        6    17299        0        0      531102   1687156  6370465     2740       52        0        0        0     1727        0
  424511  1113453     3180  1110070        0  1539682   238839     7827        0     9337        0        0      531102   1695601  6370457     2932        8        0        0        0      192        0
  440092  1091762     3214  1109923        0  1543696   216796     8100        0     9741        0        0      531139   1673760  6370299     5097      158        0        3        0     2165        0
  */

 /*
ex2 - output by process launched by ex2
PID    COMMAND          %CPU TIME     #TH   #WQ  #PORTS MEM   PURG  CMPRS PGRP  PPID  STATE    BOOSTS       %CPU_ME %CPU_OTHRS UID FAULTS   COW    MSGSENT   MSGRECV   SYSBSD    SYSMACH   CSW        PAGEINS IDLEW    POWER INSTRS CYCLES USER                   #MREGS RPRVT VPRVT VSIZE KPRVT KSHR
85541  ex2              0.0  00:00.01 1     0   10     29M   0B    0B    85541 84249 sleeping *0[1]       0.00000 0.00000    1087678142 7653      76      33         16         105        57         34         4       0         0.0   0      0      r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
85541  ex2              0.3  00:00.02 1     0   10     38M+   0B     0B     85541 84249 sleeping *0[1]        0.00000 0.00000    1087678142 10095+     76      35+         17+         106+        59+         52+         4       1+         0.3   5915548   11911438  r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
85541  ex2              0.3  00:00.03 1     0   10     48M+   0B     0B     85541 84249 sleeping *0[1]        0.00000 0.00000    1087678142 12537+     76      37+         18+         107+        61+         62+         4       1          0.3   7155455   16851973  r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
85541  ex2              1.1  00:00.04 1     0   10     67M+   0B     0B     85541 84249 sleeping *0[1]        0.00000 0.00000    1087678142 17421+     76      41+         20+         109+        65+         80+         4       1          1.1   13054764  26136298  r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
85541  ex2              0.7  00:00.05 1     0   10     77M+   0B     0B     85541 84249 sleeping *0[1]        0.00000 0.00000    1087678142 19863+     76      43+         21+         110+        67+         81+         4       1          0.7   7325202   14392366  r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
85541  ex2              0.6  00:00.06 1     0    10     86M+   0B     0B     85541 84249 sleeping *0[1]        0.00000 0.00000    1087678142 22305+     76      45+         22+         111+        69+         84+         4       1          0.6   7206138   14219851  r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
85541  ex2              0.7  00:00.07 1     0    10     96M+   0B     0B     85541 84249 sleeping *0[1]        0.00000 0.00000    1087678142 24747+     76      47+         23+         112+        71+         89+         4       2+         0.7   7069382   14391096  r-shakirova        N/A    N/A   N/A   N/A   N/A   N/A
As it can be seen by MEM field, memory is increased by about 10 MB each iteration
*/