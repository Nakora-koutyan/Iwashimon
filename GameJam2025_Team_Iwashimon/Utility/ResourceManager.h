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

	//�摜�ۑ��p�̉ϒ��z��
	std::map<std::string, std::vector<int>> images_container;
	//�����ۑ��p�̉ϒ��z��
	std::map<std::string, int> sounds_container;

private:
	ResourceManager() = default;

	//�R�s�[�֎~
	ResourceManager(ResourceManager& r) = delete;
	ResourceManager& operator=(const ResourceManager& r) = delete;

public:
	~ResourceManager() = default;
public:
	//�C���X�^���X�̐���
	static ResourceManager* GetInstance();
	//�C���X�^���X�̍폜
	static void DeleteInstance();

public:

	//�摜����string�^�Ŏ󂯎�鏈��
	const std::vector<int>& GetImages(std::string file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	//char�^�̉摜�����󂯎�鏈��
	const std::vector<int>& GetImages(const char* file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	//MaterialParam�ŊǗ�����
	const std::vector<int>& GetImages(MaterialParam element);

	//�������擾
	const int& GetSounds(std::string file_name);
	const int& GetSounds(const char* file_name);

	//�o�b�N�O���E���h�ŉ��y���Đ�
	const void PlaySoundBack(int sound_handle, int TopPositionFlg);
	//�m�[�}���ŉ��y���Đ�
	const void PlaySoundNormal(int sound_handle, int TopPositionFlg);


	//�ǂ݂��񂾑S�摜�f�[�^�̍폜
	void UnloadResourceAll();

	//�ǂݍ��񂾉����\�[�X�f�[�^�̑S�폜
	void UnloadSoundsAll();

private:
	//�摜�n���h������ǂݍ��݃��\�[�X���쐬����
	void CreateImagesResource(std::string file_name);

	//�����p�n���h������ǂݍ��ݗp�̃��\�[�X���쐬����
	void CreateSoundsResource(std::string file_name);

	//�摜���\�[�X�̍쐬
	void CreateImagesResource(std::string file_name, int all_num, int num_x,
		int num_y, int size_x, int size_y);
};