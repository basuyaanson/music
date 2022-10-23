#include"res.h"

map<int, string>Res::music;

//���ѳX�ݼƾ�
Res* Res::getres()
{
    static Res* p = new Res;
    return p;
}

//�P�_���O�_�����֤��(.mp3)
bool Res::ismusic(const string& name)
{
    int lenght = name.size();
    return name.substr(lenght - 4) == ".mp3";
}

//�p�G���֤�󦳪Ů�,������_
string Res::getnewname(string name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == ' ')
        {
            name[i] = '_';
        }
    }
    return name;
}

//�M�����
void Res::traverfile()
{
    system("color 70");
    cout << "�п�J���֮w��󧨸��|:";
    string resroot;
    cin >> resroot;
    //�P�w���|�O�_�s�b�����ɮ�
    filesystem::path ress(resroot);

    if (!filesystem::exists(ress))
    {
        cout << "����쭵���ɮ�......" << endl;
        exit(0);
    }

    //�o���e���|�U�Ҧ����֪������|
    int pos = 1;
    string oldname;
    string newname;
    filesystem::directory_iterator begin(ress);
    for (filesystem::directory_iterator end; begin != end; ++begin)//�M�����
    {
        if (!filesystem::is_directory(begin->path()))//�P�w�O�_��.mp3(***�|���L��e���|�U����L���***)
        {
            if (ismusic(begin->path().filename().string()))// �P�_���O�_�����֤��(.mp3)
            {
                //�p�G���֤�󦳪Ů�,������_
                oldname = resroot + "/" + begin->path().filename().string();
                newname = getnewname(oldname);
                int resulf = rename(oldname.c_str(), newname.c_str());//.c_str():�Nstring�ഫ��c�y����str
                music[pos++] = newname;

            }
        }
    }
    cout << "���֮w�[�����\....." << endl;
}

//��l�ƭ��֮w
Res::Res()
{
    cout << "��l�ƭ��֮w.....\n\n";
    traverfile();
}
