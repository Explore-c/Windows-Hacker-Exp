#include <Windows.h>
#include "HOOK.H"

//����HOOK
void MYWINDAPIEXPORT SetHook()
{
    //������HOOK������ Hook�Ļص���ַ ģ���� �߳�ID(0������ȫ�ֹ���)
    g_HookProc = ::SetWindowsHookEx(WH_CBT, MyProc, 
        GetModuleHandle(TEXT("GlobalHook_Test.dll")), 0); 
}

//ȡ��HOOK
void MYWINDAPIEXPORT UnHook()                                                                    
{
    if (NULL != g_HookProc) {
        ::UnhookWindowsHookEx(g_HookProc);
    }
}

//�ص����� �������
LRESULT CALLBACK MyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    //ִ�����ǵĳ���
    MessageBox(NULL, "���ع���!", "��ʾ", MB_OK);
    //�������ù��ӹ���
    return CallNextHookEx(g_HookProc, nCode, wParam, lParam);
}