#include <iomanip>
#include <iostream>
#include "timer.h"

using namespace std;

void showopts (void);
char getopt (void);
void timer_status (jod::Timer &);

int main (void)
{
	char c = '\0';
	jod::Timer a(50); // auto start
	jod::Timer t(a);  // auto start

	do
	{
		showopts ();
		c = getopt ();
		
		switch (c)
		{
		case 'p': t.pause (); break;
		case 'r': t.resume (); break;
		case 's': t.start (); break;
		case 'u': t.update (); break;
		default : break;
		}

		timer_status (t);
	}
	while (c != 'q');

	return 0;
}

void showopts (void)
{
	cout << "Test class Timer;" << endl
	     << "-----------------" << endl << endl
	     << "Choose opt:"       << endl
		 << "[c] Continue."     << endl
	     << "[s] Start time."   << endl
		 << "[p] Pause time."   << endl
		 << "[r] Resume time."  << endl
	     << "[u] Update time."  << endl
	     << "[q] Quit."         << endl
		 << "> ";
}

char getopt (void)
{
	char result;
	cin >> result;
	return tolower(result);
}

void timer_status (jod::Timer &t)
{
	const double div = 1000.;
	cout << endl
	     << "\tInterval: " << t.getInterval () << endl
	     << "\tIs running: " << (t.running () ? "yes" : "no") << endl
	     << "\tElapsed time: " << fixed << setprecision(3) << t.elapsed () / div
	     << " s." << endl << endl;
}

