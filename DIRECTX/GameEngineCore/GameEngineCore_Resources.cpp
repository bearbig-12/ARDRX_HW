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
	// 사각형 박스 에러용 텍스처 등등
	// 엔진수준에서 기본적으로 지원줘야 한다고 생각하는
	// 리소스들을 이니셜라이즈하는 단계


	{
		// 0       1

		//    원점
		
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

		//    원점

		// 3       2

		std::vector<int> Index;

		// 첫번째 삼각형
		// 디폴트 생성자로 인자를 뒤에 추가해주는 요소 추가 함수.
		Index.resize(6);

		// 첫번째
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// 두번째
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

		// 첫번째
		Index[0] = 0;
		Index[1] = 2;
		Index[2] = 4;

		// 두번째
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