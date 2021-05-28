<#

Write a Powershell script, (4.ps1) which gets a file name as parameter. In the file lines
there are names.- three names per line separated by space.
Write out TRUE if the sum of the names length are bigger than 20 if not write FALSE!
E.g. The file:
Ann Joe Jil => FALSE
Annamarie Annabella William =>TRUE
#>


$fname = $args[0]
if(test-path $fname){
    $fdata = Get-Content $fname
    foreach($line in $fdata){
        $linesum = 0
        for($i=0; $i -lt 3; $i++){
            $word = ($line.split(""))[$i]
            $linesum+=$word.length
        }
        
        if($linesum -gt 20){
            Write-Host "   TRUE   " 
        }else{
            Write-Host "   FALSE  "
        }
    }
}
