/*
 
 Coordinate - a program by Jonathan Seamon and Davis,Ezra,
 #Featuring the mysterious "I"
 #--Creates a coordinate-grid in which the player may move
 #--Provides an Interactive rpg-like environmnt.
 #--Will be enjoyed for at least 30 seconds or your monney back :)--good thing we aren't charging monnney
 */
/*TODO; complete lv 2,
text; walls on lv 2, levers, all elv but lv 0*/

 #include "gamefunct.h"

// make shure to compile with -lm (to include the math library)!!!


char map0[9][9] =
  {"+-------+",  //0 //2d array defines char[y][x]??
   "|       |",  //1
   "|     E |",  //2
   "|       |",  //3
   "|       |",  //4
   "|       |",  //5
   "|       |",  //6
   "|       |",  //7
   "+-------+"}; //8
// 012345678
char map1[15][9] =
  {"+-------+", //It's true a 2d aray is defined char[y][x]!!
   "|       |",
   "|   *   |",
   "|       |",
   "| *   * |",
   "|       |",
   "|   *   |",
   "|       |",
   "|+-+ +-+|",
   " | | | | ",
   " +-+ +-+ ",
   "  |   |  ",
   "  | E |  ",
   "  |   |  ",
   "  +---+  "};

char map2[19][19] =
  {"       |   |       ",
   "       |   |       ",
   "       |   |       ",
   "       |   |       ",
   "       |+-+|       ",
   "     +-+|X|+-+     ",
   "     |  +-+  |     ",
   "-----+       +-----",
   "    +-+  &  +-+    ",
   "  o |X|     |X|    ",
   "    +-+     +-+    ",
   "-----+       +-----",
   "     |  +-+ o|     ",
   "     +-+|X|+-+     ",
   "       |+-+|       ",
   "       |   |       ",
   "       |   |       ",
   "       |   |       ",
   "       |   |       "};
char map3[19][19] =
  {"       |   |       ",
   "    +--+---+--+    ",
   "   x           x   ",
   "   + -+     +- +   ",
   "   |  |     |  |   ",
   "   |   x   x   |   ",
   "  x+- o|   |o -+x  ",
   " |   x-+ o +-x   | ",
   " |               | ",
   " |     o # o     | ",
   " |               | ",
   " |   x-+ o +-x   | ",
   "  x+- o|   |o -+x  ",
   "   |   x   x   |   ",
   "   |  |     |  |   ",
   "   + -+     +- +   ",
   "   x    +-+    x   ",
   "    +--+| |+--+    ",
   "        +-+        "};
