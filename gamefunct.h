/*

Coordinate - a program by Jonathan Seamon and Davis,Ezra,
#Featuring the mysterious "I"
#--Creates a coordinate-grid in which the player may move
#--Provides an Interactive rpg-like environmnt.
#--Will be enjoyed for at least 30 seconds or your money back,
:) --good thing we aren't charging money
 */

 #include <stdio.h> // input/output, duh!
 #include <termios.h> // for 'getch'.
 #include <unistd.h>
 #include <math.h> // for sqrt in showmap


char inp ;                                  //  //==||
int loop=1,                                //  //   ||
    x  = 4,                               //  //    \/ ?
    y  = 4,                              //  //	    /\ U
    py = 4,                             //  //_____/ /
    px = 4,                            //   \______ global variable(s)
    z  = 0,                           //
showmsg= 1;
int sw[10]={0,0,0,0,0,0,0,0,0,0};
int inst[10]={0,0,0,0,0,0,0,0,0,0};
int getch(void) // code snippet from kermie3 @ cprogramming.com
{  
   struct termios oldt,
                 newt;
   int            ch;
   tcgetattr( STDIN_FILENO, &oldt );
   newt = oldt;
   newt.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newt );
   ch = getchar();
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
   return ch;
}
void takeinp(void)
{  

   // scanf( "%s", &inp ) ;		/* scan input onto &inp */

   py=y;  //previous x and y
   px=x;

   inp = getch(); //scan input onto &inp

//   if     ( inp == 'w' ) {--y;} //it would be more convenient to have this be a switch-case block
//   else if( inp == 'a' ) {--x;} //but i'm to lazy to re-write
//   else if( inp == 's' ) {++y;}
//   else if( inp == 'd' ) {++x;}
//   else if( inp == 'Q' ) {loop = 0;}
//   else if( inp == 'h' || inp == 'H')
//   {  
     switch(inp)
     {
        case 'w':
        case 'k':
        y--;break;
        case 'a':
        case 'h':
        x--;break;
        case 's':
        case 'j':
        y++;break;
        case 'd':
        case 'l':
        x++;break;
        case 'Q':
        loop--;break;
        case 'H':
        case '/':
        case '?':
        printf("A beam of light descends from above,\n"
             "bearing in it this tablet:\n"

             "+-----------------------------------+\n"
             "|                                   |\n"
             "| The Tablet Of Mystical Guidence   |\n"
             "|                                   |\n"
             "|                                   |\n"
             "|        Type H for help            |\n"
             "|                                   |\n"
             "|                                   |\n"
             "|                                   |\n"
             "|                                   |\n"
             "+-----------------------------------+\n\a");
        int inph = getch();
        if (inph == 'h' || inph == 'H')
        {  
           int i; for(i=0; i!=60; i++) printf("\n");
           printf("This Tablet has been brought to you by Hammerspace®\n"
                "+-----------------------------------+\n"
                "|                                   |\n"
                "|           The Tablet              |\n"
                "|      Of Mystical Guidence II      |\n"
                "|          Bigger & better          |\n"
                "|                                   |\n"
                "|  Now with 50 per¢ more Guidence   |\n"
                "|                                   |\n"
                "|              movement:            |\n"
                "|            w          k           |\n"
                "|          a s d  or  h j l,        |\n"
                "|                                   |\n"
                "|               Quit: Q             |\n"
                "|                                   |\n"
                "|                                   |\n"
                "+-----------------------------------+\n");getch();
           printf("* Not a real trademark");
       }
      }   
}
void showmap(int w, int h, int dis, char map[w][h])
{  
   int hp,wp; //variables to show position in map.

   for   (wp = 0; wp < w; wp++)
   {  
      for(hp = 0; hp < h; hp++)
      {  
         int rdis = (hp-x)*(hp-x)+(wp-y)*(wp-y);
         if(wp == y && hp==x)
           {printf("[0;32;40mA [0;37;40m");}
         else if( sqrt(rdis) <= dis)
           {/*change the color for spacific charecters & print them*/
   
           if      (map[wp][hp]=='E')//blue
             {printf("[0;34;40mE [0;37;40m");}
   
           else  if(map[wp][hp]=='*')//red
             {printf("[0;31;40m* [0;37;40m");}
               
           else  if(map[wp][hp]=='|')//yellow+
             {printf("[1;33;40m| [0;37;40m");}   
          
           else  if(map[wp][hp]=='-')//yellow+
             {printf("[1;33;40m- [0;37;40m");}   
          
           else  if(map[wp][hp]=='+')//yellow+
             {printf("[1;33;40m+ [0;37;40m");}   
          
           else  if(map[wp][hp]=='x')//yellow+
             {printf("[1;33;40mx [0;37;40m");}   
                     
           else  if(map[wp][hp]=='R')//red orb
             {printf("[0;31;40mO [0;37;40m");}   
          
           else  if(map[wp][hp]=='G')//green orb
             {printf("[0;32;40mO [0;37;40m");}   
 
           else  if(map[wp][hp]=='B')//blue orb
             {printf("[0;34;40mO [0;37;40m");}   
 
           else  if(map[wp][hp]=='M')//magenta orb/
             {printf("[0;35;40mX [0;37;40m");}  

           else  if(map[wp][hp]=='P')//hot pink orb/
             {printf("[1;35;40mO [0;37;40m");}  
           
           else
             {printf("%c ",map[wp][hp]);}
           }
   	 else
           {printf("  ");}
      }
      printf("\n");
   }
}
void block(int lx, int rx, int ty, int by, char msg[])
{  
   if( x>=lx && x<=rx && y>=ty && y<=by )
     {y=py; x=px; printf("%s\n\a",msg);}
}
void unmove(int w, int h, char map[w][h]) // why didn't I think of this BEFORE block()???
{
   switch(map[y][x])
   {
      case '|':
      case '-':
      case '+':
      case 'x':
      y=py;
      x=px;
      printf("The wall message disables for the programmers' convenience.\n\a");
      break;
   }
}
void room (int lx, int rx, int ty, int by, char msg[])
{  
   if( x<=lx || x>=rx || y<=ty || y>=by )
     {y=py; x=px; printf("%s\n\a",msg);}
}
void msg  (int lx, int rx, int ty, int by, char msg[])
{  
   if( x>=lx && x<=rx && y>=ty && y<=by )
     {printf("%s\n\a",msg);}
}
void rmsg(char msg[])
{  
   if(showmsg==1)
     {printf("%s",msg); showmsg=0;getch();}
}
void felev(int lx, int rx, int ty, int by, int gx, int gy, int gz)
{  
   if( x>=lx && x<=rx && y>=ty && y<=by )
   {  
      printf("Do I walk into the next room? ") ;
      scanf ("%s", &inp ) ;		/* scan input onto &inp */

      if(inp == 'y')
        {y=gy ; x=gx ; z=gz ; showmsg=1; }
      else 
        {x=px; y=py;}
   }

}
void elev (int lx, int ly, int tx, int ty, int tz, char msg[], char msgn[])
{  
   if( x == lx && y == ly )
   {  
      printf("%s", msg  ) ;
      scanf ("%s", &inp ) ;		/* scan input onto &inp */

      if(inp == 'y')
        {y=ty ; x=tx ; z=tz ; showmsg=1; }
      else {printf("%s\n", msgn); x=px; y=py; takeinp();}
   }
}
void lvr(int s, int lx, int ly, char msg0[], char msgy[], char msg1[])
{
   if( x == lx && y == ly )
   {  
      if(sw[s])
        {printf("%s",msg1);}
      else
      {
           printf("%s",msg0);
           scanf ("%s",&inp);
           if(inp=='y')
             {sw[s]=1;inst[s]=1;printf("\a%s", msgy);takeinp();}
           else
             {takeinp();}
      }
   }
}
