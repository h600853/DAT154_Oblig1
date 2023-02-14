// Oblig1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Oblig1.h"
#include <queue>;
#include <vector>;
#include <cstdlib>


using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
int state = 0;
int statelys2 = 0;
BOOL LCar = false;
BOOL DCar = false;
BOOL forbiveikryss = false;
BOOL forbiveikryss2 = false;
POINT position = {0, 0};
POINT position2 = {0, 0};
vector<POINT> carvector;
vector<POINT> carvector2;
BOOL makecar = false;
int randomnumber = 0;
int pw = 0;
int pn = 0;
int waitthreeseconds1 = 0;
int waitthreeseconds2 = 0;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    myDlg(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OBLIG1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OBLIG1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OBLIG1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OBLIG1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_LEFT:
        {
            if (pw >= 10 ) {
                pw -= 10;
            }

        }
        break;
        case VK_RIGHT:
        {
            if (pw <= 90) {
                pw += 10;
            }
        }
        break;
        case VK_UP:
        {
            if (pn <= 90) {
                pn += 10;
            }
        }
        break;
        case VK_DOWN:
        {
            if (pn >= 10) {
                pn -= 10;
            }
        }
        break;
        }
    }
     break;
    case WM_LBUTTONDOWN: 
    {
      /* PART 2
        state += 1;
        if (state == 5) {
            state = 1;
        }
        statelys2 += 1;
        if (statelys2 == 5) {
            statelys2 = 1;
        }
        InvalidateRect(hWnd, 0, true);
      */ 
  //PART4
       /*
        position.x = 0;
        position.y = 0;
        carvector.push_back(position);
        */
        
        

    }
    break;
   /*
    case WM_LBUTTONUP:
    {
        makecar = false;
    }
    break;
   */
    case WM_RBUTTONDOWN: 
    {
        //PART4
        /*
        position2.x = 0;
        position2.y = 0;
        carvector2.push_back(position2);
        */

       
    }
    break;
    case WM_CREATE: 
    {

        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, myDlg);

        //traffic lights
        SetTimer(hWnd, 0, 3000, 0);
        //cars left to right
        SetTimer(hWnd, 1, 100, 0);
        //cars down to bottom 
        SetTimer(hWnd, 2, 100, 0);
        //add left to right car if probability hits
        SetTimer(hWnd, 3, 1000, 0);
        //add top to bottom car if probability hits
        SetTimer(hWnd, 4, 1000, 0);
 
    }
    break;
    case WM_TIMER: 
    {
      
        switch (wParam)
        {
        case 0: {

            state += 1;
            if (state == 5) {
                state = 1;
            }
            statelys2 += 1;
            if (statelys2 == 5) {
                statelys2 = 1;
            }
            InvalidateRect(hWnd, 0, true);
        }
              break;
        case 1:
        {
         
            for (auto i = 0; i < carvector.size(); i++) {
                if (carvector[i].y == 600 && (statelys2 == 3 || statelys2 == 4)) {

                }
                else {
                    BOOL valid = true;
                    for (auto c : carvector) {
                        if (c.x > carvector[i].y && c.x <= carvector[i].y + 60) {
                            valid = false;
                        }
                    }
                    if (valid) {
                        carvector[i].x += 10;
                        carvector[i].y += 10;
                    }
                    if (carvector[i].x > 1500)
                    {
                        carvector.erase(carvector.begin() + i);
                    }

                }
                InvalidateRect(hWnd, 0, true);
            }



            
        }
        break;
        case 2:
        {
            
            for (auto i = 0; i < carvector2.size(); i++) {
                if (carvector2[i].y == 300 && (state == 1 || state == 2)) {

                }
                else {
                    BOOL valid = true;
                    for (auto c : carvector2) {
                        if (c.x > carvector2[i].y && c.x <= carvector2[i].y + 60) {
                            valid = false;
                        }
                    }
                    if (valid) {
                        carvector2[i].x += 10;
                        carvector2[i].y += 10;
                    }
                }
                if (carvector2[i].x > 1000)
                {
                    carvector2.erase(carvector2.begin() + i);
                }
            }
            InvalidateRect(hWnd, 0, true);


        }
        break;
        case 3: 
        {
            waitthreeseconds1++;
            if (waitthreeseconds1 >= 3)
            {

            if (rand() % 100 <= pw) {
            position.x = 0;
            position.y = 0;
            carvector.push_back(position);

            }
            }

        }
        break;
        case 4:
        {
            waitthreeseconds2++;
            if (waitthreeseconds2 >= 3) {

            if (rand() % 100 <= pn) {
                position2.x = 0;
                position2.y = 0;
                carvector2.push_back(position2);
            }

            }
                
        }
        break;

       
        default:
            break;
        }
    }
    break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here..
            HBRUSH brush = CreateSolidBrush(RGB(128,128,128));
            HBRUSH lightgreybrush = CreateSolidBrush(RGB(211, 211, 211));
            HBRUSH green = CreateSolidBrush(RGB(0, 128, 0));
            //trafikklys loddrett
            Rectangle(hdc, 550, 200, 600, 300);
            //trafikklys vassrett
            Rectangle(hdc, 500, 400, 600, 450);
          
            HGDIOBJ hOrg = SelectObject(hdc, brush);
           
            //trafikklys loddrett
            Ellipse(hdc, 550, 200, 600, 233);
            Ellipse(hdc, 550, 233, 600, 266);
            Ellipse(hdc, 550, 266, 600, 300);

            //trafikklys vassrett 
            Ellipse(hdc, 500, 400, 533, 450);
            Ellipse(hdc, 533, 400, 566, 450);
            Ellipse(hdc, 566, 400, 600, 450);
           
           
            //veien
            SelectObject(hdc, lightgreybrush);
            //vei loddrett
            Rectangle(hdc, 600, 0, 700, 700);
            //vei vassrett
            Rectangle(hdc, 0, 300, 1300, 400);

            //print pw on screen
            TCHAR buffer[100];
            _stprintf_s(buffer, _T("The probability of cars arriving from west: %d %%"), pw);
            TextOut(hdc, 0, 0, buffer, _tcslen(buffer));
            //print pn on screen 
            TCHAR buffer2[100];
            _stprintf_s(buffer2, _T("The probability of cars arriving from north: %d %%"), pn);
            TextOut(hdc, 0, 20, buffer2, _tcslen(buffer2));

            HBRUSH red = CreateSolidBrush(RGB(255, 0, 0));
           // HBRUSH random = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
            
           //Make Cars
          
            for (auto i = 0; i < carvector.size(); i++) {
            SelectObject(hdc, red);
                Rectangle(hdc, carvector[i].x -50 , 340, carvector[i].y , 370);
               
            }
            for (auto i = 0; i < carvector2.size(); i++) {
                SelectObject(hdc, green );
                Rectangle(hdc, 640, carvector2[i].x -50 , 670, carvector2[i].y);
               
            }
              
            
 
            switch (state)
            {
            case 1: 
            {
           
                HBRUSH redbrush = CreateSolidBrush(RGB(255, 0, 0));
                SelectObject(hdc, redbrush);
                Ellipse(hdc, 550, 200, 600, 233);
                SelectObject(hdc, brush);
                Ellipse(hdc, 550, 233, 600, 266);
                Ellipse(hdc, 550, 266, 600, 300);
                DeleteObject(redbrush);
            }
            break;
            case 2 :
            {
               
                HBRUSH redbrush = CreateSolidBrush(RGB(255, 0, 0));
                HBRUSH yellowbrush = CreateSolidBrush(RGB(255, 255, 0));
                SelectObject(hdc, redbrush);
                Ellipse(hdc, 550, 200, 600, 233);
                SelectObject(hdc, yellowbrush);
                Ellipse(hdc, 550, 233, 600, 266);
                SelectObject(hdc, brush);
                Ellipse(hdc, 550, 266, 600, 300);
                DeleteObject(redbrush);
                DeleteObject(yellowbrush);
            }
            break;
            case 3: {
          
                HBRUSH greenbrush = CreateSolidBrush(RGB(0, 255, 0));

                SelectObject(hdc, brush);
                Ellipse(hdc, 550, 200, 600, 233);
                Ellipse(hdc, 550, 233, 600, 266);
                SelectObject(hdc, greenbrush);
                Ellipse(hdc, 550, 266, 600, 300);


                DeleteObject(greenbrush);
            }
             break;
            case 4: 
            {
                HBRUSH yellowbrush = CreateSolidBrush(RGB(255, 255, 0));
                SelectObject(hdc, brush);
                Ellipse(hdc, 550, 200, 600, 233);
                SelectObject(hdc, yellowbrush);
                Ellipse(hdc, 550, 233, 600, 266);
                SelectObject(hdc, brush);
                Ellipse(hdc, 550, 266, 600, 300);
                DeleteObject(yellowbrush);
            }
            break;

            default:
                break;
            }
            switch (statelys2)
            {
            case 3: 
            {
              
                HBRUSH redbrush = CreateSolidBrush(RGB(255, 0, 0));
                SelectObject(hdc, redbrush);
                Ellipse(hdc, 566, 400, 600, 450);
                SelectObject(hdc, brush);
                Ellipse(hdc, 533, 400, 566, 450);
                Ellipse(hdc, 500, 400, 533, 450);
                DeleteObject(redbrush);
            }
            break;
            case 4:
            {
              
                HBRUSH redbrush = CreateSolidBrush(RGB(255, 0, 0));
                HBRUSH yellowbrush = CreateSolidBrush(RGB(255, 255, 0));
                SelectObject(hdc, redbrush);
                Ellipse(hdc, 566, 400, 600, 450);
                SelectObject(hdc, yellowbrush);
                Ellipse(hdc, 533, 400, 566, 450);
                SelectObject(hdc, brush);
                Ellipse(hdc, 500, 400, 533, 450);
                DeleteObject(redbrush);
                DeleteObject(yellowbrush);

            }
            break;
            case 1: 
            {
            
                HBRUSH greenbrush = CreateSolidBrush(RGB(0, 255, 0));

                SelectObject(hdc, brush);
                Ellipse(hdc, 566, 400, 600, 450);
                Ellipse(hdc, 533, 400, 566, 450);
                SelectObject(hdc, greenbrush);
                Ellipse(hdc, 500, 400, 533, 450);

                DeleteObject(greenbrush);
            }
            break;
            case 2: 
            {
                HBRUSH yellowbrush = CreateSolidBrush(RGB(255, 255, 0));
                SelectObject(hdc, brush);
                Ellipse(hdc, 566, 400, 600, 450);
                SelectObject(hdc, yellowbrush);
                Ellipse(hdc, 533, 400, 566, 450);
                SelectObject(hdc, brush);
                Ellipse(hdc, 500, 400, 533, 450);
                DeleteObject(yellowbrush);
            }
            break;
            default:
                break;
            }
           
            SelectObject(hdc, hOrg);
            DeleteObject(brush);
            DeleteObject(lightgreybrush);
            DeleteObject(red);
          //  DeleteObject(random);
            DeleteObject(green);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK myDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:

        if (LOWORD(wParam) == IDOK)
        {
          
            pw = GetDlgItemInt(hDlg, IDC_PW, NULL, true);
            pn = GetDlgItemInt(hDlg, IDC_PN, NULL, true);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        break;
        }
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;

        }
        break;
    }
    return (INT_PTR)FALSE;
}
// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
