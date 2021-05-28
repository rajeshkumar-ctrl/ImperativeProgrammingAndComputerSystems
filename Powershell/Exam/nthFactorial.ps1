$product=1
$input_number=$args[0]

for ($i=2; $i -le $input_number; $i++) 
{
    $product*=$i;
}

Write-Host $product
