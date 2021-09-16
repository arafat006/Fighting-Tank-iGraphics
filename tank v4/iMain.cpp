# include "iGraphics.h"

int bulletcontrol = 0;
int bulletindx=200, bulletindy = 261;
int tempbulletindx;
int bulletindxlock = 0;
int hide_bullet = 1;

int bombindx = 0, bombindy = 500-2;
int bombdx=5, bombdy=5;
int hide_bomb = 1;
int bomblock = 0;
int rel=0;
int bompcontrol = 0;
void bomb_relieze();
int life=0;
int touch = 0;
int fireindx = 0, fireind2 = 0;
//int tanklife = 0;
//score....
int score = 0;
char score_show[20];
//
int lifelevel = 4;

int tank1indx = 200, tank1indy = 126;//1

int plane2indx = 470, plane2indy = 500;//2

int dx = 5;
int planehood = 0;

int fire1ind = 0;
int blust = 0;
int bombindcatch = 10;

char fire[60][30] = { "pic//fire//IMG00000.bmp", "pic//fire//IMG00001.bmp", "pic//fire//IMG00002.bmp", "pic//fire//IMG00003.bmp", "pic//fire//IMG00004.bmp" 
, "pic//fire//IMG00005.bmp", "pic//fire//IMG00006.bmp", "pic//fire//IMG00007.bmp", "pic//fire//IMG00008.bmp", "pic//fire//IMG00009.bmp"
, "pic//fire//IMG00010.bmp", "pic//fire//IMG00011.bmp", "pic//fire//IMG00012.bmp", "pic//fire//IMG00013.bmp", "pic//fire//IMG00014.bmp"
, "pic//fire//IMG00015.bmp", "pic//fire//IMG00016.bmp", "pic//fire//IMG00017.bmp", "pic//fire//IMG00018.bmp", "pic//fire//IMG00019.bmp" 
, "pic//fire//IMG00020.bmp", "pic//fire//IMG00021.bmp", "pic//fire//IMG00022.bmp", "pic//fire//IMG00023.bmp", "pic//fire//IMG00024.bmp" 
, "pic//fire//IMG00025.bmp", "pic//fire//IMG00026.bmp", "pic//fire//IMG00027.bmp", "pic//fire//IMG00028.bmp", "pic//fire//IMG00029.bmp" 
, "pic//fire//IMG00030.bmp", "pic//fire//IMG00031.bmp", "pic//fire//IMG00032.bmp", "pic//fire//IMG00033.bmp", "pic//fire//IMG00034.bmp" 
, "pic//fire//IMG00035.bmp", "pic//fire//IMG00036.bmp", "pic//fire//IMG00037.bmp", "pic//fire//IMG00038.bmp", "pic//fire//IMG00039.bmp" 
, "pic//fire//IMG00040.bmp", "pic//fire//IMG00041.bmp", "pic//fire//IMG00042.bmp", "pic//fire//IMG00043.bmp", "pic//fire//IMG00044.bmp" 
, "pic//fire//IMG00045.bmp", "pic//fire//IMG00046.bmp", "pic//fire//IMG00047.bmp", "pic//fire//IMG00048.bmp", "pic//fire//IMG00049.bmp" 
, "pic//fire//IMG00050.bmp", "pic//fire//IMG00051.bmp", "pic//fire//IMG00052.bmp", "pic//fire//IMG00053.bmp", "pic//fire//IMG00054.bmp" 
, "pic//fire//IMG00055.bmp", "pic//fire//IMG00056.bmp", "pic//fire//IMG00057.bmp", "pic//fire//IMG00058.bmp", "pic//fire//IMG00059.bmp" };

