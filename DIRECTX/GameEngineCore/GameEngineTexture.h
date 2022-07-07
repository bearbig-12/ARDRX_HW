#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineRes.h"

// ���� : 
class GameEngineTexture : public GameEngineRes<GameEngineTexture>
{
public:
	// constrcuter destructer
	GameEngineTexture();
	~GameEngineTexture();

	// delete Function
	GameEngineTexture(const GameEngineTexture& _Other) = delete;
	GameEngineTexture(GameEngineTexture&& _Other) noexcept = delete;
	GameEngineTexture& operator=(const GameEngineTexture& _Other) = delete;
	GameEngineTexture& operator=(GameEngineTexture&& _Other) noexcept = delete;

	// static
	static GameEngineTexture* Create(const std::string& _Name, ID3D11Texture2D* _Texture);
	static GameEngineTexture* Create(ID3D11Texture2D* _Texture);

	// Member
	ID3D11RenderTargetView* CreateRenderTargetView();


protected:

private:
	ID3D11Texture2D* Texture2D;
	ID3D11RenderTargetView* RenderTargetView;

	// �̳༮�� �ؽ�ó�� ���ؼ� 
	// ID3D11RenderTargetView* Render;


};
