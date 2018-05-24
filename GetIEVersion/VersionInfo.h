#include "stdafx.h"
#include <iostream>
#include <string>


/** �汾��Ϣ
*/
class  CVersionInfo
{
public:
    /** ���汾��
    */
    DWORD m_major;

    /** �ΰ汾��
    */
    DWORD m_minor;

    /** �ٴΰ汾��
    */
    DWORD m_lowest;

    /** �����汾��
    */
    DWORD m_revision;

public:

    /** ���캯��
    */
    CVersionInfo();

public:

    /** �����汾��
    @param [in] strVersion �汾���ַ����� �����ĸ�ʽΪ�Ķΰ汾�Ÿ�ʽ��1.2.3.456
    */
    bool ParseVersionInfo(const std::wstring& strVersion);

    /** ����һ���汾��Ϣ
    @param [in] major ���汾��
    @param [in] minor �ΰ汾��
    @param [in] lowest ����λ�汾��
    @param [in] revision ���������汾��
    */
    void InitVersionInfo(DWORD major, DWORD minor, DWORD lowest, DWORD revision);

public:

    /** �汾�Ƚ�
    */
    bool operator < (const std::wstring& other) const;

    /** �汾�Ƚ�
    */
    bool operator <= (const std::wstring& other) const;

    /** �汾�Ƚ�
    */
    bool operator == (const std::wstring& other) const;

    /** �汾�Ƚ�
    */
    bool operator != (const std::wstring& other) const;

public:

    /** ���ɰ汾��ʾ�ַ���(�������λΪ0����ʾ), ��ʽΪ: V1.2 (Build 123) �� V1.2.1 (Build 123)
    @return ���ɰ汾��ʾ�ַ���
    */
    std::wstring Format() const;

    /** ���ɰ汾��ʾ�ַ���, ��ʽΪ: 1.2.0.123
    @return ���ɰ汾��ʾ�ַ���
    */
    std::wstring DetailVersion() const;
};