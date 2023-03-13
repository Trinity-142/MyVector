template<typename T>
class Vector {
    T* buffer; // Указатель на место хранения массива
    unsigned int size = 0; //Размер вектора, реально занятые ячейки массива buffer
    unsigned int capacity = 10; //Размер массива, резерв
    //Увеличение размера резерва
    void SetNewCapacity(unsigned int newCap) {
        capacity = newCap; //увеличиваем резерв
        T* newBuffer = new T[capacity];  //По новому указателю создаете новый массив нового размера
        for (unsigned int i = 0; i < size; ++i) {
            newBuffer[i] = buffer[i];
        }//Перенос значений в новый
        delete[] buffer; //Удалить старый 
        buffer = newBuffer; //Меняем указатель
    }

public:
    //Конструкторы
    Vector() {
        buffer = new T[capacity];
    }

    Vector(unsigned int size) : size(size), capacity(2 * size) {
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = T();
        }
    }

    Vector(unsigned int size, const T& defaultValue) : size(size), capacity(2 * size) {
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = defaultValue;
        }
    }

    Vector(const Vector& another) : size(another.size), capacity(another.capacity) {
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = another.buffer[i];
        }
    }

    Vector& operator=(const Vector& another) {
        if (&another == this) {
            return *this;
        }
        delete[] buffer;
        size = another.size;
        capacity = another.capacity;
        buffer = new T[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            buffer[i] = another.buffer[i];
        }
    }

    ~Vector() {
        delete[] buffer;
    }

    T& At(unsigned int index) {
        return buffer[index];
    }

    const T& At(unsigned int index) const {
        return buffer[index];
    }

    T& operator[](unsigned int index) {
        return buffer[index];
    }

    const T& operator[](unsigned int index) const {
        return buffer[index];
    }

    void PushBack(const T& element) {
        if (size == capacity) {
            SetNewCapacity(2 * capacity);
        }
        auto newIndex = size;
        buffer[newIndex] = element;
        ++size;
    }
    void Insert(unsigned int atIndex, const T& element) {
        if (size == capacity) {
            SetNewCapacity(2 * capacity);
        }
        for (unsigned int i = size; i >= atIndex + 1; --i) {
            buffer[i] = buffer[i - 1];
        }
        buffer[atIndex] = element;
        ++size;
    }

    void PopBack() {
        --size;
    }

    void Erase(unsigned int atIndex) {
        for (unsigned int i = atIndex + 1; i < size; ++i) {
            buffer[i - 1] = buffer[i];
        }
        --size;
    }

    void Resize(unsigned int newSize) {
        if (newSize > capacity) {
            SetNewCapacity(2 * newSize);
        }
        size = newSize;
    }

    unsigned int Size() const {
        return size;
    }
};