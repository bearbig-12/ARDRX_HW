#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include "GameEngineLevel.h"

// Resources Header
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

void GameEngineCore::EngineResourcesInitialize()
{
	// �簢�� �ڽ� ������ �ؽ�ó ���
	// �������ؿ��� �⺻������ ������� �Ѵٰ� �����ϴ�
	// ���ҽ����� �̴ϼȶ������ϴ� �ܰ�


	{
		// 0       1

		//    ����
		
		// 3       2

		std::vector<float4> Vertex;
		Vertex.push_back(float4(-0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, -0.5f));

		GameEngineVertexBuffer::Create("Rect", Vertex);
	}

	{
		// 0       1

		//    ����

		// 3       2

		std::vector<int> Index;

		// ù��° �ﰢ��
		// ����Ʈ �����ڷ� ���ڸ� �ڿ� �߰����ִ� ��� �߰� �Լ�.
		Index.resize(6);

		// ù��°
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// �ι�°
		Index[3] = 0;
		Index[4] = 2;
		Index[5] = 3;

		GameEngineIndexBuffer::Create("Rect", Index);
	}

	// HomeWork HexaGram
	{
		// Vertex Buffer

		//		0
		//	5		1
		//		C
		//	4		2
		//		3
		

		std::vector<float4> Vertex;
		Vertex.push_back(float4(0.0f, 0.75f));
		Vertex.push_back(float4(0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, -0.5f));

		Vertex.push_back(float4(0.0f, -0.75f));
		Vertex.push_back(float4(-0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, 0.5f));
		
		

		GameEngineVertexBuffer::Create("HexaGram", Vertex);



	}
	{
		// IndexBuffer
		// Need to draw two triangles 0 2 4 ,  1 3 5

		//		0
		//	5		1
		//		C
		//	4		2
		//		3
		
		std::vector<int> Index;

		Index.resize(6);

		// ù��°
		Index[0] = 0;
		Index[1] = 2;
		Index[2] = 4;

		// �ι�°
		Index[3] = 1;
		Index[4] = 3;
		Index[5] = 5;

		GameEngineIndexBuffer::Create("HexaGram", Index);
	}

}


void GameEngineCore::EngineResourcesDestroy()
{
	GameEngineVertexBuffer::ResourcesDestroy();
	GameEngineIndexBuffer::ResourcesDestroy();
}