#pragma once

#include "OpCode.h"
#include <string>

namespace OpenFlight
{
    class Record
    {
    public:
        Record() = delete;
        Record(Record* ipParent);
        Record(const Record&) = delete;
        Record& operator=(const Record&) = delete;
        virtual ~Record();
        
        opCode getOpCode() const { return mOpCode; }
        Record* getParent() const { return mpParent; }
        int getRecordLength() const {return mRecordLenght; }
        
    protected:
        /*Since the reader creates and manages the parsing of the
         records, he is friend.*/
        friend class OpenFlightReader;
        
        virtual bool parseRecord(const std::string& iRawRecord, int iVersion);
        
        void setParent(Record* iParent);
        
        opCode mOpCode;
        uint16_t mRecordLenght;
        Record* mpParent;
    };
}