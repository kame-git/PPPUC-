# 第6章 練習問題7
## 問
論理式(!,¥~,&,|,^)の文法を記述する。  

!と~は前置単項演算子、優先順位は&>^>lとする。 
## 例
* x|y^z=x|(y^z)  
* x^y&z=x^(y&z)  
## 文法
Expression:  
	Term1  
	Expression "|" Term1  
Term1:  
    Term2  
    Term1 "^" Primary   
Term2:  
    Primary  
    Term2 "&" Primary  
Primary:  
    Number  
    "~" Number  
    "!" Number  
