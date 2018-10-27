#include "DxLib.h"

#include <string>
#include <utility>

#define WinX 1280
#define WinY  720	// この二つはウィンドウサイズ
#define GRAY  GetColor(105, 105, 105) // 色リスト
#define BLACK GetColor(  0,   0,   0)
#define WHITE GetColor(255, 255, 255)
#define PNT 32
#define HEIGHT 48
#define WIDTH  HEIGHT * 18 / 2
#define SIZE   HEIGHT / 2

void CreateConButton(int cnt){	// 条件サイドの画面構築関数
	int pnt = PNT;	// 生成位置初期値
	int Size = HEIGHT / 2;	// 文字サイズ
	
	// char teststr[cnt - 1][64] = "＜ここに条件が入る＞";
	
	SetFontSize(Size);
	
	// 最初に画面を初期化
	DrawBox(PNT, PNT, PNT + WIDTH + HEIGHT * 5 + 1, PNT + HEIGHT * 13 + 1, GRAY, TRUE);
	
	for(int i = 0, x = pnt; i < cnt; i++, pnt += HEIGHT){
		// 条件枠生成(黒背景+白罫線)
		DrawBox(x, pnt, x + WIDTH + 1, pnt + HEIGHT + 1, BLACK, TRUE);
		DrawBox(x, pnt, x + WIDTH + 1, pnt + HEIGHT + 1, WHITE, FALSE);
		// 条件枠文字列描画
		DrawFormatString(x + Size / 2, pnt + Size / 2, WHITE, i < cnt - 1 ? "＜ここに条件が入る＞" : (cnt == 1 ? "いつも" : "（上のどれでもないとき）"));
		
		// 矢印描画
		DrawFormatString(x + WIDTH + Size, pnt + Size / 2, WHITE, "→");
		
		// 行動枠生成
		DrawBox(x + WIDTH + HEIGHT + Size, pnt, x + WIDTH + HEIGHT * 4 + 1, pnt + HEIGHT + 1, BLACK, TRUE);
		DrawBox(x + WIDTH + HEIGHT + Size, pnt, x + WIDTH + HEIGHT * 4 + 1, pnt + HEIGHT + 1, WHITE, FALSE);
		// 行動枠文字列描画
		DrawFormatString(x + WIDTH + (HEIGHT * 3 + Size) / 2, pnt + Size / 2, WHITE, "こうどう");
		
		// elseは削除できないように、あと下限1なのでcnt=1なら描画しない
		if(cnt > 1 && i < cnt - 1){
			// 削除ボタン枠描画
			DrawBox(x + WIDTH + HEIGHT * 4 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 4 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, BLACK, TRUE);
			DrawBox(x + WIDTH + HEIGHT * 4 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 4 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, WHITE, FALSE);
			// 削除ボタン文字列描画
			DrawFormatString(x + WIDTH + HEIGHT * 4 + HEIGHT / 4, pnt + HEIGHT / 4, WHITE, "－");
		}
		
		// 並べ替えボタン描画(cnt>2のとき)
		if(cnt > 2 && i < cnt - 1){
			DrawBox(x + WIDTH + HEIGHT * 5 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 5 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, BLACK, TRUE);
			DrawBox(x + WIDTH + HEIGHT * 5 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 5 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, WHITE, FALSE);
			DrawFormatString(x + WIDTH + HEIGHT * 5 + HEIGHT / 8, pnt + HEIGHT / 4, WHITE, "↑");
			DrawFormatString(x + WIDTH + HEIGHT * 5 + HEIGHT / 8 * 3, pnt + HEIGHT / 4, WHITE, "↓");
		}
	}
	pnt = PNT;
	// 条件数が12未満だったら追加ボタンを描画
	if(cnt < 12){
		DrawBox(pnt + HEIGHT / 8, pnt + HEIGHT * cnt + HEIGHT / 8, pnt + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * cnt + HEIGHT * 7 / 8 + 1, BLACK, TRUE);
		DrawBox(pnt + HEIGHT / 8, pnt + HEIGHT * cnt + HEIGHT / 8, pnt + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * cnt + HEIGHT * 7 / 8 + 1, WHITE, FALSE);
		DrawFormatString(pnt + HEIGHT / 4, pnt + HEIGHT * cnt + HEIGHT / 4, WHITE, "＋");
	}
}

