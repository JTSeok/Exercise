#include <zip.h>
#include <string>
#include <fstream>

class ZipCTL {
private:
    zipFile _zf;
public:
    ZipCTL(std::string zfname, int flags = APPEND_STATUS_CREATE);
    ~ZipCTL();

    void createZipFile(std::string fname);
};