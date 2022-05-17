#ifndef STATEMENT_H
#define STATEMENT_H
#include "fstream"
#include "..\defs.h"
#include "Connector.h"
//class Output;
#include "..\GUI\Output.h"

//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID
	string Text;	//Statement text (e.g.  "X = 5" OR "if(salary > 3000)" and so on )
	bool Selected=false;	//true if the statement is selected on the folwchart
	string type;
	int width;
	int height;
	Point Inlet;
	Point Outlet;
	bool Connected = false;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.
static int count;
public:
	Statement();
	void SetSelected(bool s = false);
	bool IsSelected() const;

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	bool CheckStatement(Point p);
	virtual Point getstatmentposition() ;
	virtual string gettype();
	virtual int getheight();
	virtual int getwidth();
	virtual Point getInlet();
	virtual Point getOutlet();
	virtual Point getOutletyes();
	virtual Point getOutletno();
	virtual void unselectstat();
	static int Getcount();
	int GetID();
	bool GetConnected();
	virtual Connector* Getconnect();
     ///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type	


	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file


	//virtual void Move() = 0;		//Move the Statement on the flowchart
	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file
	//virtual void Simulate();	//Execute the statement in the simulation mode


	//virtual void PrintInfo(Output* pOut) = 0;	//print all Statement info on the status bar
	
	///TODO: Add more functions if needed
};

#endif