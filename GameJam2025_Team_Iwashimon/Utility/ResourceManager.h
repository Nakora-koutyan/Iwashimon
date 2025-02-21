#pragma once

#include <map>
#include <vector>
#include <string>

struct MaterialParam
{
	std::string file_path;
	int all_num;
	int num_x;
	int num_y;
	int size_x;
	int size_y;
};

class ResourceManager
{
private:

	static ResourceManager* instance;

	//画像保存用の可変長配列
	std::map<std::string, std::vector<int>> images_container;
	//音源保存用の可変長配列
	std::map<std::string, int> sounds_container;

private:
	ResourceManager() = default;

	//コピー禁止
	ResourceManager(ResourceManager& r) = delete;
	ResourceManager& operator=(const ResourceManager& r) = delete;

public:
	~ResourceManager() = default;
public:
	//インスタンスの生成
	static ResourceManager* GetInstance();
	//インスタンスの削除
	static void DeleteInstance();

public:

	//画像名をstring型で受け取る処理
	const std::vector<int>& GetImages(std::string file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	//char型の画像名を受け取る処理
	const std::vector<int>& GetImages(const char* file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	//MaterialParamで管理する
	const std::vector<int>& GetImages(MaterialParam element);

	//音源を取得
	const int& GetSounds(std::string file_name);
	const int& GetSounds(const char* file_name);

	//バックグラウンドで音楽を再生
	const void PlaySoundBack(int sound_handle, int TopPositionFlg);
	//ノーマルで音楽を再生
	const void PlaySoundNormal(int sound_handle, int TopPositionFlg);


	//読みこんだ全画像データの削除
	void UnloadResourceAll();

	//読み込んだ音源ソースデータの全削除
	void UnloadSoundsAll();

private:
	//画像ハンドルから読み込みリソースを作成する
	void CreateImagesResource(std::string file_name);

	//音源用ハンドルから読み込み用のリソースを作成する
	void CreateSoundsResource(std::string file_name);

	//画像リソースの作成
	void CreateImagesResource(std::string file_name, int all_num, int num_x,
		int num_y, int size_x, int size_y);
};