#include <jni.h>
#include <string>
#include <utils/file.hpp>
#include <build/builder.hpp>
#include <parser/header.hpp>
#include <parser/entry.hpp>
#include <encryption.hpp>


extern "C"
JNIEXPORT void JNICALL
Java_eternal_future_silkcasket_MainActivity_func(JNIEnv *env, jobject thiz) {

    SilkCasket::Build::Builder::Build A;
    A.build("/sdcard/Android/data/eternal.future.silkcasket/files/TRLanguage",
            "/sdcard/Android/data/eternal.future.silkcasket/files/信息加密.silkc",
            {true, false, false, true, false},
            {false, true},
            "SilkCasket"
            );



    /*
    using namespace SilkCasket;
    auto a = "/sdcard/Android/data/eternal.future.silkcasket/files/a.silk";


    auto b = FileStructure::deserializeHeader(
            Utils::File::readFileAddress(a,
                0,
                73
            )
    );


    auto c = FileStructure::deserializeEntryData(Utils::File::readFileAddress(a, b.entryData.offset, b.entryData.size));

    auto d = Utils::File::readFileAddress(a, c.Address.at(0).offset, c.Address.at(0).size);

    std::string str(reinterpret_cast<const char*>(d.data()), d.size());
    LOG(SilkCasket::LogLevel::INFO, "文件信息：" +
            str
    );
     */


 }