#ifndef WINDOWSPATHUTIL_H
#define WINDOWSPATHUTIL_H

#include "qtutils_global.h"
#include <QObject>
#include <QString>
#include <qt_windows.h>
#include <shlobj.h>

namespace QtUtils
{
	struct DeCoInitializer
	{
		DeCoInitializer()
			: neededCoInit(CoInitialize(nullptr) == S_OK)
		{
		}

		~DeCoInitializer()
		{
			if (neededCoInit)
				CoUninitialize();
		}

		bool neededCoInit;

		void noWarrning()
		{
		}
	};

	class QTUTILS_EXPORT WindowsPathUtil
	{
	public:
		//�û�Ŀ¼����ʱĿ¼������QDir��ȡ
		enum SYSTEMPATH
		{
			UserDeskTopPath = CSIDL_DESKTOPDIRECTORY,//����
			UserDocumentsPath = CSIDL_PERSONAL,//�ҵ��ĵ�
			UserMusicPath = CSIDL_MYMUSIC,//�ҵ�����
			UserVideoPath = CSIDL_MYVIDEO,//�ҵ���Ƶ
			UserPricturesPath = CSIDL_MYPICTURES,//�ҵ�ͼƬ
			UserFavoritesPath = CSIDL_FAVORITES,//�ҵ��ղ�
			UserAppDataPath = CSIDL_APPDATA,//��ǰ�û����ض���Ӧ�ó������ݴ洢�ļ���
			UserLocalAppDataPath = CSIDL_LOCAL_APPDATA,//��ʾ��ǰ�û���Ӧ�ó��������ļ��У����磺C:\Documents and Settings\username\Local Settings\Application Dat
			UserNetHoodPath = CSIDL_NETHOOD,//��ʾ��ǰ�û����ڵ��������ӵ��ļ��У����磺C:\Documents and Settings\username\NetHood
			UserPrintHoodPath = CSIDL_PRINTHOOD,//��ʾ��ǰ�û����ڵ������ӡ���������ļ��У����磺C:\Documents and Settings\username\PrintHood

			UserStartMenuPath = CSIDL_STARTMENU,//�û���ʼ�˵�
			UserStartMenuProgramsPath = CSIDL_PROGRAMS,//�û���ʼ����˵�
			UserStartUpPath = CSIDL_STARTUP,//����Ŀ¼
			UserSentTo = CSIDL_SENDTO,//��ʾ��ǰ�û��ġ����͵����ļ��У����磺C:\Documents and Settings\username\SendTo

			AdminToolsPath = CSIDL_COMMON_ADMINTOOLS,//��ʾ�����û��ġ������ߡ�ϵͳ�ļ���
			CommonAppData = CSIDL_COMMON_APPDATA,//��ʾ�����û����ض���Ӧ�ó������ݴ洢�ļ���,����:C:\Documents and Settings\All Users\Application Data
			CommonDeskTopPath = CSIDL_COMMON_DESKTOPDIRECTORY,//��ʾ�����û��ġ����桱�ļ��У����磺C:\Documents and Settings\All Users\Desktop��
			CommonDocumentsPath = CSIDL_COMMON_DOCUMENTS,//��ʾ�����û��ġ��ҵ��ĵ����ļ��У�����:C:\Documents and Settings\All Users\Documents
			CommonFavoritesPath = CSIDL_COMMON_FAVORITES,//��ʾ�����û��ġ��ҵ��ղؼС��ļ��С�
			CommonMusicPath = CSIDL_COMMON_MUSIC,// �������� 0x0035
			CommonPricturesPath = CSIDL_COMMON_PICTURES,// ����ͼƬ0x0036
			CommonVideoPath = CSIDL_COMMON_VIDEO,//������Ƶ 0x0037
			CommonStartMenuProgramsPath = CSIDL_COMMON_PROGRAMS,//��ʾ�����û��ġ������ļ��У����磺C:\Documents and Settings\All Users\Start Menu\Programs
			CommonStartMenuPath = CSIDL_COMMON_STARTMENU,//��ʾ�����û��ġ���ʼ�˵����ļ��У����磺C:\Documents and Settings\All Users\Start Menu
			CommonStartUpPath = CSIDL_COMMON_STARTUP,//��ʾ�����û��ġ��������ļ��У����磺C:\Documents and Settings\All Users\Start Menu\Programs\Startup
			CommonTemplantesPath = CSIDL_COMMON_TEMPLATES,//��ʾ�����û��ġ�ģ�顱�ļ��У����磺C:\Documents and Settings\All Users\Templates

			IECookiesPath = CSIDL_COOKIES,//��ʾ��ǰ�û�Internet Explorer��cookie �ļ��У����磺C:\Documents and Settings\username\Cookies
			IEHistoryPath = CSIDL_HISTORY,//��ʾInernet Explorer�ġ���ʷ��¼���ļ���
			IECachePath = CSIDL_INTERNET_CACHE,//��ʾ��ǰ�û���Internet Explorer��"Cache"�ļ��У����磺C:\Documents and Settings\username\Temporary Internet Files

			TemplantesPath = CSIDL_TEMPLATES,//ģ��Ŀ¼
			FontsPath = CSIDL_FONTS,//����Ŀ¼
			ProgramFilesPath = CSIDL_PROGRAM_FILES,//��ʾ�����ļ����ļ��У����磺C:\Program Files
			ProgramFilesCommonPath = CSIDL_PROGRAM_FILES_COMMON,//��ʾϵͳ����������ļ��У����磺C:\Program Files\Common
			SystemPath = CSIDL_SYSTEM,//��ʾWINDOWSϵͳ��ϵͳ�ļ��У����磺C:\WINNT\SYSTEM32
			WindowsPath = CSIDL_WINDOWS //��ʾ����ϵͳ��WindowsĿ¼���ļ��䣬���磺C:\WINNT
		};

		static bool createLink(const QString& fileName, const QString& linkName,
							   const QString& arguments = QString(), const QString& iconPath = QString(),
							   const QString& iconId = QString());//������ݷ�ʽ��Դ�ļ���������������path

		static QString getWinSysDir(SYSTEMPATH path);//��ȡϵͳ��·��

	private:
		WindowsPathUtil()
		{
		}
	};
}
#endif // WINDOWSPATHUTIL_H


