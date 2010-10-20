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
  {"+-------+", //It's true 2d aray is defined char[y][x]!!
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
   "    |X|     |X|    ",
   "    +-+     +-+    ",
   "-----+   L   +-----",
   "     |  +-+  |     ",
   "     +-+|X|+-+     ",
   "       |+-+|       ",
   "       |   |       ",
   "       |   |       ",
   "       |   |       ",
   "       |   |       "};


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
              "press h for help\n");

         /*-walls&objects-*/

         room(0,8,0,8,
           "   I see a great white wall forever rising to infinity...\n"
           "...How bland.");

         elev(6,2,4,13,1,
           "   An elegant glass box materializes out of the mist,\n"
           "it has a height twice its length and width,\n"
           "I wonder if I should go inside, Do I? ",
           "\nI decide not to enter the box.");

         /*switches&effects*/

         lvr(0,2,6,
           "I have found a lever. Do I pull it? ",
           "I pull the lever",
           "I have already pulled this lever.");

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
           "   I step into the elevator and the machine begins to hum\n"
           "as the doors close behind me.\n"
           "I notice the elevator has no buttons inside as it starts to move.\n"
           "The elevator continues for a time.\n\n"

           "   The doors open with a hiss.\n"
           "I step outside and look at the space where I have been deposited,\n"
           "The white mist is still there, but I can see the ceiling now.\n"
           "There is a three dimensional network of pipes on said ceiling.\n");

         /*-walls&objects-*/

         char wall[] =
          {"   I see a network of pipes barring my way in that direction,\n"
           "some of the tubes rising to the ceiling are warm "
           "and others are very cold."};
         char pillar[] =
          {"   There is an unstable pillar before me.\n"
           "It reminds me of the foundation to all logic and reason."};

         block(2,2,11,14,wall);
         block(6,6,11,14,wall);
         block(3,5,14,14,wall);
         block(1,3,8, 10,"   I see a large tube,\nit looks exactly like the tube to my left.");
         block(5,7,8, 10,"   I see a large tube,\nit looks exactly like the tube to my right.");
         block(0,0,0, 8 ,wall);
         block(8,8,0, 8 ,wall);
         block(0,8,0, 0 ,wall);
         block(4,4,6, 6 ,pillar);
         block(6,6,4, 4 ,pillar);
         block(4,4,2, 2 ,pillar);
         block(2,2,4, 4 ,pillar);

         elev(4,12,6,3,0,
           "   I see another glass box,\n"
           "it has a similar shape and composition to the one in the first room,\n"
           "should I enter? ",
           "\nI salute the box and continue on my way.");

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
      if( z== 2)
      {  
         /*-input,cls&roommsg-*/
         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg(
           "I seem to have been transported to another room.\n\n"
           "A voice echoes throught before I get a feal for the room;\n\n"

           "  \"Welcome to the Infinite Cube,\n"
           "The Cube is a prototype in alternate-reality technology.\n"
           "You may ask how we know this space is a cube if it is,\n"
           "as has been previously stated, infinite.\n\n"
           "      Don\'t.\n\n"
           "   It consists of several levels,\n"
           "designed to test your mental abilities,\n"
           "which are being enhanced by experiments in the real world.\n"
           "You are perfectly safe...\n\n"
           "   ...as far as we know.\"\n");

         /*-walls&objects-*/
         char cube[]=
          {"   You see a large cube.\n"
           "It is inscribed with strange symbols.\n"
           "They seem to indicate the turning of a lever...\n"
           "...this is giving me second thoughts about turning that lever."};

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
         
         felev(7, 11,19,19,4,4,0); //botom side -> begining
         
         /*switches&effects*/
         lvr(1,9,11,"I see a lever, do I pull it? ","I pull the lever",
         "I already pulled the lever");

         if(sw[1])
         {  
            map2[13][9]=' ';
            msg(8 ,10,12,14,
              "I see the outlines of the cube around me,\n"
               "but I can't touch it.");
         }
         else
           {block(8 ,10,12,14,cube);}

         /*-map&coordinates-*/
         showmap(19,19,4,map2);
         printf("%i,%i,%i\n",x,y,z);
         

      }
   }
   return 0 ;
}

 /*-input,cls&roommsg-*/
 /*-walls&objects-*/
 /*switches&effects*/
 /*-map&coordinates-*/
