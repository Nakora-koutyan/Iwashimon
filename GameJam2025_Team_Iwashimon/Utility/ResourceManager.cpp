#include "ResourceManager.h"
#include "DxLib.h"

//静的メンバ変数定義
ResourceManager* ResourceManager::instance = nullptr;

//リソース管理のインスタンス取得処理
ResourceManager* ResourceManager::GetInstance()
{
	//インスタンスがなければ生成する
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//インスタンスのポインタを返却
	return instance;
}
//リソース管理のインスタンス削除処理
void ResourceManager::DeleteInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

const std::vector<int>& ResourceManager::GetImages(std::string file_name,
	int all_num, int num_x, int num_y, int size_x, int size_y)
{
	if (images_container.count(file_name) == NULL)
	{
		if (all_num == 1)
		{
			//リソースを生成
			CreateImagesResource(file_name);
		}
		else
		{
			//リソースを生成
			CreateImagesResource(file_name,
				all_num, num_x, num_y, size_x, size_y);
		}
	}

	return images_container[file_name];
}

const std::vector<int>& ResourceManager::GetImages(const char* file_name,
	int all_num, int num_x, int num_y, int size_x, int size_y)
{
	return GetImages(std::string(file_name),

		all_num, num_x, num_y, size_x, size_y);
}

const std::vector<int>& ResourceManager::GetImages(MaterialParam element)
{
	return GetImages(element.file_path,
		element.all_num, element.num_x, element.num_y,
		element.size_x, element.size_y);
}

const int& ResourceManager::GetSounds(std::string file_name)
{
	//コンテナ内に音源がなければ、音源を読み込む
	if ((sounds_container.count(file_name) == NULL))
	{
		CreateSoundsResource(file_name);
	}

	return sounds_container[file_name];
}

const int& ResourceManager::GetSounds(const char* file_name)
{
	return GetSounds(std::string(file_name));
}

const void ResourceManager::PlaySoundBack(int sound_handle,
	int TopPositionFlg)
{
	PlaySoundMem(sound_handle, DX_PLAYTYPE_BACK, TopPositionFlg);
}

const void ResourceManager::PlaySoundNormal(int sound_handle,
	int TopPositionFlg)
{
	PlaySoundMem(sound_handle, DX_PLAYTYPE_NORMAL, TopPositionFlg);
}
 
void ResourceManager::UnloadResourceAll()
{
	//コンテナ内にデータがなければ終了
	if (images_container.size() == NULL)
	{
		return;
	}

	//文字列と画像ハンドルデータのセットでループを行う
	for (std::pair<std::string, std::vector<int>>value
		: images_container)
	{
		//読み込んだ画像の解放
		DeleteSharingGraph(value.second[0]);
		//動的配列の解放
		value.second.clear();
	}

	//画像コンテナの解放
	images_container.clear();
}

void ResourceManager::UnloadSoundsAll()
{
	//コンテナ内にデータがない場合処理を終了
	if (sounds_container.size() == NULL)
	{
		return;
	}

	//文字列と音源データのセットでループを行う
	for (std::pair<std::string, int>value
		: sounds_container)
	{
		DeleteSoundMem(value.second);
	}

	//音源コンテナの解放
	sounds_container.clear();
}

void ResourceManager::CreateImagesResource(std::string file_name)
{
	//指定されたファイルを読み込む
	int handle = LoadGraph(file_name.c_str());

	//エラーチェック
	if (handle == -1)
	{
		throw(file_name + "がありません\n");
	}

	//コンテナに読み込んだ画像を追加する
	images_container[file_name].push_back(handle);
}

void ResourceManager::CreateSoundsResource(std::string file_name)
{
	//指定されたファイルを読み込む
	int handle = LoadSoundMem(file_name.c_str());

	//エラーチェック
	if (handle == -1)
	{
		throw(file_name + "がありません\n");
	}

	//音源コンテナに読み込んだ音源を追加する
	sounds_container[file_name] = handle;
}

void ResourceManager::CreateImagesResource(std::string file_name,
	int all_num, int num_x, int num_y, int size_x, int size_y)
{
	//指定されたファイルを読み込む
	int* handle = new int[all_num];
	int err = LoadDivGraph(file_name.c_str(), all_num, num_x,
		num_y, size_x, size_y, handle);

	//エラーチェック
	if (err == -1)
	{
		throw(file_name + "がありません\n");
	}

	//コンテナに読み込んだ画像を追加する
	for (int i = 0; i < all_num; i++)
	{
		images_container[file_name].push_back(handle[i]);
	}

	//動的メモリの解放
	delete[] handle;
}