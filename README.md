# RSA-Implementation
RSA Encryption and Decryption using Public and Private keys including other operations.

Note: 
1) This code was an assignment in Security course in my college, and it was required to include all functions and classes in one cpp file, that's why I did so.

2) It was required that we implement an algorithm to deal with very big numbers and not to use the ready libraries, and that was the hard part about the project.
This code is capable of:
1- Doing any of the basic operations (plus, minus, mul, div) on any 2 big numbers.
2- Primality test on any big number.
3- Getting the pwr of any number or get the pwr of any number under a specific mod. (ex. 3^7 mod 10) 
4- Getting Inverse of any number under a specific mod using Extended Euclid.
5- Encrypt using public or private keys.


==========================

** Tried tests:

Test #1
(Number Of P & Q bits: 8)
(Time: milliseconds)

P=67
Q=43
E=13
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<1994>
EncryptPrivate=<1755>
Quit


==========================

Test #2 
(Number Of P & Q bits: 16)
(Time: milliseconds)

P=26309
Q=6581
E=11
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<0123456>
EncryptPrivate=<51714414>
Quit


==========================

Test #3 
(Number Of P & Q bits: 32)
(Time: milliseconds)

P=1843337113
Q=1014065287
E=7
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<8764932147>
EncryptPrivate=<747972787394966084>
Quit


==========================

Test #4
(Number Of P & Q bits: 64)
(Time: 0.8 sec)

P=6592183028488204223
Q=15369086635329281669
E=17
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<123123123123456456456>
EncryptPrivate=<93738337573499717367533201395797902883>
Quit


==========================

Test #5
(Number Of P & Q bits: 96)
(Time: 1.1 sec)

P=71065247938178632403540728757
Q=19004600296118742180338124947
E=17
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<19982222221998>
EncryptPrivate=<903785262068290870253208419297181915827679755148969533024>
Quit


==========================

Test #6
(Number Of P & Q bits: 128)
(Time: 1.3 sec)

P=75164025890726496019173371238111072907
Q=46134478684436156789454923032401055711
E=65537
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<991992993994>
EncryptPrivate=<1778216672399920029071975224868841826488744100844410587264019418645347026002>
Quit


==========================

Test #7
(Number Of P & Q bits: 256)
(Time: 4.8 sec)

P=90659935589672134066418069661244537071942135986254663159165058746421811420293
Q=58309303853042539764661388376356487646503897140817194956479465954985166355731
E=65537
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<729635987311111>
EncryptPrivate=<307544207737943951363288472891362986097510918654030168414175278866222437123293942515732562114635604248417979457622899834036676310152557601215352043880320>
Quit


==========================

Test #8
(Number Of P & Q bits: 512)
(Time: 25 sec)

P=628318670066178457053670199563344464965537168632953142338299523986368528873871040502441803731787657611039664858028755241659900940358103952351683108930567
Q=7719361681463342032600828111006038574009562360881761909317110325482481339309282366637253454121668834209708774688976768853700053421162120853406191359220773
E=65537
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=<5050505005050500505050500505>
EncryptPrivate=<3164467343985800246832186720654280624146836502168819921428611367378029691246128600429410378082691848172476726109145992532845600439948982411929203081121732283557275184613524289745648178917469405771451345680111788833000937433864950279253479224324641123998653609567574869127586951862847698525322773543202526214>
Quit

