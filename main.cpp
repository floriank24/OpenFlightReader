
#include "OpenFlight/DotExporter.h"
#include "OpenFlight/OpenFlightReader.h"
#include <iostream>
#include <string>

using namespace std;

//class MyDocument
//{
//public:
//    MyDocument(const Document&) = delete;
//    MyDocument& operator=(const Document&) = delete;
//    virtual ~MyDocument() {;}
//    
//protected:
//    
//};


int main(int argc, char** argv)
{
    OpenFlight::OpenFlightReader ofr;
    ofr.enableDebug(true);

    //string filenamePath = "../assets/sample/nested_references/master/master.flt";
    //string filenamePath = "../assets/sample/nested_references2/db/1/1.flt";
    string filenamePath = "../assets/sample/nested_references2/db/1/12/123/1234/1234.flt";
    
    //string filenamePath = "G:\CYYZ-Toronto/main_CYYZ.flt";

    OpenFlight::HeaderRecord *pDoc = ofr.open( filenamePath );
    if ( !ofr.hasErrors() )
    {
        if(ofr.hasWarnings())
        { cout << "Warnings: " << ofr.getAndClearLastWarnings() << endl; }
        
        cout << OpenFlight::toDotFormat( pDoc );
    }
    else
    { cout << "Errors while reading flt file: " << filenamePath << "\n" <<  ofr.getAndClearLastErrors(); }
    
    delete pDoc;

    return 0;
}