#include "DxLib.h"

#define WinX 1280
#define WinY  720	// この二つはウィンドウサイズ
#define GRAY   GetColor(105, 105, 105) // 色リスト
#define BLACK  GetColor(  0,   0,   0)
#define WHITE  GetColor(255, 255, 255)
#define RED    GetColor(255,   0,   0)
#define GREEN  GetColor(  0, 255,   0)
#define YELLOW GetColor(255, 255,   0)
#define PNT 32
#define HEIGHT 48
#define WIDTH  HEIGHT * 10
#define SIZE   HEIGHT / 2

// グロ変
int HP_me = 16, HP_you = 4;

// 基本画面構築
void CreateMain(void){
	
	SetFontSize(SIZE);
	
	// メッセージボックス
	DrawBox(0, WinY - HEIGHT * 2, WinX + 1, WinY + 1, WHITE, TRUE);
	DrawBox(0, WinY - HEIGHT * 2, WinX + 1, WinY + 1, BLACK, FALSE);
	DrawFormatString(SIZE / 2, WinY - HEIGHT * 2 + SIZE / 2, BLACK,
	                 "メッセージボックス\n\nサンプルテキスト");
	
	// ステータス描画
		// 相手側下地
		DrawBox(-1, PNT, PNT * 3 + WIDTH + 1, PNT * 4 + 1, WHITE, TRUE);
		DrawBox(-1, PNT, PNT * 3 + WIDTH + 1, PNT * 4 + 1, BLACK, FALSE);
		// 相手のHP枠下地
		DrawBox(PNT, PNT * 3 / 2, PNT + WIDTH + 1, PNT * 3 / 2 + SIZE + 1, BLACK, TRUE);
		// 相手の残りHPのテキスト
		DrawFormatString(PNT + WIDTH, PNT * 3 / 2, BLACK, "%2d", HP_you);
		// 相手のHPバー
		// 現在値によって色変化
		DrawBox(PNT, PNT * 3 / 2, PNT + SIZE * HP_you + 1, PNT * 3 / 2 + SIZE + 1,
		        HP_you > 10 ? GREEN : (HP_you > 4 ? YELLOW : RED), TRUE);
		// 相手の名前
		DrawFormatString(PNT, PNT * 3 / 2 + SIZE, BLACK, "＜ここに敵の名前＞");
		// ターンの行動
		DrawBox(PNT * 3 + WIDTH - SIZE * 5, PNT * 4 - SIZE * 2,
		        PNT * 3 + WIDTH + 1, PNT * 4 + 1, BLACK, FALSE);
		DrawFormatString(PNT * 3 + WIDTH - SIZE * 9 / 2, PNT * 4 - SIZE * 3 / 2, BLACK,
		                 "こうどう");
		
		// 自分側下地
		DrawBox(WinX - (PNT * 3 + WIDTH), WinY - (PNT * 4 + HEIGHT * 2),
		        WinX + 2, WinY - (PNT + HEIGHT * 2) + 1, WHITE, TRUE);
		DrawBox(WinX - (PNT * 3 + WIDTH), WinY - (PNT * 4 + HEIGHT * 2),
		        WinX + 2, WinY - (PNT + HEIGHT * 2) + 1, BLACK, FALSE);
		// 自分のHP枠下地
		DrawBox(WinX - (PNT + WIDTH), WinY - (PNT * 7 / 2 + HEIGHT * 2),
		        WinX - PNT + 1, WinY - (PNT * 7 / 2 + HEIGHT * 2) + SIZE + 1, BLACK, TRUE);
		// 自分の残りHPのテキスト
		DrawFormatString(WinX - (PNT + WIDTH + SIZE + 4),
		                 WinY - (PNT * 7 / 2 + HEIGHT * 2), BLACK, "%2d", HP_me);
		// 自分のHPバー
		// 現在値によって色変化
		DrawBox(WinX - (PNT + WIDTH), WinY - (PNT * 7 / 2 + HEIGHT * 2),
		        WinX - (PNT + WIDTH) + SIZE * HP_me + 1, WinY - (PNT * 7 / 2 + HEIGHT * 2) + SIZE + 1,
		        HP_me > 10 ? GREEN : (HP_me > 4 ? YELLOW : RED), TRUE);
		// ターンの行動
		DrawBox(WinX - (PNT * 3 + WIDTH), WinY - (PNT * 4 + HEIGHT),
		        WinX - (PNT * 3 + WIDTH) + SIZE * 5 + 1, WinY - (PNT + HEIGHT * 2) + 1, BLACK, FALSE);
		DrawFormatString(WinX - (PNT * 3 + WIDTH) + SIZE / 2, WinY - (PNT * 4 + HEIGHT) + SIZE / 2, BLACK,
		                 "こうどう");
}

// 構築画面の設計
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){
	// もろもろ起動前の初期設定
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(1920, 1080, 32);
	SetWindowSize(WinX, WinY);
	
	if( DxLib_Init() == -1 ){
		return -1;
	}
	
	// ウィンドウ生成：画面サイズは仮
	DrawBox(0, 0, WinX + 1, WinY + 1, GRAY, TRUE);
	
	// 基本画面構築
	CreateMain();
	
	int Mx, My;
	do{
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			GetMousePoint(&Mx, &My);
			// ※※※デバッグ用、左上クリックすると消えます
			if(Mx < PNT && My < PNT)	break;
		}
	}while(1);
	
	DxLib_End();
	
	return 0;
}
