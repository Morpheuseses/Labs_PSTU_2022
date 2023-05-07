#pragma once
const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmShow = 4; // s
const int cmMake = 6;
const int cmQuit = 101; 
const int cmGet = 75; // z

struct TEvent
{
	int what;
	union {
		int command;
		struct {
			int message;
			int param;
		};
	};
};