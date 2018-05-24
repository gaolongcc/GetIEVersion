#include "stdafx.h"
#include <iostream>
#include <string>


/** 版本信息
*/
class  CVersionInfo
{
public:
    /** 主版本号
    */
    DWORD m_major;

    /** 次版本号
    */
    DWORD m_minor;

    /** 再次版本号
    */
    DWORD m_lowest;

    /** 修正版本号
    */
    DWORD m_revision;

public:

    /** 构造函数
    */
    CVersionInfo();

public:

    /** 解析版本号
    @param [in] strVersion 版本号字符串， 期望的格式为四段版本号格式：1.2.3.456
    */
    bool ParseVersionInfo(const std::wstring& strVersion);

    /** 构造一个版本信息
    @param [in] major 主版本号
    @param [in] minor 次版本号
    @param [in] lowest 第三位版本号
    @param [in] revision 代码变更集版本号
    */
    void InitVersionInfo(DWORD major, DWORD minor, DWORD lowest, DWORD revision);

public:

    /** 版本比较
    */
    bool operator < (const std::wstring& other) const;

    /** 版本比较
    */
    bool operator <= (const std::wstring& other) const;

    /** 版本比较
    */
    bool operator == (const std::wstring& other) const;

    /** 版本比较
    */
    bool operator != (const std::wstring& other) const;

public:

    /** 生成版本显示字符串(如果第三位为0则不显示), 格式为: V1.2 (Build 123) 或 V1.2.1 (Build 123)
    @return 生成版本显示字符串
    */
    std::wstring Format() const;

    /** 生成版本显示字符串, 格式为: 1.2.0.123
    @return 生成版本显示字符串
    */
    std::wstring DetailVersion() const;
};