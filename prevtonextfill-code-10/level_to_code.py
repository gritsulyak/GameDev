import sys

while 1:
 x=0
 y=0
 maxx=0
 maxy=0

 while 1:
  c = sys.stdin.read(1) 
  if not c: 
   quit()
  if c == '=':
   break
 
 cheat = sys.stdin.readline()

 print "{"
 print "GameField curTarget;"
 
 while 1:
  c = sys.stdin.read(1)

  if c=='~':
    break
  
  if c == '\n':
    if x > maxx :
      maxx = x
    x=0
    y=y+1 
    continue 

  if c >= '0' and c<='9':
    print "curTarget.m_Fields.push_back(Target(XYpair","(",x,",",y,"), ",c,"));" 
  x=x+1  

 maxy = y
 
 print "curTarget.xSize =",maxx,";";
 print "curTarget.ySize =",maxy,";";
 cheat=cheat[0:len(cheat)-1]+'"'
 print "curTarget.code_=\""+cheat+";"  
 print "sTargetFields1.push_back(curTarget);"
 print "}"

