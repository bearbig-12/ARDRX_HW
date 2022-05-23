#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

GameEngineRenderer::GameEngineRenderer()
{
}

GameEngineRenderer::~GameEngineRenderer()
{
}


void GameEngineRenderer::Start()
{
	GetActor()->GetLevel()->PushRenderer(this);
}

float4 XDir = { 1, 0 };
float4 YDir = { 0, -1 };

float Angle = 0.0f;
float Dis = 0.0f;
float4 Postion;

void GameEngineRenderer::Render(float _DeltaTime)
{
	// 방향을 정했고
	// 정규화는 크기가 아닌 방향을 뽑아내기 위함

	float4 Dir = float4::DegreeToDirection2D(Angle);
	Angle += _DeltaTime;


	//GetActor()->GetTransform().SetPosition(float4{ 300.0f, 300.0f } + Dir * 300.0f);

	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("HexaGram");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("HexaGram");

	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());



	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		int TriIndex = Index->Indexs[i];

		// 0 번째 순서의 점이 됩니다.
		CopyBuffer[i] = Vertex->Vertexs[TriIndex];

		// [0.5f] [0.5f] []                  [100] [100] [] 
		// 크
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();

		// 돌리고 돌리고 돌다 보면은~
		CopyBuffer[i] = float4::VectorRotationToRadianZ(CopyBuffer[i], Angle);

		// 자전
		//CopyBuffer[i] *= GetActor()->GetTransform().GetRotation();


		 //이동
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();


		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}



	

	for (size_t i = 0; i < DrawVertex.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}


	// Rectangle(GameEngineWindow::GetHDC(), LeftTop.ix(), LeftTop.iy(), RightBot.ix(), RightBot.iy());
}