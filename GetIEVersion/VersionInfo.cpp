
#include "stdafx.h"
#include "VersionInfo.h"
#include <winver.h>
#pragma comment(lib,"Version.lib") 

CVersionInfo::CVersionInfo()
{

}
void CVersionInfo::InitVersionInfo(DWORD major, DWORD minor, DWORD lowest, DWORD revision)
{
    m_major = major;
    m_minor = minor;
    m_lowest = lowest;
    m_revision = revision;
}
bool CVersionInfo::ParseVersionInfo(const std::wstring& strVersion)
{
    InitVersionInfo(0,0,0,0);
    const TCHAR* szFilename = strVersion.c_str();
    DWORD dwHandle = 0;
    // 判断容纳文件版本信息需要一个多大的缓冲区 
    DWORD dwVerInfoSize = ::GetFileVersionInfoSize(szFilename, &dwHandle);
    if (0 == dwVerInfoSize)
    {
        return 0;
    }
    // 从堆中分配指定大小的字节数  
    LPVOID lpBuffer = ::LocalAlloc(LPTR, dwVerInfoSize);
    if (0 == lpBuffer)
    {
        return 0;
    }
    // 从支持版本标记的一个模块里获取文件版本信息  
    if (::GetFileVersionInfo(szFilename, dwHandle, dwVerInfoSize, lpBuffer))
    {
        VS_FIXEDFILEINFO * lpFixedFileInfo = NULL;
        UINT nFixedFileInfoSize = 0;
        if (::VerQueryValue(lpBuffer, TEXT("\\"), (LPVOID*)&lpFixedFileInfo, &nFixedFileInfoSize) && (nFixedFileInfoSize))
        {
            // 从版本资源中获取信息  
            m_major = HIWORD(lpFixedFileInfo->dwFileVersionMS); 
            m_minor = LOWORD(lpFixedFileInfo->dwFileVersionMS);
            m_lowest = HIWORD(lpFixedFileInfo->dwFileVersionLS);  
            m_revision = LOWORD(lpFixedFileInfo->dwFileVersionLS);
        }
    }
    ::LocalFree(lpBuffer);
    return 0;
}

std::wstring CVersionInfo::Format() const
{

    std::wstring a;
    return a;
}

std::wstring CVersionInfo::DetailVersion() const
{
    TCHAR buf[1024] = { 0 };
    ::swprintf_s(buf, _T("%d.%d.%d.%d"), m_major, m_minor, m_lowest, m_revision);
    std::wstring strVersion(buf);
    return strVersion;
}