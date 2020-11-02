#include "animation.h"


void drawanimatedjonathan_vh()
{


        jonathan_vh.frameNumber++;

        if(jonathan_vh.frameNumber >= jonathan_vh.sprite->w / JONATHAN_VH_WIDTH)
               {
                 jonathan_vh.frameNumber = 0;
               }



    drawJonathan_vh();
}

void drawanimatedjonathan()
{


               if(jonathan.frameNumber >= jonathan.sprite->w / JONATHAN_WIDTH)
               {
                 jonathan.frameNumber = 0;
               }



    drawJonathan();
}


