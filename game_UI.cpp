#include "DxLib.h"

#include <string>
#include <utility>

#define WinX 1280
#define WinY  720	// ���̓�̓E�B���h�E�T�C�Y
#define GRAY  GetColor(105, 105, 105) // �F���X�g
#define BLACK GetColor(  0,   0,   0)
#define WHITE GetColor(255, 255, 255)
#define PNT 32
#define HEIGHT 48
#define WIDTH  HEIGHT * 18 / 2
#define SIZE   HEIGHT / 2

void CreateConButton(int cnt){	// �����T�C�h�̉�ʍ\�z�֐�
	int pnt = PNT;	// �����ʒu�����l
	int Size = HEIGHT / 2;	// �����T�C�Y
	
	// char teststr[cnt - 1][64] = "�������ɏ��������遄";
	
	SetFontSize(Size);
	
	// �ŏ��ɉ�ʂ�������
	DrawBox(PNT, PNT, PNT + WIDTH + HEIGHT * 5 + 1, PNT + HEIGHT * 13 + 1, GRAY, TRUE);
	
	for(int i = 0, x = pnt; i < cnt; i++, pnt += HEIGHT){
		// �����g����(���w�i+���r��)
		DrawBox(x, pnt, x + WIDTH + 1, pnt + HEIGHT + 1, BLACK, TRUE);
		DrawBox(x, pnt, x + WIDTH + 1, pnt + HEIGHT + 1, WHITE, FALSE);
		// �����g������`��
		DrawFormatString(x + Size / 2, pnt + Size / 2, WHITE, i < cnt - 1 ? "�������ɏ��������遄" : (cnt == 1 ? "����" : "�i��̂ǂ�ł��Ȃ��Ƃ��j"));
		
		// ���`��
		DrawFormatString(x + WIDTH + Size, pnt + Size / 2, WHITE, "��");
		
		// �s���g����
		DrawBox(x + WIDTH + HEIGHT + Size, pnt, x + WIDTH + HEIGHT * 4 + 1, pnt + HEIGHT + 1, BLACK, TRUE);
		DrawBox(x + WIDTH + HEIGHT + Size, pnt, x + WIDTH + HEIGHT * 4 + 1, pnt + HEIGHT + 1, WHITE, FALSE);
		// �s���g������`��
		DrawFormatString(x + WIDTH + (HEIGHT * 3 + Size) / 2, pnt + Size / 2, WHITE, "�����ǂ�");
		
		// else�͍폜�ł��Ȃ��悤�ɁA���Ɖ���1�Ȃ̂�cnt=1�Ȃ�`�悵�Ȃ�
		if(cnt > 1 && i < cnt - 1){
			// �폜�{�^���g�`��
			DrawBox(x + WIDTH + HEIGHT * 4 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 4 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, BLACK, TRUE);
			DrawBox(x + WIDTH + HEIGHT * 4 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 4 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, WHITE, FALSE);
			// �폜�{�^��������`��
			DrawFormatString(x + WIDTH + HEIGHT * 4 + HEIGHT / 4, pnt + HEIGHT / 4, WHITE, "�|");
		}
		
		// ���בւ��{�^���`��(cnt>2�̂Ƃ�)
		if(cnt > 2 && i < cnt - 1){
			DrawBox(x + WIDTH + HEIGHT * 5 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 5 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, BLACK, TRUE);
			DrawBox(x + WIDTH + HEIGHT * 5 + HEIGHT / 8, pnt + HEIGHT / 8, x + WIDTH + HEIGHT * 5 + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * 7 / 8 + 1, WHITE, FALSE);
			DrawFormatString(x + WIDTH + HEIGHT * 5 + HEIGHT / 8, pnt + HEIGHT / 4, WHITE, "��");
			DrawFormatString(x + WIDTH + HEIGHT * 5 + HEIGHT / 8 * 3, pnt + HEIGHT / 4, WHITE, "��");
		}
	}
	pnt = PNT;
	// ��������12������������ǉ��{�^����`��
	if(cnt < 12){
		DrawBox(pnt + HEIGHT / 8, pnt + HEIGHT * cnt + HEIGHT / 8, pnt + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * cnt + HEIGHT * 7 / 8 + 1, BLACK, TRUE);
		DrawBox(pnt + HEIGHT / 8, pnt + HEIGHT * cnt + HEIGHT / 8, pnt + HEIGHT * 7 / 8 + 1, pnt + HEIGHT * cnt + HEIGHT * 7 / 8 + 1, WHITE, FALSE);
		DrawFormatString(pnt + HEIGHT / 4, pnt + HEIGHT * cnt + HEIGHT / 4, WHITE, "�{");
	}
}

