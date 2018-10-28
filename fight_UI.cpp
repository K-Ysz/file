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
	
	// �X�e�[�^�X�`��
		// ���葤���n
		DrawBox(-1, PNT, PNT * 3 + WIDTH + 1, PNT * 4 + 1, WHITE, TRUE);
		DrawBox(-1, PNT, PNT * 3 + WIDTH + 1, PNT * 4 + 1, BLACK, FALSE);
		// �����HP�g���n
		DrawBox(PNT, PNT * 3 / 2, PNT + WIDTH + 1, PNT * 3 / 2 + SIZE + 1, BLACK, TRUE);
		// ����̎c��HP�̃e�L�X�g
		DrawFormatString(PNT + WIDTH, PNT * 3 / 2, BLACK, "%2d", HP_you);
		// �����HP�o�[
		// ���ݒl�ɂ���ĐF�ω�
		DrawBox(PNT, PNT * 3 / 2, PNT + SIZE * HP_you + 1, PNT * 3 / 2 + SIZE + 1,
		        HP_you > 10 ? GREEN : (HP_you > 4 ? YELLOW : RED), TRUE);
		// ����̖��O
		DrawFormatString(PNT, PNT * 3 / 2 + SIZE, BLACK, "�������ɓG�̖��O��");
		// �^�[���̍s��
		DrawBox(PNT * 3 + WIDTH - SIZE * 5, PNT * 4 - SIZE * 2,
		        PNT * 3 + WIDTH + 1, PNT * 4 + 1, BLACK, FALSE);
		DrawFormatString(PNT * 3 + WIDTH - SIZE * 9 / 2, PNT * 4 - SIZE * 3 / 2, BLACK,
		                 "�����ǂ�");
		
		// ���������n
		DrawBox(WinX - (PNT * 3 + WIDTH), WinY - (PNT * 4 + HEIGHT * 2),
		        WinX + 2, WinY - (PNT + HEIGHT * 2) + 1, WHITE, TRUE);
		DrawBox(WinX - (PNT * 3 + WIDTH), WinY - (PNT * 4 + HEIGHT * 2),
		        WinX + 2, WinY - (PNT + HEIGHT * 2) + 1, BLACK, FALSE);
		// ������HP�g���n
		DrawBox(WinX - (PNT + WIDTH), WinY - (PNT * 7 / 2 + HEIGHT * 2),
		        WinX - PNT + 1, WinY - (PNT * 7 / 2 + HEIGHT * 2) + SIZE + 1, BLACK, TRUE);
		// �����̎c��HP�̃e�L�X�g
		DrawFormatString(WinX - (PNT + WIDTH + SIZE + 4),
		                 WinY - (PNT * 7 / 2 + HEIGHT * 2), BLACK, "%2d", HP_me);
		// ������HP�o�[
		// ���ݒl�ɂ���ĐF�ω�
		DrawBox(WinX - (PNT + WIDTH), WinY - (PNT * 7 / 2 + HEIGHT * 2),
		        WinX - (PNT + WIDTH) + SIZE * HP_me + 1, WinY - (PNT * 7 / 2 + HEIGHT * 2) + SIZE + 1,
		        HP_me > 10 ? GREEN : (HP_me > 4 ? YELLOW : RED), TRUE);
		// �^�[���̍s��
		DrawBox(WinX - (PNT * 3 + WIDTH), WinY - (PNT * 4 + HEIGHT),
		        WinX - (PNT * 3 + WIDTH) + SIZE * 5 + 1, WinY - (PNT + HEIGHT * 2) + 1, BLACK, FALSE);
		DrawFormatString(WinX - (PNT * 3 + WIDTH) + SIZE / 2, WinY - (PNT * 4 + HEIGHT) + SIZE / 2, BLACK,
		                 "�����ǂ�");
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
