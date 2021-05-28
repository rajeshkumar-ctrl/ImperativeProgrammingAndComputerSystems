$N=Read-Host
$a=0
$b=1
$fibo=0
write-host ($fibo+1)
for($i=2;$i -le $N;$i++)
{
    $fibo=$a+$b
    $a=$b
    $b=$fibo
    write-host $fibo
}
