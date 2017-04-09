str=$*
left=${str//\[/\{}
right=${left//\]/\}}
echo $right | pbcopy
