#include "ZipCTL.h"
#include <filesystem>
#include <fstream>

using namespace std::tr2::sys;

ZipCTL::ZipCTL(std::string zfname, int flags) 
    : _zf{ zipOpen(zfname.data(), flags) }
{
}

ZipCTL::~ZipCTL() {
    zipCloseFileInZip(_zf);
    zipClose(_zf, "global_comment");
}

void ZipCTL::createZipFile(std::string fname) {
    zip_fileinfo info;
    memset(&info, 0, sizeof(zip_fileinfo));

    std::time_t tm = last_write_time(path(fname));
    struct tm* tdata = std::localtime(&tm);
    info.tmz_date.tm_year = tdata->tm_year;
    info.tmz_date.tm_mon = tdata->tm_mon;
    info.tmz_date.tm_mday = tdata->tm_mday;
    info.tmz_date.tm_hour = tdata->tm_hour;
    info.tmz_date.tm_min = tdata->tm_min;
    info.tmz_date.tm_sec = tdata->tm_sec;

    std::ifstream fp(fname, std::ios_base::binary);
    if (!fp) return;

    zipOpenNewFileInZip(_zf, fname.data(), &info, nullptr, 0, nullptr, 0, "comment", Z_DEFLATED, Z_DEFAULT_COMPRESSION);

    const int BUFSIZE = 1024;
    Bytef buf[1024];
    do {
        fp.read(reinterpret_cast<char*>(buf), BUFSIZE);
        std::size_t size = static_cast<std::size_t>(fp.gcount());
        zipWriteInFileInZip(_zf, buf, size);
    } while (!fp.eof());

}