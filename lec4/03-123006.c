/* 
 * 文字のカウント(デバッグ)
 * 学籍番号: 03-123006
 * 氏名: 岩成達哉
 */


#include <stdio.h>

/* 小文字アルファベットならTrueを返す関数 */
int isLower(int);

int main(){

  //count[x][y] stores the no. of times we observe the letter y after letter x.
  int count[26][26];

  //initialize the count 2D array to zeros.
  int i, j;
  for(i = 0; i < 26; i++){
    for(j = 0; j < 26; j++){
      count[i][j] = 0;
    }
  }

  // Do the counting.
  int x, y, c;
  x = getchar();
  while( (c = getchar()) != EOF){
    y = c;
    if ((isLower(x)) && (isLower(y))){
// ここで元々はxとyが0から25の間に収まってなくてSegment Faultが起きていた
// count[x][y]++; ではxとyがアルファベット('a'から'z'なので配列をはみ出す)
      count[x - 'a'][y - 'a']++;  // したがって, 'a'で引く
    }
    x = y;
  }

  //print the non-zero counts.
  for(i = 0; i < 26; i++){
    for(j = 0; j < 26; j++){
      if (count[i][j] > 0){
	printf("count[%c][%c] = %d\n", (i + 'a'), (j + 'a'), count[i][j]);
      }
    }
  }
  return 0;
}

/* 小文字アルファベットならTrueを返す関数 */
int isLower(int c){
  //return 1 if c is lowercase alphabet charachter.
// ここでcが"."や"A"などでも1を返していた
// if ((c != '\n') && (c != '\t') && ( c!= ' ')){
// では大文字のアルファベットなども認めてしまう
  if (c >= 'a' && c <= 'z'){ // したがって, cを'a'から'z'までに限定
    return 1;
  }
  else{
    return 0;
  }
}
