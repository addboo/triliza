#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <iostream>


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

HDC         hdc, screen;
PAINTSTRUCT ps;
char        turn = 'X'; 

//Πίνακας χαρακτήρων που αποθηκεύει τις 9 θέσεις του παιχνιδιού ( η θέση 0 δε χρησιμοποιείται)
char m[10] = {' ','1','2','3','4','5','6','7','8','9'};

	
//Επιστρέφει true αν υπάρχει νικητής, αλλιώς false (ελέγχονται οι 8 πιθανές τριάδες)

bool win(char z)
{
	if	((m[1]==z) && (m[2]==z) && (m[3]==z)  ||
		 (m[4]==z) && (m[5]==z) && (m[6]==z)  ||
		 (m[7]==z) && (m[8]==z) && (m[9]==z)  ||
		 (m[1]==z) && (m[4]==z) && (m[7]==z)  ||
		 (m[2]==z) && (m[5]==z) && (m[8]==z)  ||
		 (m[3]==z) && (m[6]==z) && (m[9]==z)  ||
		 (m[1]==z) && (m[5]==z) && (m[9]==z)  ||
		 (m[3]==z) && (m[5]==z) && (m[7]==z)) 
	
		return true;
	else 
		return false;
}



/*
Ellipse coordinations x1,y1,x2,y2

70, 50, 170, 150
226, 50, 326, 150
376, 50, 476, 150

70, 180, 170, 280
226, 180, 326, 280
376, 180, 476, 280
 
70, 310, 170, 410
226, 310, 326, 410
376, 310, 476, 410

*/

void drawO(HWND hwnd, int x1, int y1, int x2, int y2)
{
	screen = GetDC(hwnd);
    
    Ellipse(hdc, x1, y1, x2, y2);  
    
    
	//RECT r = {20, 20, 120, 120};
    //HBRUSH br = CreateSolidBrush(RGB(0, 255, 0));



	/*
	Ellipse(hdc, 70, 50, 170, 150);  
	Ellipse(hdc, 226, 50, 326, 150);  
	Ellipse(hdc, 376, 50, 476, 150);  

	Ellipse(hdc, 70, 180, 170, 280);  
	Ellipse(hdc, 226, 180, 326, 280);  
	Ellipse(hdc, 376, 180, 476, 280);  

	Ellipse(hdc, 70, 310, 170, 410);  
	Ellipse(hdc, 226, 310, 326, 410);  
	Ellipse(hdc, 376, 310, 476, 410);  
    */
    
    //FillRect(screen, &r, br);

    //InvalidateRect(NULL, &r, true);
}

void drawX(HWND hwnd, int a, int b, int c, int d)
{   
	screen = GetDC(hwnd);

	MoveToEx  (hdc, a, b, NULL) ;
	LineTo    (hdc, c, d) ;
	MoveToEx  (hdc, c, b, NULL) ;
	LineTo    (hdc, a, d) ;


	/*
	MoveToEx  (hdc, 65, 61, NULL) ;
	LineTo    (hdc, 185, 150) ;
	MoveToEx  (hdc, 185, 61, NULL) ;
	LineTo    (hdc, 65, 150) ;
            
	MoveToEx  (hdc, 215, 61, NULL) ;
	LineTo    (hdc, 335, 150) ;
	MoveToEx  (hdc, 335, 61, NULL) ;
	LineTo    (hdc, 215, 150) ;

	MoveToEx  (hdc, 365, 61, NULL) ;
	LineTo    (hdc, 485, 150) ;
	MoveToEx  (hdc, 485, 61, NULL) ;
	LineTo    (hdc, 365, 150) ;



	MoveToEx  (hdc, 65, 191, NULL) ;
	LineTo    (hdc, 185, 280) ;
	MoveToEx  (hdc, 185, 191, NULL) ;
	LineTo    (hdc, 65, 280) ;

	MoveToEx  (hdc, 215, 191, NULL) ;
	LineTo    (hdc, 335, 280) ;
	MoveToEx  (hdc, 335, 191, NULL) ;
	LineTo    (hdc, 215, 280) ;

	MoveToEx  (hdc, 365, 191, NULL) ;
	LineTo    (hdc, 485, 280) ;
	MoveToEx  (hdc, 485, 191, NULL) ;
	LineTo    (hdc, 365, 280) ;



	MoveToEx  (hdc, 65, 331, NULL) ;
	LineTo    (hdc, 185, 420) ;
	MoveToEx  (hdc, 185, 331, NULL) ;
	LineTo    (hdc, 65, 420) ;

	MoveToEx  (hdc, 215, 331, NULL) ;
	LineTo    (hdc, 335, 420) ;
	MoveToEx  (hdc, 335, 331, NULL) ;
	LineTo    (hdc, 215, 420) ;

	MoveToEx  (hdc, 365, 331, NULL) ;
	LineTo    (hdc, 485, 420) ;
	MoveToEx  (hdc, 485, 331, NULL) ;
	LineTo    (hdc, 365, 420) ;
    
	*/
    

	//MessageBox(0, "into drawX", "Variable", 0);
    //Ellipse(hdc, 50, 50, 120, 120);  
    
    //EndPaint (hwnd, &ps);	
}