char fire1[60][30] = { "pic//fire1//IMG00000.bmp", "pic//fire1//IMG00001.bmp", "pic//fire1//IMG00002.bmp", "pic//fire1//IMG00003.bmp", "pic//fire1//IMG00004.bmp"
, "pic//fire1//IMG00005.bmp", "pic//fire1//IMG00006.bmp", "pic//fire1//IMG00007.bmp", "pic//fire1//IMG00008.bmp", "pic//fire1//IMG00009.bmp"
, "pic//fire1//IMG00010.bmp", "pic//fire1//IMG00011.bmp", "pic//fire1//IMG00012.bmp", "pic//fire1//IMG00013.bmp", "pic//fire1//IMG00014.bmp"
, "pic//fire1//IMG00015.bmp", "pic//fire1//IMG00016.bmp", "pic//fire1//IMG00017.bmp", "pic//fire1//IMG00018.bmp", "pic//fire1//IMG00019.bmp"
, "pic//fire1//IMG00020.bmp", "pic//fire1//IMG00021.bmp", "pic//fire1//IMG00022.bmp", "pic//fire1//IMG00023.bmp", "pic//fire1//IMG00024.bmp"
, "pic//fire1//IMG00025.bmp", "pic//fire1//IMG00026.bmp", "pic//fire1//IMG00027.bmp", "pic//fire1//IMG00028.bmp", "pic//fire1//IMG00029.bmp"
, "pic//fire1//IMG00030.bmp", "pic//fire1//IMG00031.bmp", "pic//fire1//IMG00032.bmp", "pic//fire1//IMG00033.bmp", "pic//fire1//IMG00034.bmp"
, "pic//fire1//IMG00035.bmp", "pic//fire1//IMG00036.bmp", "pic//fire1//IMG00037.bmp", "pic//fire1//IMG00038.bmp", "pic//fire1//IMG00039.bmp"
, "pic//fire1//IMG00040.bmp", "pic//fire1//IMG00041.bmp", "pic//fire1//IMG00042.bmp", "pic//fire1//IMG00043.bmp", "pic//fire1//IMG00044.bmp"
, "pic//fire1//IMG00045.bmp", "pic//fire1//IMG00046.bmp", "pic//fire1//IMG00047.bmp", "pic//fire1//IMG00048.bmp", "pic//fire1//IMG00049.bmp"
, "pic//fire1//IMG00050.bmp", "pic//fire1//IMG00051.bmp", "pic//fire1//IMG00052.bmp", "pic//fire1//IMG00053.bmp", "pic//fire1//IMG00054.bmp"
, "pic//fire1//IMG00055.bmp", "pic//fire1//IMG00056.bmp", "pic//fire1//IMG00057.bmp", "pic//fire1//IMG00058.bmp", "pic//fire1//IMG00059.bmp" };

void bomb_control();
void bomb_touch_control();
void bomb_blust();