int main(void)
{  
   printf("\n   I am now awake,\n"
          "I know this because when my eyes where closed "
          "I saw nothing but black darkness,\n"
          "and now that my eyes are open I see nothing...\n"
          "...but white fog.\n\n"

          "   I get up,\n"
          "I feel sturdy ground beneath my feet,\n"
          "but an infernal abyss inside my mind.\n");

   while(loop==1)
   {  
      if(z == 0)
      {  
         /*-input,cls&roommsg-*/
         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen

         rmsg("   This room has an odd familiarity,\n"
              "It's like I've spent an eternity here.\n"
              "press ? for help\n");

         /*-walls&objects-*/

         room(0,8,0,8,
           "   I see a great white wall forever rising to infinity...\n"
           "...How bland.");

         elev(6,2,4,13,1,
           "   I suddenly notice a large white cube,\n"
           "it has an opening large enough to enter,\n"
           "Should I go inside the cube? ",
           "\n   I do not go inside the cube.");

         /*switches&effects*/

         lvr(0,2,6,
           "   An orb of a dull grey tint is floating in mid-air.\n"
           "Should I poke it to see if it is real? ",
           "\n   I poke the orb, and I feal a slight shock,\n"
           "It begins to glow electric green.",
           "The electric green orb is here.");
         if(sw[0])
         {map0[6][2]='G';}
         /*-map&coordinates-*/

         showmap(9,9,2,map0);
         printf("%i,%i,%i\n",x,y,z);

      }
      if(z == 1)
      {  
         /*-input,cls&roommsg-*/

         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg(
           "   I traverse through the box: out the other side,\n"
           "However, this side of the box is much different than the other...\n\n"

           "   On \"this side of the box\",\n"
           "(although I now doubt it to be such)\n"
           "There are many cylindrical objects which begin and end\n"
           "at the floor and ceiling,\n"
           "(all said objects consist of metal)\n"
           "and which twist and turn at right angles,\n"
           "and form a sort of unpassable mesh here and there.\n");

         /*-walls&objects-*/

         char wall[] =
          {"   I cannot pass through the mesh here."};
         char pillar[] =
          {"   There is an unstable pillar before me.\n"
           "It reminds me of the foundation to all logic and reason."};

         block(2,2,11,14,wall);
         block(6,6,11,14,wall);
         block(3,5,14,14,wall);
         block(1,3,8, 10,"   A large cylinder is here,\nit looks exactly like the cylinder to my left.");
         block(5,7,8, 10,"   A large cylinder is here,\nit looks exactly like the cylinder to my right.");
         block(0,0,0, 8 ,wall);
         block(8,8,0, 8 ,wall);
         block(0,8,0, 0 ,wall);
         block(4,4,6, 6 ,pillar);
         block(6,6,4, 4 ,pillar);
         block(4,4,2, 2 ,pillar);
         block(2,2,4, 4 ,pillar);

         elev(4,12,6,3,0,
           "   I see another white cube,\n"
           "it has a similar shape and composition to the one in the first room,\n"
           "should I enter? ",
           "\n   I salute the cube and continue on my way.");

         /*switches&effects*/

         if(sw[0])
         {  
            map1[4][4]='E';
            elev(4,4,9,9,2,
              "   I see that the complex geometric design that was here is now glowing blue,\n"
              "It makes me think of a transportation device.\n"
              "Should I stand on it? ",
              "I stand clear of it.");
         }
         else
         {  
            msg(4,4,4,4,
              "   My foot scrapes against a rough spot on the ground,\n"
              "I look down and see a complex geometric design,\n"
              "surrounded by an inscription:\n\n"

              "      2,6,0");
         }

         /*-map&coordinates-*/

         showmap(15,9,2,map1);
         printf("%i,%i,%i\n",x,y,z);

      }
      if( z == 2)
      {  
         /*-input,cls&roommsg-*/
         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg(
           "   I seem to have been transported to another room.\n\n"
           "A voice echoes throught before I get a feal for the room;\n\n"

           "  \"Welcome to the Infinite Cube,\n"
           "The Cube is a prototype in alternate-reality technology.\n"
           "You may ask how we know this space is a cube if it is,\n"
           "as has been previously stated, infinite.\n\n"
           "      Don\'t.\n\n"
           "   It consists of several levels,\n"
           "designed to test your mental and physical abilities,\n"
           "You are perfectly safe...\n\n"
           "   ...as far as we know.\"\n");

         /*-walls&objects-*/
         msg(9,9,8,8,"   The transport device is here,\n"
                     "It seems to be inactive as it glows dim red.");
         
         char cube[]=
          {"   You see a large cube.\n"
           "It is inscribed with strange symbols.\n"
           "They seem to portray a glowing orb...\n"
           "...this is giving me second thoughts about touching that thing."};

         block(4 ,6 ,8 ,10,cube);
         block(8 ,10,4 ,6 ,cube);
         block(12,14,8 ,10,cube);

         char wall[]=
          {"   I can't think of anything interesting to say about this wall,\n"
           "...Infinite objects must be of finite interest.\n\n"
           "(That would also explain most of my boring one-liners!)" };

         //block(7 ,11,0 ,0, wall);  // comented out room's sides.
         block(5 ,7 ,0 ,5 ,wall);
         block(0 ,5, 5, 7 ,wall);
         //block(0 ,0 ,7 ,11,wall);
         block(0 ,5 ,11,13,wall);
         block(5 ,7 ,13,18,wall);
         //block(7 ,11,18,18,wall);
         block(11,13,13,18,wall);
         block(13,18,11,13,wall);
         //block(18,18,7 ,11,wall);
         block(13,19,5 ,7 ,wall);
         block(11,13,0 ,5 ,wall);
         
         felev(7, 11,19,19,9,3,3); //botom side -> dead end
         
         /*switches&effects*/
         lvr(1,12,12,
         "I see an orb similar to that in the first room. Poke? ",
         "I feal a slight burn as it turns hot pink.",
         "The Hot Pink orb is here.");

         if(sw[1])
         {  
            map2[12][12]='P';
            map2[13][9]=' ';
            msg(8 ,10,12,14,
              "   I see the outlines of the cube around me,\n"
               "but I can't touch it.");
         }
         else
           {block(8 ,10,12,14,cube);}

         /*-map&coordinates-*/
         showmap(19,19,4,map2);
         printf("%i,%i,%i\n",x,y,z);
         

      }
      if ( z == 3)
      {
         /*-input,cls&roommsg-*/
         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg("   Blam!,a door closes behind me.\n"
              "maybe I should turn back,\n"
              "so I can look for another rought.\n");
         /*-unmove&objects-*/
         unmove(19,19,map3);
         /*-switches*/
         lvr(2, 6, 6,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(3,12, 6,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(4, 9, 7,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(5, 7, 9,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(6,11, 9,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(7, 9,11,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(8, 6,12,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
         lvr(9,12,12,"There is an orb. Poke? ",
                     "It turns purple.",
                     "A purple orb is here"); 
        /*-switch effects-*/

         if(inst[2])
         {
            if(sw[6])//switch polarity 6
            {sw[6]=0;}
            else
            {sw[6]=1;}
            
            if(sw[7])//switch polarity 7
            {sw[7]=0;}
            else
            {sw[7]=1;}
            
            inst[2]=0;
         }
         if(inst[3])
         {
            if(sw[5])//switch polarity 5
            {sw[5]=0;}
            else
            {sw[5]=1;}
            
            if(sw[7])//switch polarity 7
            {sw[7]=0;}
            else
            {sw[7]=1;}
            
            inst[3]=0;
         }
         if(inst[4])
         {
            if(sw[8])//switch polarity 8
            {sw[8]=0;}
            else
            {sw[8]=1;}
            
            if(sw[9])//switch polarity 9
            {sw[9]=0;}
            else
            {sw[9]=1;}
            
            inst[4]=0;
         }
         if(inst[5])
         {
            if(sw[3])//switch polarity 3
            {sw[3]=0;}
            else
            {sw[3]=1;}
            
            if(sw[9])//switch polarity 9
            {sw[9]=0;}
            else
            {sw[9]=1;}
            
            inst[5]=0;
         }
         if(inst[6])
         {
            if(sw[2])//switch polarity 2
            {sw[2]=0;}
            else
            {sw[2]=1;}
            
            if(sw[8])//switch polarity 8
            {sw[8]=0;}
            else
            {sw[8]=1;}
            
            inst[6]=0;
         }
         if(inst[7])
         {
            if(sw[2])//switch polarity 6
            {sw[2]=0;}
            else
            {sw[2]=1;}
            
            if(sw[3])//switch polarity 7
            {sw[3]=0;}
            else
            {sw[3]=1;}
            
            inst[7]=0;
         }
         if(inst[8])
         {
            if(sw[6])//switch polarity 6
            {sw[6]=0;}
            else
            {sw[6]=1;}
            
            if(sw[4])//switch polarity 7
            {sw[4]=0;}
            else
            {sw[4]=1;}
            
            inst[8]=0;
         }
         if(inst[9])
         {
            if(sw[4])//switch polarity 6
            {sw[4]=0;}
            else
            {sw[4]=1;}
            
            if(sw[5])//switch polarity 7
            {sw[5]=0;}
            else
            {sw[5]=1;}
            
            inst[9]=0;
         }
 
         //need to reverse map coordinates, oh well...
         if(sw[2])
         {map3[ 6][ 6]='M';}
         else
         {map3[ 6][ 6]='o';}
               
         if(sw[3])
         {map3[ 6][12]='M';}
         else
         {map3[ 6][12]='o';}

         if(sw[4])
         {map3[ 7][ 9]='M';}
         else
         {map3[ 7][ 9]='o';}

         if(sw[5])
         {map3[ 9][ 7]='M';}
         else
         {map3[ 9][ 7]='o';}

         if(sw[6])
         {map3[ 9][11]='M';}
         else
         {map3[ 9][11]='o';}

         if(sw[7])
         {map3[11][ 9]='M';}
         else
         {map3[11][ 9]='o';}

         if(sw[8])
         {map3[12][ 6]='M';}
         else
         {map3[12][ 6]='o';}

         if(sw[9])
         {map3[12][12]='M';}
         else
         {map3[12][12]='o';}
         
         if(sw[2]&&sw[3]&&sw[4]&&sw[5]&&sw[6]&&sw[7]&&sw[8]&&sw[9])
         {map3[9][9]='E';}
        /*-map&coordinates-*/
         showmap(19,19,6,map3);
         printf("%i,%i,%i\n",x,y,z);
 
     }
   }
   return 0 ;
}

 /*-input,cls&roommsg-*/
 /*-walls&objects-*/
 /*switches&effects*/
 /*-map&coordinates-*/
