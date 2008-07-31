#! user/bin/env perl
# Roman.plx     Author : ecntrk
use warnings;

my @a;   # temporary array
my @s;  # final array
$count = 0;

$n=<STDIN>;  # taking input in Arabic
if ($n>0 and $n<3999){   # setting values into right course.. cause I need unicode to print 4000 in Roman.

while ($n > 0){     # Splitting the numbers into individual digits.
$x = $n%10;
$a[$count] = $x;
$n /= 10;
$count += 1;}

## line 17  for debugging

if ($count > 0){                  # First Condition for base 1
        $cha2 = 'I';
    # print "1 working debug \n";
        if ($a[0] == 4){
            $char1 = 'IV';}
        elsif ($a[0]>=5 and $a[0]<=8){
            $cha1 = 'V';
            $char1 = $cha1 . ($cha2 x ($a[0]-5));  #perl's really amazing, see... 
		}
        elsif ($a[0] == 9){
            $char1 = 'IX';}
        else{
            $char1 = $cha2 x $a[0]; #print "else working debug 2 \n";
		}
$s[0]=$char1;


#print $char1;       
}

if ($count > 1){        # Second condition for base 10
        $cha2 = 'X';
    # print "1 working debug \n";
        if ($a[1] == 4){
            $char1 = 'XL';}
        elsif ($a[1]>=5 and $a[1]<=8){
            $cha1 = 'L';
            $char1 = $cha1 . ($cha2 x ($a[1]-5));  
		}
        elsif ($a[1] == 9){
            $char1 = 'XC';}
        else{
            $char1 = $cha2 x $a[1]; #print "else working debug 2 \n";
		}
$s[1]=$char1;


#print $char1;       
}
if ($count > 2){           # third condition for base 100..
        $cha2 = 'C';
    # print "1 working debug \n";
        if ($a[2] == 4){
            $char1 = 'CD';}
        elsif ($a[2]>=5 and $a[2]<=8){
            $cha1 = 'D';
            $char1 = $cha1 . ($cha2 x ($a[2]-5));  #perl's really amazing, see... 
		}
        elsif ($a[2] == 9){
            $char1 = 'CM';}
        else{
            $char1 = $cha2 x $a[2]; #print "else working debug 2 \n";
		}
$s[2]=$char1;


#print $char1;       
}

if ($count > 3){         # Last condition for base 1000... :)
        $cha2 = 'M';
        $char1 = $cha2 x $a[3];
    	$s[3] = $char1;
		}    


print reverse(@s); #Just reversed the array ...
print " \nThank you ... \n ";
}  # If condition finished..


else {
print " \n Hey, sorry mate, put a value between 0 and 4000, not included...and try again \n ";
}