void CreateConList(int cnt){	// �������X�g�̉�ʍ\�z�֐�
	// ���������ʒu
	int pntx = WinX - (PNT + WIDTH);
	int pnty = PNT;
	
	char teststr[] = "�������ɏ��������遄";
	
	SetFontSize(SIZE);
	
	// �E�ʂ���ʏ�����
	DrawBox(pntx, pnty, pntx + WIDTH + 1, PNT + HEIGHT * 12 + 1, GRAY, TRUE);
	
	// ������ސ��������X�g�𐶐�
	for(int i = 0; i < cnt; i++, pnty += HEIGHT){
		DrawBox(pntx, pnty, pntx + WIDTH + 1, pnty + HEIGHT + 1, BLACK, TRUE);
		DrawBox(pntx, pnty, pntx + WIDTH + 1, pnty + HEIGHT + 1, WHITE, FALSE);
		DrawFormatString(pntx + SIZE / 2, pnty + SIZE / 2, WHITE, teststr);
	}
	
	// �����ɐ��l�̓��̓t�B�[���h�𐶐�
	DrawFormatString(pntx, pnty + SIZE, WHITE, "���̐����͉��ɓ��͂��Ă�");
	DrawBox(pntx, pnty + HEIGHT, pntx + HEIGHT * 4 + 1, pnty + SIZE * 3 + 1, BLACK, TRUE);
	DrawBox(pntx, pnty + HEIGHT, pntx + HEIGHT * 4 + 1, pnty + SIZE * 3 + 1, WHITE, FALSE);
}

void CreateActList(void){	// �s�����X�g�̉�ʍ\�z�֐�
	// ���������ʒu
	int pntx = WinX - (PNT + WIDTH);
	int pnty = PNT;
	
	char teststr[3][64] = {"��������", "�ڂ�����", "�͂񂰂�"};
	
	SetFontSize(SIZE);
	
	// �E�ʂ���ʏ�����
	DrawBox(pntx, pnty, pntx + WIDTH + 1, PNT + HEIGHT * 12 + 1, GRAY, TRUE);
	
	// 3�������X�g�𐶐�
	for(int i = 0; i < 3; i++, pntx += WIDTH / 3){
		DrawBox(pntx, pnty, pntx + WIDTH / 3 + 1, pnty + HEIGHT + 1, BLACK, TRUE);
		DrawBox(pntx, pnty, pntx + WIDTH / 3 + 1, pnty + HEIGHT + 1, WHITE, FALSE);
		DrawFormatString(pntx + SIZE, pnty + SIZE / 2, WHITE, teststr[i]);
	}
	
	// ������������
	pntx = WinX - (PNT + WIDTH);
	DrawBox(pntx, pnty + HEIGHT + SIZE, pntx + WIDTH + 1, pnty + HEIGHT + SIZE * 22 + 1, BLACK, TRUE);
	DrawBox(pntx, pnty + HEIGHT + SIZE, pntx + WIDTH + 1, pnty + HEIGHT + SIZE * 22 + 1, WHITE, FALSE);
	SetFontSize(SIZE / 2);
	DrawFormatString(pntx + SIZE / 4, pnty + HEIGHT + SIZE + SIZE / 4, WHITE, "%s%s%s",
		"���������c\n�@�Ă��ɂQ�_���[�W�����������B\n�@�ł��u�ڂ�����v�����ƂP�_���[�W�������������Ȃ��āA\n�@�u�͂񂰂��v�����Ƃ����ɂ��Ԃ񂪃_���[�W���������B\n\n",
		"�ڂ�����c\n�@�Ă�����̃_���[�W���ւ炷��B\n\n",
		"�͂񂰂��c\n�@�Ă����u���������v���Ă����Ƃ��A�����Ăɂ͂񂰂������B\n�@���̂Ƃ����Ԃ�̓_���[�W�������Ȃ���B\n�@�ł������Ă��u���������v���Ă��Ȃ������Ƃ��A\n�@���̃^�[���������Ȃ��Ȃ��Ă�����_���[�W���ӂ����Ⴄ��B");
}

