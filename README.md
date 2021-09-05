# spelling-recommendation-system-using-KNN
input 'msg' output will be 'message'

**Introduction:** nowadays people tend to use only consonant characters of a word when writing informal communication. So people use ‘excllnt’ instead of ‘excellent’ as a result when they go for writing formal communication they literally fight to figure out the actual spelling. They usually try out the following combination:
exellent  
excelent 
excellant etc
There are also many words which actually hard to remember the vowel sequence like ‘lieutenant, ‘nauseous’ etc

My spell recommendation system will help them out by providing some suggestions. User will provide just some hint of their intended word and our system will use KNN to find out the nearest words of the hint.

**Dataset:** I have collected around 500 words as a dictionary inside the ‘dict.txt’ file. Every line contains a single word with no leading or trailing space. One can add more words if needed.

**Procedure:** dummy character(*) will be inserted at the mismatch position in the input string according to our dictionary string. Then we will consider the matching sequence to calculate the weight to be assigned. The earlier the match happens, the more weight it will be given. Finally those words in the dictionary that contain top weight will be suggested.

**For example:**suppose we have only two words in the dictionary which are ‘precious’ and ‘previous’ and user inputs the string ‘prvs’.
let see how to assign weight for those two words

1. previous: 
	* insert dummy character(*) to the input pr*v***s
	* so we have four characters matches with our dictionary word ‘previous’.
	
2. precious:
	* insert dummy character(*) to the input pr****** 
	* so we have only two characters matches with word ‘precious’.
	
Therefore ‘previous’ will gain more weight over ‘precious’. if one character need to be suggested then only ‘previous’ will be chosen.

weight is assigned by considering how much character matches and in which position it matches, earlier positions will get more weight.


![Capture](https://user-images.githubusercontent.com/43715453/132135327-e756b78f-ce4c-4450-934e-cd23f94f1509.PNG)
sample input output
