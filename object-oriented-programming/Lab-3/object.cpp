#include "Object.hpp"
// Инициализация счётчиков созданных и активных обектов
int Object::activeObjects = 0;
int Object::overallObjects = 0;
// Конструктор объекта
Object::Object()
{
    // Количество операций
    operationsCount = 0;
    objectsCountInc();
};
// Вывод информации о созданных и активных объектах
void Object::printTotalInfo()
{
    printf("Objects created: %d\n", overallObjects);
    printf("Objects active: %d", activeObjects);
}
// Добавление оперции в список объекта
void Object::addOp(const char *operation)
{
    int i;
    // Сохранение прежнего списка для последующего освобождения памяти
    char **tmp = operations;
    // Выделение памяти для нового размера списка
    operations = new char *[++operationsCount];
    for (i = 0; i < operationsCount; i++)
    {
        operations[i] = new char[50];
    }
    // Копирование операций
    if (operationsCount != 1)
    {
        for (i = 0; i < operationsCount - 1; i++)
        {
            strcpy(operations[i], tmp[i]);
        }
    }
    strcpy(operations[operationsCount - 1], operation);
    // Освобождение памяти
    if (operationsCount != 1)
    {
        for (i = 0; i < operationsCount - 1; i++)
        {
            free(tmp[i]);
        }
        free(tmp);
    }
}
// Очистка списка операций объекта
void Object::clearOp()
{
    // Счётчик цикла
    int i;
    // Освобождение памяти
    for (i = 0; i < operationsCount - 1; i++)
    {
        free(operations[i]);
    }
    free(operations);
    // Обнуление длины списка
    operationsCount = 0;
}
// Вывод всех операций
void Object::printOp()
{
    int i;
    for (i = 0; i < operationsCount; i++)
    {
        printf("%s\n", operations[i]);
    }
}
// Оператор присваивания
Object &Object::operator=(const Object &obj)
{
    // Счётчик циклов
    int i;
    // Сохранение указателя на прежний массив для последующего удаления
    char **tmp = operations;
    // Выделение и копирование для уже имевшейся информации
    operationsCount = obj.operationsCount;
    operations = new char *[obj.operationsCount];
    operations = obj.operations;
    if (obj.operationsCount != 0)
    {
        for (i = 0; i < obj.operationsCount; i++)
        {
            operations[i] = new char[20];
            strcpy(operations[i], obj.operations[i]);
        }
        // Освобождение памяти
        for (i = 0; i < obj.operationsCount - 1; i++)
        {
            free(tmp[i]);
        }
        free(tmp);
    }
    return *this;
}
// Конструктор копирования
Object::Object(const Object &obj)
{
    int i;
    // выделение памяти под новый массив
    this->operations = (char **)malloc(sizeof(char *) * obj.operationsCount);
    // Копирование данных
    if (obj.operationsCount != 0)
    {
        for (i = 0; i < obj.operationsCount; i++)
        {
            operations[i] = (char *)malloc(sizeof(char *));
            strcpy(operations[i], obj.operations[i]);
        }
    }
}
// Деструктор орбъекта
Object::~Object()
{
    // Уменьшение количества активных объектов
    objectsCountDec();
}
