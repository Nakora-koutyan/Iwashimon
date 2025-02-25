#include "ResourceManager.h"
#include "DxLib.h"

//�ÓI�����o�ϐ���`
ResourceManager* ResourceManager::instance = nullptr;

//���\�[�X�Ǘ��̃C���X�^���X�擾����
ResourceManager* ResourceManager::GetInstance()
{
	//�C���X�^���X���Ȃ���ΐ�������
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//�C���X�^���X�̃|�C���^��ԋp
	return instance;
}
//���\�[�X�Ǘ��̃C���X�^���X�폜����
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
			//���\�[�X�𐶐�
			CreateImagesResource(file_name);
		}
		else
		{
			//���\�[�X�𐶐�
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
	//�R���e�i���ɉ������Ȃ���΁A������ǂݍ���
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
	//�R���e�i���Ƀf�[�^���Ȃ���ΏI��
	if (images_container.size() == NULL)
	{
		return;
	}

	//������Ɖ摜�n���h���f�[�^�̃Z�b�g�Ń��[�v���s��
	for (std::pair<std::string, std::vector<int>>value
		: images_container)
	{
		//�ǂݍ��񂾉摜�̉��
		DeleteSharingGraph(value.second[0]);
		//���I�z��̉��
		value.second.clear();
	}

	//�摜�R���e�i�̉��
	images_container.clear();
}

void ResourceManager::UnloadSoundsAll()
{
	//�R���e�i���Ƀf�[�^���Ȃ��ꍇ�������I��
	if (sounds_container.size() == NULL)
	{
		return;
	}

	//������Ɖ����f�[�^�̃Z�b�g�Ń��[�v���s��
	for (std::pair<std::string, int>value
		: sounds_container)
	{
		DeleteSoundMem(value.second);
	}

	//�����R���e�i�̉��
	sounds_container.clear();
}

void ResourceManager::CreateImagesResource(std::string file_name)
{
	//�w�肳�ꂽ�t�@�C����ǂݍ���
	int handle = LoadGraph(file_name.c_str());

	//�G���[�`�F�b�N
	if (handle == -1)
	{
		throw(file_name + "������܂���\n");
	}

	//�R���e�i�ɓǂݍ��񂾉摜��ǉ�����
	images_container[file_name].push_back(handle);
}

void ResourceManager::CreateSoundsResource(std::string file_name)
{
	//�w�肳�ꂽ�t�@�C����ǂݍ���
	int handle = LoadSoundMem(file_name.c_str());

	//�G���[�`�F�b�N
	if (handle == -1)
	{
		throw(file_name + "������܂���\n");
	}

	//�����R���e�i�ɓǂݍ��񂾉�����ǉ�����
	sounds_container[file_name] = handle;
}

void ResourceManager::CreateImagesResource(std::string file_name,
	int all_num, int num_x, int num_y, int size_x, int size_y)
{
	//�w�肳�ꂽ�t�@�C����ǂݍ���
	int* handle = new int[all_num];
	int err = LoadDivGraph(file_name.c_str(), all_num, num_x,
		num_y, size_x, size_y, handle);

	//�G���[�`�F�b�N
	if (err == -1)
	{
		throw(file_name + "������܂���\n");
	}

	//�R���e�i�ɓǂݍ��񂾉摜��ǉ�����
	for (int i = 0; i < all_num; i++)
	{
		images_container[file_name].push_back(handle[i]);
	}

	//���I�������̉��
	delete[] handle;
}