#include "PathUtil.h"
#include "duilib/Utils/StringUtil.h"

namespace ui
{

DString PathUtil::NormalizeDirPath(const DString& strFilePath)
{
    try {
        DString dirPath(strFilePath);
        StringUtil::ReplaceAll(_T("/"), _T("\\"), dirPath);
        StringUtil::ReplaceAll(_T("\\\\"), _T("\\"), dirPath);
        fs::path dir_path(dirPath);
        dir_path = lexically_normal(dir_path);
        dirPath = dir_path.native();
        if (!dirPath.empty()) {
            //确保路径最后字符是分割字符
            auto cEnd = dirPath.back();
            if (cEnd != _T('\\') && cEnd != _T('/')) {
#ifdef DUILIB_PLATFORM_WIN
                dirPath += _T('\\');
#else
                dirPath += _T('/');
#endif
            }
        }
        return dirPath;
    }
    catch (...) {
        return strFilePath;
    }
}

DString PathUtil::NormalizeFilePath(const DString& strFilePath)
{
    try {
        DString tmp(strFilePath);
        StringUtil::ReplaceAll(_T("/"), _T("\\"), tmp);
        StringUtil::ReplaceAll(_T("\\\\"), _T("\\"), tmp);
        fs::path file_path(tmp);
        file_path = lexically_normal(file_path);
        tmp = file_path.native();
        return tmp;
    }
    catch (...) {
        return strFilePath;
    }
}

DString PathUtil::JoinFilePath(const DString& path1, const DString& path2)
{
    try {
        fs::path file_path(path1);
        file_path /= path2;
        file_path = lexically_normal(file_path);
        DString tmp = file_path.native();
        return tmp;
    }
    catch (...) {
        return DString();
    }
}

bool PathUtil::IsExistsPath(const DString& strFilePath)
{
    try {
        return fs::exists(strFilePath);
    }
    catch (...) {
        return false;
    }
}

bool PathUtil::IsRelativePath(const DString& strFilePath)
{
    try {
        return fs::path(strFilePath).is_relative();
    }
    catch (...) {
        return false;
    }
}

bool PathUtil::IsAbsolutePath(const DString& strFilePath)
{
    try {
        return fs::path(strFilePath).is_absolute();
    }
    catch (...) {
        return false;
    }
}

bool PathUtil::FilePathIsExist(const DString& filePath, bool bDirectory)
{
	try {
		auto fileStatus = fs::status(fs::path(filePath));
		if ((fileStatus.type() != fs::file_type::none) &&
			(fileStatus.type() != fs::file_type::not_found)) {
			if (bDirectory) {
				return fileStatus.type() == fs::file_type::directory;
			}
			else {
				return (fileStatus.type() == fs::file_type::regular) ||
					(fileStatus.type() == fs::file_type::symlink) ||
					(fileStatus.type() == fs::file_type::directory);
			}
		}
	}
	catch (...) {
	}
	return false;
}

bool PathUtil::CreateOneDirectory(const DString& filePath)
{
    bool bCreated = false;
    try {
        bCreated = fs::create_directory(fs::path(filePath));
    }
    catch (...) {
    }
    return bCreated;
}

bool PathUtil::CreateDirectories(const DString& filePath)
{
    bool bCreated = false;
    try {
        bCreated = fs::create_directories(fs::path(filePath));
    }
    catch (...) {
    }
    return bCreated;
}

DString PathUtil::GetCurrentModuleDirectory()
{
#ifdef DUILIB_PLATFORM_WIN
    DString dirPath;
    dirPath.resize(1024, 0);
    dirPath.resize(::GetModuleFileNameW(nullptr, &dirPath[0], (uint32_t)dirPath.size()));
    size_t nPos = dirPath.find_last_of(_T("/\\"));
    if (nPos != DString::npos) {
        dirPath = dirPath.substr(0, nPos);
#ifdef DUILIB_PLATFORM_WIN
        dirPath += _T('\\');
#else
        dirPath += _T('/');
#endif
    }
    else {
        dirPath.clear();
    }
    return dirPath;
#else
    DString path = std::filesystem::current_path().native();
    PathUtil::NormalizeDirPath(path);
    return path;
#endif
}

} // namespace ui
