#include<SDL.h>
#include <iostream>
#include <math.h>
#include <locale.h>
#define SCREEN_WEIGHT	1280
#define SCREEN_HEIGHT	1024

using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL error:" << SDL_GetError() << endl;
	}
	else
	{
		SDL_Window* windowsss = NULL;

		windowsss = SDL_CreateWindow(u8"Never be among", 200, 100, SCREEN_WEIGHT, SCREEN_HEIGHT, 0);
		if (windowsss == NULL)
		{
			cout << "SDL error:" << SDL_GetError() << endl;
		}
		else
		{
			SDL_Renderer* renderersss = SDL_CreateRenderer(windowsss, -1, 0);

			SDL_SetRenderDrawColor(renderersss, 255, 255, 255, 0);
			SDL_RenderClear(renderersss);
			
			double b,a;
			do
			{
				cout << "Введите коэффициенты a,b для задания эллиптической орбиты (формула эллипса x^2/a^2 + y^2/b^2 = 1)"<<endl;
				cout << "Введите коэффициент a," << endl;
				cin >> a;
				cout << "Введите коэффициент b," << endl;
				cin >> b;
			} while (a == 0 || b == 0);
			//Введите скорости движения окружности
			
			SDL_SetRenderDrawColor(renderersss, 120, 80, 7, 0);


			double angle = 0;
			double x, y;
/*			//Первая точка (эллиппс)
			for (int angle = 0; angle < 360; angle += 1)
			{
				x = 50* a * cos(angle)+ SCREEN_WEIGHT / 2;
				y = 50* b * sin(angle)+ SCREEN_HEIGHT / 2;
				SDL_RenderDrawPoint(renderersss, x, y);
/*			}
/*			//Вторая точка (эллиппс)
			for (int angle = 0; angle < 360; angle += 1)
			{
				x = 100 * a * cos(angle) + SCREEN_WEIGHT / 2;
				y = 100 * b * sin(angle) + SCREEN_HEIGHT / 2;
				SDL_RenderDrawPoint(renderersss, x, y);
			}
*/
			//Эллипс
			for (double angle = 0; angle < 720; angle += 0.5)
			{
				for (int angle3 = 0; angle3 < 360; angle3 += 1)
				{
					x = 30 * a * cos(angle3) + SCREEN_WEIGHT / 2;
					y = 30 * b * sin(angle3) + SCREEN_HEIGHT / 2;
					SDL_RenderDrawPoint(renderersss, x, y);
				}
				for (int angle1 = 0; angle1 < 360; angle1 += 1)
				{
					x = 20 * a * cos(angle1) + SCREEN_WEIGHT / 2 + 30 * a * cos(angle);
					y = 20 * a * sin(angle1) + SCREEN_HEIGHT / 2 + 30 * b * sin(angle);
					SDL_RenderDrawPoint(renderersss, x, y);
				}
				for (int angle2 = 0; angle2 < 360; angle2 += 1)
				{
					x = 10 * b * cos(angle2) + SCREEN_WEIGHT / 2 + 30 * a * cos(angle+300);
					y = 10 * b * sin(angle2) + SCREEN_HEIGHT / 2 + 30 * b * sin(angle+300);
					SDL_RenderDrawPoint(renderersss, x, y);
				}

				SDL_RenderPresent(renderersss);
				SDL_Delay(120);
				SDL_SetRenderDrawColor(renderersss, 255, 255, 255, 0);
				SDL_RenderClear(renderersss);
				SDL_SetRenderDrawColor(renderersss, 120, 80, 7, 0);

			}
			SDL_RenderPresent(renderersss);

			SDL_Delay(5000);
			SDL_DestroyRenderer(renderersss);
			SDL_DestroyWindow(windowsss);
		}
	}
	SDL_Quit();
	return 0;
}
