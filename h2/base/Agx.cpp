#include "Agx.h"
void Agx::print()
{
    cout << "型号: " << this->model << endl;
    cout << "AI: " << this->ai << "TOPS" << endl;
    cout << "CUDA核心: " << this->cudas << endl;
    cout << "Tensor CORE: " << this->tensor_core << endl;
    cout << "显存: " << this->video_storage << "G" << endl;
    cout << "存储: " << this->storage << "G" << endl;
}

void Agx::save()
{
    ofstream fw;
    fw.open("../doc/test.txt",ios::app);
    fw << "型号: " << this->model << endl;
    fw << "AI: " << this->ai << "TOPS" << endl;
    fw << "CUDA核心: " << this->cudas << endl;
    fw << "Tensor CORE: " << this->tensor_core << endl;
    fw << "显存: " << this->video_storage << "G" << endl;
    fw << "存储: " << this->storage << "G" << endl;
    fw.close();
}

void Agx::setModel(string model)
{
    this->model = model;
}

void Agx::setAi(int ai)
{
    this->ai = ai;
}

void Agx::setCudas(int cudas)
{
    this->cudas = cudas;
}

void Agx::setVideoStorage(int video_storage)
{
    this->video_storage = video_storage;
}

void Agx::setStorage(int storage)
{
    this->storage = storage;
}
