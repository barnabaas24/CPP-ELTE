#ifndef ARRACVIEW_H
#define ARRACVIEW_H


template<class T>
class array_accumulate_view{

    private:
    T* accumulator_array;
    int arraySize;

    public:

    
    // array_accumulate_view(const T* array, int arr_size) : accumulator_array(array), arraySize(arr_size) {
        
    //     for (int i = 1; i < arraySize; i++)
    //     {
    //         accumulator_array[i] += accumulator_array[i-1];
    //     }
        
        
    //     // accumulator_array = new T[arr_size];
        
    //     // for (int i = 0; i < arr_size; i++)
    //     // {
    //     //     if(i!=0){
    //     //         accumulator_array[i]=(accumulator_array[i-1]+array[i]);
    //     //     }
    //     //     else{
    //     //         accumulator_array[i]=array[i];
    //     //     }
    //     // }
    // }

    array_accumulate_view(const T* array, int arr_size) : arraySize(arr_size) {
        accumulator_array = new T[arr_size];

        for (int i = 0; i < arr_size; i++) {
            accumulator_array[i] = array[i];
        }

        for (int i = 1; i < arraySize; i++) {
            accumulator_array[i] += accumulator_array[i - 1];
        }
    }

    void printer() const {
        for (int i = 0; i < arraySize; i++)
        {
            std::cout << accumulator_array[i] << " ";
        }

        std::cout << std::endl;
        
    }

    T size() const{
        return this->arraySize;
    }

    T at(int index) const {
        return accumulator_array[index];
    }

    

};






#endif