void CreateConList(int cnt){	// 条件リストの画面構築関数
	// 初期生成位置
	int pntx = WinX - (PNT + WIDTH);
	int pnty = PNT;
	
	char teststr[] = "＜ここに条件が入る＞";
	
	SetFontSize(SIZE);
	
	// 右面を画面初期化
	DrawBox(pntx, pnty, pntx + WIDTH + 1, PNT + HEIGHT * 12 + 1, GRAY, TRUE);
	
	// 条件種類数だけリストを生成
	for(int i = 0; i < cnt; i++, pnty += HEIGHT){
		DrawBox(pntx, pnty, pntx + WIDTH + 1, pnty + HEIGHT + 1, BLACK, TRUE);
		DrawBox(pntx, pnty, pntx + WIDTH + 1, pnty + HEIGHT + 1, WHITE, FALSE);
		DrawFormatString(pntx + SIZE / 2, pnty + SIZE / 2, WHITE, teststr);
	}
	
	// 直下に数値の入力フィールドを生成
	DrawFormatString(pntx, pnty + SIZE, WHITE, "○の数字は下に入力してね");
	DrawBox(pntx, pnty + HEIGHT, pntx + HEIGHT * 4 + 1, pnty + SIZE * 3 + 1, BLACK, TRUE);
	DrawBox(pntx, pnty + HEIGHT, pntx + HEIGHT * 4 + 1, pnty + SIZE * 3 + 1, WHITE, FALSE);
}

void CreateActList(void){	// 行動リストの画面構築関数
	// 初期生成位置
	int pntx = WinX - (PNT + WIDTH);
	int pnty = PNT;
	
	char teststr[3][64] = {"こうげき", "ぼうぎょ", "はんげき"};
	
	SetFontSize(SIZE);
	
	// 右面を画面初期化
	DrawBox(pntx, pnty, pntx + WIDTH + 1, PNT + HEIGHT * 12 + 1, GRAY, TRUE);
	
	// 3つだけリストを生成
	for(int i = 0; i < 3; i++, pntx += WIDTH / 3){
		DrawBox(pntx, pnty, pntx + WIDTH / 3 + 1, pnty + HEIGHT + 1, BLACK, TRUE);
		DrawBox(pntx, pnty, pntx + WIDTH / 3 + 1, pnty + HEIGHT + 1, WHITE, FALSE);
		DrawFormatString(pntx + SIZE, pnty + SIZE / 2, WHITE, teststr[i]);
	}
	
	// 説明文を書く
	pntx = WinX - (PNT + WIDTH);
	DrawBox(pntx, pnty + HEIGHT + SIZE, pntx + WIDTH + 1, pnty + HEIGHT + SIZE * 22 + 1, BLACK, TRUE);
	DrawBox(pntx, pnty + HEIGHT + SIZE, pntx + WIDTH + 1, pnty + HEIGHT + SIZE * 22 + 1, WHITE, FALSE);
	SetFontSize(SIZE / 2);
	DrawFormatString(pntx + SIZE / 4, pnty + HEIGHT + SIZE + SIZE / 4, WHITE, "%s%s%s",
		"こうげき…\n　てきに２ダメージをあたえるよ。\n　でも「ぼうぎょ」されると１ダメージしかあたえられなくて、\n　「はんげき」されるとかわりにじぶんがダメージをうけるよ。\n\n",
		"ぼうぎょ…\n　てきからのダメージをへらすよ。\n\n",
		"はんげき…\n　てきが「こうげき」してきたとき、あいてにはんげきするよ。\n　このときじぶんはダメージをうけないよ。\n　でもあいてが「こうげき」してこなかったとき、\n　つぎのターンうごけなくなってうけるダメージがふえちゃうよ。");
}

