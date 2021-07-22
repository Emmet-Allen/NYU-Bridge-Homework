#include <iostream>
#include <string>


// First we want to ask the user for an input string sentence. We can use 'getline(cin ,sentence)' 
// Next we need to determine how many words are in the string. Words are seperated by spaces, so n+1, where 'n' is the number of spaces. 
// We need to seperate each word, we can use substr() method. 

// The index of the letter of the first word, then find the index of the first space. 
// use substr(first letter index, index of space minus 1 (to get the length of the first word). 


using namespace std;
string* createWordsArray(string sentence, int& outWordsArrSize); 

int main() { 

	string sentence; 

	cout << "Please enter a sentence: ";
	getline(cin, sentence); 

	int arraySize = 0;

	string* wordArray = createWordsArray(sentence, arraySize);

	int arrSize = arraySize;

	
	cout << "[";
	for (int i = 0; i < arraySize; i++) {
		cout << '"' << wordArray[i] << '"' << ',';
	}
	cout << "]";

	delete[] wordArray;
	return 0; 

}



string* createWordsArray(string sentence, int& outWordsArrSize){
	int wordCount = 1;
	int wordpos = 0; 
	int wordlength = 0; 
	int arrayLength = 0; 
	int counter = 0;
	string wordStore; 

	//Words are seperated by spaces, so n + 1, where 'n' is the number of spaces, and 1 is the default number of words. 
	for (int i = 0; i < sentence.length(); i++) {
		if ( sentence[i] == ' ' ) {
			wordCount+=1;
		}
	}
	 // Return the count of the words by reference. 
	 outWordsArrSize = wordCount;

	 //Dynamic Array of words.
	string* wordsArray = new string[wordCount];

	// This will loop through each letter of the sentence. 
	for (int i = 0, j = 0; i < sentence.length(); i++) {
		// If the i is a space, and j == 0, then this would signify the first word.
		if (sentence[i] == ' ' && j == 0) {
			wordpos = i;
			// We can take out the word, by the index of j in the sentence, and the position of the first space.
			// This will give us the length of chars in that word
			wordStore = sentence.substr(j, wordpos);
			wordsArray[counter] = wordStore;
			//Update dynamic storage
			counter++;
			// Update j to the next space. 
			j = i;
		}
		//If both i and j are spaces, that signifies a next word. 
	   else if ( sentence[i] == ' '  && sentence[j] == ' ' ) {
			wordpos = i;
			// We can take out the word by having the index of word start at j+1, the first char of the word
			// The length can be substracted by the position of the next space minus the first char. 
			wordStore = sentence.substr( (j + 1), (wordpos - (j + 1) ) );
			wordsArray[counter] = wordStore;
			counter++;
			j = i; 
		}
		//If i is the last loop, then this is the last word
	   else if ( (i == sentence.length() - 1) && sentence[j] == ' ') {
			// The position of the last char would be the sentence length.
			// So we need to include that last char. 
		   wordpos = i + 1;
		   // Same idea as before. 
		   wordStore = sentence.substr( (j + 1), (wordpos - j) );
		   wordsArray[counter] = wordStore;
		   counter++;
		   j = i; 
	   }
	}
	return wordsArray; 
}