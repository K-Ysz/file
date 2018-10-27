#include "DxLib.h"

#define WinX 1280
#define WinY  720	// ���̓�̓E�B���h�E�T�C�Y
#define GRAY   GetColor(105, 105, 105) // �F���X�g
#define BLACK  GetColor(  0,   0,   0)
#define WHITE  GetColor(255, 255, 255)
#define RED    GetColor(255,   0,   0)
#define GREEN  GetColor(  0, 255,   0)
#define YELLOW GetColor(255, 255,   0)
#define PNT 32
#define HEIGHT 48
#define WIDTH  HEIGHT * 10
#define SIZE   HEIGHT / 2

// �O����
int HP_me = 16, HP_you = 4;

// ��{��ʍ\�z
void CreateMain(void){
	
	SetFontSize(SIZE);
	
	// ���b�Z�[�W�{�b�N�X
	DrawBox(0, WinY - HEIGHT * 2, WinX + 1, WinY + 1, WHITE, TRUE);
	DrawBox(0, WinY - HEIGHT * 2, WinX + 1, WinY + 1, BLACK, FALSE);
	DrawFormatString(SIZE / 2, WinY - HEIGHT * 2 + SIZE / 2, BLACK,
	                 "���b�Z�[�W�{�b�N�X\n\n�T���v���e�L�X�g");
	
	// HP�o�[�`��
		// �����HP�g���n
		DrawBox(PNT, PNT, PNT + WIDTH + 1, PNT + SIZE + 1, BLACK, TRUE);
		// ����̎c��HP�̃e�L�X�g���n
		DrawBox(PNT + WIDTH, PNT,
		        PNT + WIDTH + SIZE + 5, PNT + SIZE + 1, WHITE, TRUE);
		// ����̎c��HP�̃e�L�X�g
		DrawFormatString(PNT + WIDTH, PNT, BLACK, "%2d", HP_you);
		// �����HP�o�[
		// ���ݒl�ɂ���ĐF�ω�
		DrawBox(PNT, PNT, PNT + SIZE * HP_you + 1, PNT + SIZE + 1,
		        HP_you > 10 ? GREEN : (HP_you > 4 ? YELLOW : RED), TRUE);
		// ������HP�g���n
		DrawBox(WinX - (PNT + WIDTH), WinY - (PNT + HEIGHT * 2 + SIZE),
		        WinX - PNT + 1, WinY - (PNT + HEIGHT * 2) + 1, BLACK, TRUE);
		// �����̎c��HP�̃e�L�X�g���n
		DrawBox(WinX - (PNT + WIDTH + SIZE + 4), WinY - (PNT + HEIGHT * 2 + SIZE),
		        WinX - (PNT + WIDTH) + 1, WinY - (PNT + HEIGHT * 2) + 1, WHITE, TRUE);
		// �����̎c��HP�̃e�L�X�g
		DrawFormatString(WinX - (PNT + WIDTH + SIZE + 4),
		                 WinY - (PNT + HEIGHT * 2 + SIZE), BLACK, "%2d", HP_me);
		// ������HP�o�[
		// ���ݒl�ɂ���ĐF�ω�
		DrawBox(WinX - (PNT + WIDTH), WinY - (PNT + HEIGHT * 2 + SIZE),
		        WinX - (PNT + WIDTH) + SIZE * HP_me + 1, WinY - (PNT + HEIGHT * 2) + 1,
		        HP_me > 10 ? GREEN : (HP_me > 4 ? YELLOW : RED), TRUE);
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
	
	// ��{��ʍ\�z
	CreateMain();
	
	int Mx, My;
	do{
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			GetMousePoint(&Mx, &My);
			// �������f�o�b�O�p�A����N���b�N����Ə����܂�
			if(Mx < PNT && My < PNT)	break;
		}
	}while(1);
	
	DxLib_End();
	
	return 0;
}