void CreateElse(void){	// その他生成
	int pntx = WinX - PNT;
	int pnty = WinY - PNT;
	
	// 戦闘モード移行ボタン生成
	DrawBox(pntx - SIZE * 5, pnty - HEIGHT, pntx + 1, pnty + 1, BLACK, TRUE);
	DrawBox(pntx - SIZE * 5, pnty - HEIGHT, pntx + 1, pnty + 1, WHITE, FALSE);
	DrawFormatString(pntx - SIZE * 9 / 2, pnty - SIZE * 3 / 2, WHITE, "たたかう");
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
	
	int Con_Cnt = 2;	// 条件数（1～12）
	int Choice = -1, Type = -1;
	int Mx, My;
	CreateConButton(Con_Cnt);
	CreateElse();
	do{
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			GetMousePoint(&Mx, &My);
			// ※※※デバッグ用、左上クリックすると消えます
			if(Mx < PNT && My < PNT)	break;
			
			// 条件枠選択処理
			int x = Mx - PNT;
			int y = My - PNT;
			if(0 <= y / HEIGHT && y / HEIGHT + 1 < Con_Cnt && 0 <= x && x <= WIDTH){
				// 何か選んでたらそれを消去
				if(Choice != -1){
					switch(Type){
						case 0 : DrawBox(PNT + 4, PNT + HEIGHT * Choice + 4, PNT + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
						case 1 : DrawBox(PNT + WIDTH + HEIGHT + HEIGHT / 2 + 4, PNT + HEIGHT * Choice + 4, PNT + HEIGHT * 4 + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
					}
				}
				// 選択枠をオレンジで囲う、選択枠を保存
				DrawBox(PNT + 4, PNT + HEIGHT * (y / HEIGHT) + 4, PNT + WIDTH - 3, PNT + HEIGHT * (y / HEIGHT + 1) - 3, GetColor(255, 165, 0), FALSE);
				Choice = y / HEIGHT;
				Type = 0;
				
				// んでもって右側生成
				CreateConList(8);
			}
			
			// 行動枠選択処理
			x = Mx - (PNT + HEIGHT * 3 / 2 + WIDTH);
			if(0 <= y / HEIGHT && y / HEIGHT + 1 <= Con_Cnt && 0 <= x && x <= HEIGHT * 5 / 2){
				// 何か選んでたらそれを消去
				if(Choice != -1){
					switch(Type){
						case 0 : DrawBox(PNT + 4, PNT + HEIGHT * Choice + 4, PNT + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
						case 1 : DrawBox(PNT + WIDTH + HEIGHT * 3 / 2 + 4, PNT + HEIGHT * Choice + 4, PNT + HEIGHT * 4 + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
					}
				}
				// 選択枠をオレンジで囲う、選択枠を保存
				DrawBox(PNT + WIDTH + HEIGHT * 3 / 2 + 4, PNT + HEIGHT * (y / HEIGHT) + 4, PNT + HEIGHT * 4 + WIDTH - 3, PNT + HEIGHT * (y / HEIGHT + 1) - 3, GetColor(255, 165, 0), FALSE);
				Choice = y / HEIGHT;
				Type = 1;
				
				// んでもって右側生成
				CreateActList();
			}
			
			// 削除枠選択処理
			// ボタンがないところに反応しないようにする
			x = Mx - (PNT + WIDTH + HEIGHT * 4);
			int n = My - (PNT + HEIGHT * (y / HEIGHT));
			if(0 <= y / HEIGHT && y / HEIGHT <= Con_Cnt &&
			   HEIGHT / 8 <= x && x <= HEIGHT * 7 / 8 &&
			   HEIGHT / 8 <= n && n <= HEIGHT * 7 / 8 &&
			   Con_Cnt > 1){
				CreateConButton(--Con_Cnt);
				Choice = -1;
				WaitTimer(500);
			}
			
			// 追加枠選択処理
			x = Mx - PNT;
			n = My - (PNT + HEIGHT * Con_Cnt);
			if(Con_Cnt < 12 && y / HEIGHT + 1 > Con_Cnt && HEIGHT / 8 <= x && x <= HEIGHT * 7 / 8 && HEIGHT / 8 <= n && n <= HEIGHT * 7 / 8){
				CreateConButton(++Con_Cnt);
				Choice = -1;
				WaitTimer(500);
			}
		}
	}while(1);
	
	
	DxLib_End();
	
	return 0;
}
