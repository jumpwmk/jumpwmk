var alphabet = ['A', 'B', 'C', 'D', 'E'];
var answer = 'B';
var isCorrect = false;
for(var i = 0; i < 4; i++)
{
    if(alphabet[ i ] == answer)
    {
    	console.log(alphabet[ i ]);
        isCorrect = true;
    }
}

console.log(isCorrect);