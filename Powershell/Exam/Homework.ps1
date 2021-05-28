<#

Write powershell script program (wordsinwords.ps1) which has got a parameter (a filename)! The file contains a text. The task of the script is to decide which word is contained most frequently in other words. (e.g. the text is: play ball football basketball snowball - therefore ball is the winner because it is part of three other worlds)


#>


$file_data= Get-Content "combined.txt"
$number_of_words = Get-Content "combined.txt" | Measure-Object -word
$Words =$file_data.Split(" ")

$WordCount = 0
$MAXCount = 0 
$Longest = ""

for($i = 0; $i -lt $Words.Length; $i++){
    $k = 0


    while (($k -lt $i) -and ($Words[$k] -ne $Words[$i])){
        $k += 1
    }

    if( $k -ge $i ){
        $WordCount = 0
        for ($j = 0; $j -lt $Words.Length; $j++) {
            if($Words[$i] -eq $Words[$j]){
                $WordCount++
            }
        }
    
        if($WordCount -ge $MAXCount){
            $MAXCount = $WordCount
            $Longest = $Words[$i]
        }
    }
}

Write-Host $Longest " is the longest word that appeared " $MAXCount " times in the file."
