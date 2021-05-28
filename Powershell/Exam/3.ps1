<# 
Write a Powershell script (3.ps1), which gets a file name as parameter.
Check the existence of the file! In the file there are lines which contains integers, floats
and words  - - but only one per line. DEcide whether the number of words and floats are
the same or not!
E.g. .\3.ps1 f.txt   =>NOT (contains two words but only 1 float)
// f.txt contains:
apple
2
5.6
tree



#>



$fname = $args[0]
if(test-path $fname){

    $wordCounter = 0
    $floatCounter = 0

    $fdata = Get-Content $fname
    foreach($line in $fdata){
        if($line -match "[a-z][A-Z]"){
            $wordCounter+=1
        }
        if($line -match "[0-9].[0-9]"){
            $floatCounter+=1
        }
        
    }


    if($wordCounter -eq $floatCounter){
        Write-Host YES
    }else{
        Write-host NOT
    }
}
