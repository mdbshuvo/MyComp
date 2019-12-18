cls
bison -d myComp.y
flex myComp.l
g++ lex.yy.c myComp.tab.c -o myComp
myComp code.b
type code.b.out