void CreateElse(void){	// ���̑�����
	int pntx = WinX - PNT;
	int pnty = WinY - PNT;
	
	// �퓬���[�h�ڍs�{�^������
	DrawBox(pntx - SIZE * 5, pnty - HEIGHT, pntx + 1, pnty + 1, BLACK, TRUE);
	DrawBox(pntx - SIZE * 5, pnty - HEIGHT, pntx + 1, pnty + 1, WHITE, FALSE);
	DrawFormatString(pntx - SIZE * 9 / 2, pnty - SIZE * 3 / 2, WHITE, "��������");
}

// �\�z��ʂ̐݌v
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){
	// �������N���O�̏����ݒ�
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(1920, 1080, 32);
	SetWindowSize(WinX, WinY);
	
	if( DxLib_Init() == -1 ){
		return -1;
	}
	
	// �E�B���h�E�����F��ʃT�C�Y�͉�
	DrawBox(0, 0, WinX + 1, WinY + 1, GRAY, TRUE);
	
	int Con_Cnt = 2;	// �������i1�`12�j
	int Choice = -1, Type = -1;
	int Mx, My;
	CreateConButton(Con_Cnt);
	CreateElse();
	do{
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			GetMousePoint(&Mx, &My);
			// �������f�o�b�O�p�A����N���b�N����Ə����܂�
			if(Mx < PNT && My < PNT)	break;
			
			// �����g�I������
			int x = Mx - PNT;
			int y = My - PNT;
			if(0 <= y / HEIGHT && y / HEIGHT + 1 < Con_Cnt && 0 <= x && x <= WIDTH){
				// �����I��ł��炻�������
				if(Choice != -1){
					switch(Type){
						case 0 : DrawBox(PNT + 4, PNT + HEIGHT * Choice + 4, PNT + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
						case 1 : DrawBox(PNT + WIDTH + HEIGHT + HEIGHT / 2 + 4, PNT + HEIGHT * Choice + 4, PNT + HEIGHT * 4 + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
					}
				}
				// �I��g���I�����W�ň͂��A�I��g��ۑ�
				DrawBox(PNT + 4, PNT + HEIGHT * (y / HEIGHT) + 4, PNT + WIDTH - 3, PNT + HEIGHT * (y / HEIGHT + 1) - 3, GetColor(255, 165, 0), FALSE);
				Choice = y / HEIGHT;
				Type = 0;
				
				// ��ł����ĉE������
				CreateConList(8);
			}
			
			// �s���g�I������
			x = Mx - (PNT + HEIGHT * 3 / 2 + WIDTH);
			if(0 <= y / HEIGHT && y / HEIGHT + 1 <= Con_Cnt && 0 <= x && x <= HEIGHT * 5 / 2){
				// �����I��ł��炻�������
				if(Choice != -1){
					switch(Type){
						case 0 : DrawBox(PNT + 4, PNT + HEIGHT * Choice + 4, PNT + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
						case 1 : DrawBox(PNT + WIDTH + HEIGHT * 3 / 2 + 4, PNT + HEIGHT * Choice + 4, PNT + HEIGHT * 4 + WIDTH - 3, PNT + HEIGHT * (Choice + 1) - 3, BLACK, FALSE);	break;
					}
				}
				// �I��g���I�����W�ň͂��A�I��g��ۑ�
				DrawBox(PNT + WIDTH + HEIGHT * 3 / 2 + 4, PNT + HEIGHT * (y / HEIGHT) + 4, PNT + HEIGHT * 4 + WIDTH - 3, PNT + HEIGHT * (y / HEIGHT + 1) - 3, GetColor(255, 165, 0), FALSE);
				Choice = y / HEIGHT;
				Type = 1;
				
				// ��ł����ĉE������
				CreateActList();
			}
			
			// �폜�g�I������
			// �{�^�����Ȃ��Ƃ���ɔ������Ȃ��悤�ɂ���
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
			
			// �ǉ��g�I������
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
