#include <Arduino.h>
#include <PMS.h>

class PMSReader{
    public:
        PMSReader();
        float getPM25Data();
};