﻿#pragma once
#include <string>
#include <random>

enum class PCBStatus
{
	Error = -1,
	New = 0,
	Waiting = 1,
	Ready = 2,
	Running = 3,
	Terminated = 4,
	//Dummy = 5
};

class PCB
{
public:
	std::string processName;
	int processID;
	PCBStatus status;
	//===== PROCESSOR CONTROL ======
	uint8_t estimatedTime = 0;
	//===== INTEPRETER =====
	uint8_t AX = 0, BX = 0, CX = 0, DX = 0;
	uint8_t insnIndex = 0;
	uint8_t insnCounter = 0;
	//===== MEMORY CONTROL =====
	std::vector<uint8_t> pages;/*tablica stronic procesu znajdującego się w PCB*/
	unsigned int sizePageProcess = 16; /*rozmiar strony*/
	//===== FILE CONTROL =====

	//===== LOCK CONTROL =====
	//Absolutna cisza w samym �rodku szalej�cego �ywio�u. 

	PCB();
	PCB(std::string name, int ID, PCBStatus processStatus);

	~PCB() = default;

	std::string showProcess() const;

	int getPID() const;
	PCBStatus getStatus() const;
	void changeStatus(PCBStatus status);

	/*
	 * PCB - konstruktor
	 *
	 * showProcess - metoda wy�wietlaj�ca w�asno�ci wybranego procesu
	 * getPID - metoda zwracaj�ca ID wybranego procesu
	 * changeStatus - metoda zmieniaj�ca status wybranego procesu
	 */
};

int randomPID(int min, int max);