char switchPlayer(char p)
{
	char ret;
	
	if(p == 'X')
		ret = 'O';
	else
		ret = 'X';
		
	return ret;
}


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT ("LineDemo") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;
     
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     
     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("Program requires Windows NT!"), 
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Triliza v0.3 (beta)"),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          550, 540,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
		
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     static int  cxClient, cyClient ;
     RECT rect;
     
     switch (message)
     {
      	case WM_LBUTTONDOWN:    
        {	
        	int xPos = GET_X_LPARAM(lParam); 
			int yPos = GET_Y_LPARAM(lParam);

          	//drawX(hwnd, hdc);

			// check the range of coordinations of the mouse click 
			// and then it draw the shape.
			if(xPos > 51 && xPos < 194 && yPos > 50 && yPos < 142) 
			{
  				if(turn == 'X')  // 1 is for X
					drawX(hwnd, 65, 61, 185, 150);
				else  // else will be O
					drawO(hwnd, 70, 50, 170, 150);
					
				m[1] = turn; // Save the player's move to the first
				             // position (up, left) of the tic tac toe table.
			}
			else if(xPos > 210 && xPos < 342 && yPos > 51 && yPos < 152)
			{
				if(turn == 'X')
 					drawX(hwnd, 215, 61, 335, 150);
				else
					drawO(hwnd, 226, 50, 326, 150);

				m[2] = turn; // Save the player's move to the second
				             // position (up, middle) of the tic tac toe table.
			}
			else if(xPos > 358 && xPos < 491 && yPos > 54 && yPos < 149)
			{
				if(turn == 'X')
 					drawX(hwnd, 365, 61, 485, 150);
				else
					drawO(hwnd, 376, 50, 476, 150);
					
				m[3] = turn;
			}

	
			else if(xPos > 70 && xPos < 170 && yPos > 180 && yPos < 280)
			{
				if(turn == 'X')
 					drawX(hwnd, 65, 191, 185, 280);
				else
					drawO(hwnd, 70, 180, 170, 280);
	
				m[4] = turn;
			}
			else if(xPos > 226 && xPos < 326 && yPos > 180 && yPos < 280)
			{
				if(turn == 'X')
 					drawX(hwnd, 215, 191, 335, 280);
				else
					drawO(hwnd, 226, 180, 326, 280);
					
				m[5] = turn;
			}
			else if(xPos > 376 && xPos < 476 && yPos > 180 && yPos < 280)
			{
				if(turn == 'X')
 					drawX(hwnd, 365, 191, 485, 280);
				else
					drawO(hwnd, 376, 180, 476, 280);
					
				m[6] = turn;
			}

    
			else if(xPos > 70 && xPos < 170 && yPos > 310 && yPos < 410)
			{
				if(turn == 'X')
 					drawX(hwnd, 65, 331, 185, 420);
				else
					drawO(hwnd, 70, 310, 170, 410);
					
				m[7] = turn;
			}
			else if(xPos > 226 && xPos < 326 && yPos > 310 && yPos < 410)
			{
				if(turn == 'X')
 					drawX(hwnd, 215, 331, 335, 420);
				else
					drawO(hwnd, 226, 310, 326, 410);
					
				m[8] = turn;
			}
			else if(xPos > 376 && xPos < 476 && yPos > 310 && yPos < 410)
			{
				if(turn == 'X')
 					drawX(hwnd, 365, 331, 485, 420);
				else	
					drawO(hwnd, 376, 310, 476, 410);
					
				m[9] = turn;
			}
			
			// Check if we have a winner.
			if(win(turn))
			{
				char bufwin[100];
				
				sprintf(bufwin, "The winner is: %c", turn);
				MessageBox(0, bufwin, "Winner!", 0);
					
				break;
			}
			
			turn = switchPlayer(turn);
			
			// For debugging purposes:
			// char buf[1024];
			// sprintf(buf, "Coordinates: %d, %d", xPos, yPos);
			// MessageBox(0, buf, "Variable", 0);
            
            
			/*			  
     		char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
            */
            //PostMessage(hwnd, WM_CLOSE, 0, 0); 
			     	
		}
		break;
		     	
     case WM_SIZE:
          cxClient = LOWORD (lParam) ;
          cyClient = HIWORD (lParam) ;
          return 0 ;
          
     case WM_PAINT:
          hdc = BeginPaint (hwnd, &ps) ;
             
          // Design the tic tac toe's lines table.           
		  MoveToEx  (hdc, 200, 50, NULL) ;
          LineTo    (hdc, 200, 450) ;

          MoveToEx  (hdc, 350, 50, NULL) ;
          LineTo    (hdc, 350, 450) ;
          
          MoveToEx  (hdc, 50, 160, NULL) ;
          LineTo    (hdc, 500, 160) ;

          MoveToEx  (hdc, 50,  300, NULL) ;
          LineTo    (hdc, 500, 300) ;
          
      	  
          EndPaint (hwnd, &ps) ;
          
		  return 0 ;
          
     case WM_DESTROY:
          PostQuitMessage (0) ;
          return 0 ;
     }
     
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}