void iDraw()
{
	//place your drawing codes here
	iClear();

	//background picture :::::::::
	iShowBMP2(0, 0, "pic//background2.bmp", -1);
	//life level ::::::::::::
	iShowBMP2(1085, 650, "pic//lifelevel.bmp", -1);

	//score.....
	iSetColor(100,90,80);
	_itoa_s(score, score_show, 9);
	iText2(27, 670, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(120, 670, score_show, GLUT_BITMAP_TIMES_ROMAN_24);
	//

	//bomb blust....
	if (blust == 1)
	{
		if (fire1ind >= 60)
		{
			fire1ind = 0;
			blust = 0;
		}
		iShowBMP2(bombindcatch - 15, 142, fire1[fire1ind++], 0);
	}

	//

	
	//fire behind tank 
	if (fireind2 > 59)
	{
		fireind2 = 0;
	}
	if (lifelevel == 0)
	{
		iShowBMP2(tank1indx, tank1indy, fire[fireind2], 0);
		fireind2 =fireind2+ 1;
	}

	//

	//plane life :::::::::
	if (lifelevel>0)
	iShowBMP2(1085, 645, "pic//life.bmp", 0);
	if (lifelevel>1)
	iShowBMP2(1110, 645, "pic//life.bmp", 0);
	if (lifelevel>2)
	iShowBMP2(1135, 645, "pic//life.bmp", 0);
	if (lifelevel>3)
	iShowBMP2(1160, 645, "pic//life.bmp", 0);
	//
	//life text ::::::::::::
	iSetColor(0,0,255);
	iText(1040, 665, "LIFE");

	//bullet :::::::::::::
	if (bulletindxlock == 0)
	{
		bulletindx = tank1indx + 57;
	}
	else
	{
		bulletindx = tempbulletindx;
	}

	if (bulletcontrol == 1)
	{
		bulletindy += 5;
	}


	//if (hide_bullet == 1)
	{
		if ((bulletindy > 490) && (hide_bullet == 1))
		{
			bulletindxlock = 0;
			bulletindy = 261;
			bulletcontrol = 0;
			//hide_bullet = 0;
		}
	}
	//else
	{
		if (bulletindy > 700)
		{
			bulletindxlock = 0;
			bulletindy = 261;
			bulletcontrol = 0;
		}
	}
	if (bulletindy)
	{
		iShowBMP2(bulletindx, bulletindy, "pic//bullet.bmp", 0);
	}


	//plane bomb
	if (bomblock==0)
	{
		bombindx = plane2indx + 70;
	}
	else
	{

	}


	if ((bombindy<plane2indy) && (lifelevel!=0))
	iShowBMP2(bombindx, bombindy, "pic//bomb1.bmp", 255);
	
	bomb_touch_control();
	if (touch == 1)
	{
		lifelevel--;
	}

	if (hide_bomb == 1)
	{
		//bombindy = 500 - 2;
	}
	if (rel == 1)
	{
		if (lifelevel>0)
		{
			bombindy -= 7;
		}
	}
	if (bombindy < 142)
	{
		bombindcatch = bombindx;
		blust = 1;
		rel = 0;
		bomblock = 0;
		bombindy = 500 - 2;
	}
	
	
	//
	

	iShowBMP2(tank1indx , tank1indy, "pic//tank1(180).bmp", 0);
	
	if (dx > 0)
	{
		if (lifelevel != 0)
		{
			iShowBMP2(plane2indx, plane2indy, "pic//plane3.bmp", 0);
		}
		else
		{
			//iShowBMP2(plane2indx, plane2indy, "pic//planewin//planewin1.bmp", 0);
			//iShowBMP2(plane2indx, plane2indy, "pic//planewin//planewin2.bmp", 0);
			iShowBMP2(plane2indx, plane2indy, "pic//planewin//planewin3.bmp", 0);
		}
	}
	else if (dx < 0)
	{
		if (lifelevel!=0)
			iShowBMP2(plane2indx, plane2indy, "pic//plane3.2.bmp", 0);
		else
			iShowBMP2(plane2indx, plane2indy, "pic//planewin//planewin3.2.bmp", 0);
	}

	//gameover ::::::::::::::::::
	if (lifelevel<1)
	iShowBMP2(200,300, "pic//Gameover.bmp", 0);

	else if (bulletindy > 485)
	{
		bulletindxlock = 0;
	}

	if (fireindx > 59)
	{
		fireindx = 0;
	}
	if (lifelevel == 0)
	{
		iShowBMP2(tank1indx+40, tank1indy, fire[fireindx++], 0);
	}
	


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	printf_s("%d %d\n",mx,my);
	//bombindx = mx;
	//bombindy = my;
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (lifelevel > 0)
		{
			if (bulletindxlock == 0)
			{
				bulletcontrol = 1;
				bulletindxlock = 1;
				tempbulletindx = tank1indx + 57;
			}
		}
		//printf("%d  %d\n", mx, my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 's')
	{

	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		if (1050>tank1indx)
		{
			if(lifelevel > 0)
				tank1indx += 5;
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (0 < tank1indx)
		{
			if (lifelevel>0)
				tank1indx -= 5;
		}
		
	}
	//place your codes for other keys here
}
void planecontrol2()
{
	
	if (plane2indx > 1040)
	{
		dx = dx* -1;
	}
	if (plane2indx <10)
	{
		dx = dx* -1;
	}
	
	if (lifelevel > 0)
	{

		plane2indx += dx;
	}
	else
	{
		/*
		if (plane2indy>300)
		plane2indy-=5;
		*/
		if (dx > 0)
		{
			plane2indx += 7;
			plane2indy += 2;
		}
		else
		{
			plane2indx -= 7;
			plane2indy += 2;
		}
	}

}
void bullettouchcontrol()
{
	if (bulletindy>plane2indy - 15)
	{
		if ((bulletindx + 35 > plane2indx) && (bulletindx + 35 < plane2indx + 182))
		{
			score = score++;
			hide_bullet = 1;
		}
	}
}

void bomb_blust()
{
	if (fire1ind >= 60)
	{
		fire1ind = 0;
	}
	iShowBMP2(400, 142, fire1[fire1ind++], 0);
}

void bomb_touch_control()
{
	if (bombindy < tank1indy+50)
	{
		if ((bombindx>tank1indx-10) && (bombindx < tank1indx+190))
		{
			//printf_s("yes\n");
			hide_bomb = 1;
			life = 1;
			touch ++;
			//lifelevel--;
		}
		
	}
}

void bomb_relieze()
{
	if (rel == 0)
	{
		rel = 1;
		bomblock = 1;
		touch = 0;
	}

}
//
int main()
{
	iSetTimer(1,planecontrol2);
	iSetTimer(1,bullettouchcontrol);
	iSetTimer(1500, bomb_relieze);
	iSetTimer(1, bomb_blust);
	//place your own initialization codes here.
	iInitialize(1243, 700, "Fighter Tank");
	return 0;
}
