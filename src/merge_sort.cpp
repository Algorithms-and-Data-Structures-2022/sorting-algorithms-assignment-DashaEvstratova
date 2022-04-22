#include "assignment/merge_sort.hpp"

#include "assignment/partitioning.hpp"  // middle_of
#include "assignment/merging.hpp"       // merge

namespace assignment {

  void MergeSort::Sort(std::vector<int>& arr) const {

    // буфер памяти для операции слияния (merge)
    std::vector<int> buf(arr.size());
    return merge_sort(arr, 0, static_cast<int>(arr.size()) - 1, buf);
    // забыл что-то здесь вызвать ...
  }

  void MergeSort::merge_sort(std::vector<int>& arr, int start, int stop, std::vector<int>& buf) const {

    // выход из рекурсии: подмассив длины один
    if (start >= stop) {
      return;
    }

    // вычисляем индекс середины области
    const int middle = middle_of(start, stop);
    merge_sort(arr, start, middle, buf);
    merge_sort(arr, middle+1, stop, buf);
    merge(arr, start, middle_of(start, middle),middle, buf);
    merge(arr, middle+1, middle_of(middle+1, stop),stop, buf);
    // рекурсивный вызов сортировки левой [start, middle] и правой [middle + 1, stop] подмассивов ...
    // слияния двух подмассивов [start, middle] и [middle + 1, stop] ...
  }

}  // namespace assignment
