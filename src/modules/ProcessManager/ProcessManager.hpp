#pragma once
#include "PCB.hpp"
#include <vector>
#include <memory>
#include <string>

class Shell;

class ProcessManager {
	using PCB_ptr = std::shared_ptr<PCB>;

	std::vector<PCB_ptr> processList;
	std::vector<PCB_ptr> readyQueue;
public:
	ProcessManager(Shell *shell);
	~ProcessManager() = default;

	PCB_ptr createProcess(std::string name, std::string programName);
	PCB_ptr createDummyProcess();
	
	int getNextPID();
	Shell *shell;

	std::vector<PCB_ptr>& getReadyQueue();
	std::vector<PCB_ptr>& getProcessList();

	static std::string showChosenProcess(PCB_ptr process);
	std::string showProcessList();
	std::string showReadyQueue();
	std::string showPriority();
	std::string showProcessPages(int pid);

	void deleteProcessFromList(int pid);
	void deleteProcessFromQueue(int pid);

	void addProcessToList(PCB_ptr process);
	void addProcessToQueue(PCB_ptr process);

	PCB_ptr getProcessFromList(std::string processName);
	PCB_ptr getProcessFromList(int PID);

	PCBStatus convertStringToPCBStatus(std::string& processStatusName) const;


	void changeStatusChosenProcess(int pid, PCBStatus sts);
	/*
	 * processList - vector wszystkich procesow: nowych, oczekuj�cych itd.
	 * readyQueue - vector procesow gotowych
	 *
	 * createProcess - metoda dodaj�ca proces do listy wszystkich proces�w
	 * getNextPID - metoda generuj�ca niepowtarzalny numer ID
	 *
	 * getReadyQueue - metoda zwracaj�ca referencj� do kolejki procesow gotowych
	 * getProcessList - metoda zwracaj�ca referencj� do kolejki wszystkich procesow
	 *
	 * showChosenProcess - metoda wy�wietlaj�ca proces o podanej nazwie
	 * showProcessList - metoda wyswietlajaca list� wszystkich proces�w
	 * showReadyQueue - metoda wyswietlaj�ca kolejk� procesow gotowych
	 * deleteProcessFromList - metoda usuwaj�ca proces o podanym ID
	 * deleteProcessFromQueue - metoda usuwaj�ca proces o podanym ID
	 * addProcessToList - metoda dodaj�ca wybrany proces do listy
	 * getProcessFromList - metoda zwracaj�ca proces o podanej nazwie
	 * changeStatusChosenProcess - metoda zmieniaja status procesu wybranego z listy
	 */
};
