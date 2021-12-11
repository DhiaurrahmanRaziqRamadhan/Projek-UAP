#include <iostream>
#include <ncurses.h>
#include <windows.h>
#include <string.h>
#include <time.h>
using namespace std;

char pilih,ulang;

int computer, ipilih,iulang;

int height = 10;
int width  = 42;
int startX = 39;
int startY = 10;

string pilihan[3]={"Gunting","Batu","Kertas"};

int main();

void main_menu(){
	WINDOW * win = newwin(height,width,startY,startX);
	start_color();
	init_pair(1,COLOR_CYAN,COLOR_BLACK);
	wattron(win,COLOR_PAIR(1));
	box(win,0,0);
	refresh();
	
	mvwprintw(win,1,1,"========================================");
	mvwprintw(win,2,1,"       Selamat datang di Game Suit      ");
	mvwprintw(win,3,1,"========================================");
	mvwprintw(win,4,1,"| 1 |             %s              |",pilihan[0].c_str());
	mvwprintw(win,5,1,"| 2 |             %s                 |",pilihan[1].c_str());
	mvwprintw(win,6,1,"| 3 |             %s               |",pilihan[2].c_str());
	mvwprintw(win,7,1,"Silahkan pilih antara | 1 | 2 | 3 | -> ");
	
	pilih = wgetch(win);
	
	ipilih = pilih -'0'; //conver dari char ke int untuk variabel pilih
	ipilih = ipilih - 1;
	mvwprintw(win,8,1,"Anda memilih %s", pilihan[ipilih].c_str());	
	wrefresh(win);
	Sleep(1000);
}

void loading(){
	WINDOW * win = newwin(height,width,startY,startX);
	start_color();
	init_pair(1,COLOR_CYAN,COLOR_BLACK);
	wattron(win,COLOR_PAIR(1));
	box(win,0,0);
	refresh();
	
	//LOADING START//
	for(int i=0;i<5;i++){
	wclear(win);
	box(win,0,0);
	refresh();
	
	mvwprintw(win,height/2,width/2 - 5,"Loading");
	mvwprintw(win,height/2,width/2 - 5,"Loading.");
	wrefresh(win);
	Sleep(100);
	mvwprintw(win,height/2,width/2 - 5,"Loading..");
	Sleep(100);
	mvwprintw(win,height/2,width/2 - 5,"Loading...");
	wrefresh(win);
	Sleep(100);
	wclear(win);
		
	//LOADING END//
	}
}

void hasil(){
	WINDOW * win = newwin(height,width,startY,startX);
	start_color();
	init_pair(1,COLOR_CYAN,COLOR_BLACK);
	wattron(win,COLOR_PAIR(1));
	box(win,0,0);
	refresh();
	
	
		if(pilih=='1')
	{
		mvwprintw(win,1,1,"========================================");
		mvwprintw(win,2,1,"           Hasil Pertandingan           ");
		mvwprintw(win,3,1,"========================================");
		mvwprintw(win,4,1,"Anda memilih gunting");
		wrefresh(win);
		srand(time(0));	// bilangan random/acak setiap di run
		computer = 1 + rand()%3;
		if(computer==1)
			{
				mvwprintw(win,5,1,"Lawan memilih gunting");
				mvwprintw(win,6,1,"Seri");
			}
		else if(computer==2)
			{
				mvwprintw(win,5,1,"Lawan memilih batu");
				mvwprintw(win,6,1,"kalah");
			}
		else
			{
				mvwprintw(win,5,1,"Lawan memilih kertas");
				mvwprintw(win,6,1,"menang");
			}
		wrefresh(win);	
	}
	else if(pilih=='2')
	{
		mvwprintw(win,1,1,"========================================");
		mvwprintw(win,2,1,"           Hasil Pertandingan           ");
		mvwprintw(win,3,1,"========================================");
		mvwprintw(win,4,1,"Anda memilih batu");
		wrefresh(win);
		srand(time(0));	// bilangan random/acak setiap di run
		computer = 1 + rand()%3;
		if(computer==1)
			{
				mvwprintw(win,5,1,"Lawan memilih gunting");
				mvwprintw(win,6,1,"Menang");
			}
		else if(computer==2)
			{
				mvwprintw(win,5,1,"Lawan memilih batu");
				mvwprintw(win,6,1,"Seri");
			}
		else
			{
				mvwprintw(win,5,1,"Lawan memilih kertas");
				mvwprintw(win,6,1,"Kalah");
			}
		wrefresh(win);	
	}
	else if(pilih=='3')
	{
		mvwprintw(win,1,1,"========================================");
		mvwprintw(win,2,1,"           Hasil Pertandingan           ");
		mvwprintw(win,3,1,"========================================");
		mvwprintw(win,4,1,"Anda memilih kertas");
		wrefresh(win);
		srand(time(0));	// bilangan random/acak setiap di run
		computer = 1 + rand()%3;
		if(computer==1)
			{
				mvwprintw(win,5,1,"Lawan memilih gunting");
				mvwprintw(win,6,1,"Kalah");
			}
		else if(computer==2)
			{
				mvwprintw(win,5,1,"Lawan memilih batu");
				mvwprintw(win,6,1,"Menang");
			}
		else
			{
				mvwprintw(win,5,1,"Lawan memilih kertas");
				mvwprintw(win,6,1,"Seri");
			}
		wrefresh(win);	
	}
	else
	{
		mvwprintw(win,height/2,width/2 - 16,"Inputan anda salah");
		wrefresh(win);	
	}
	
	mvwprintw(win, 8,1,"Ketik 0 untuk mengulang");
	ulang = wgetch(win);
	
	iulang = ulang -'0'; //conver dari char ke int untuk variabel pilih
	if(iulang==0)
	{
		wclear(win);
		main();
	}else{
		wclear(win);
		WINDOW * win = newwin(height,width,startY,startX);
		start_color();
		init_pair(1,COLOR_CYAN,COLOR_BLACK);
		wattron(win,COLOR_PAIR(1));
		box(win,0,0);
		refresh();
		
		mvwprintw(win, height/2,13,"Program Berakhir");
		wrefresh(win);
		Sleep(1000);
	}
}

int main(){
	//NCURSES START//
	
	initscr(); //menginialisasi screen
	
	main_menu(); //membuat menu utama
	
	loading(); //membuat fungsi loading
	
	hasil(); // hasil gamenya
	
	endwin();
	return 0;
	//NCURSES END//
}

