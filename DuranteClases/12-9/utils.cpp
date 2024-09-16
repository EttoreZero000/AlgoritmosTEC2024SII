
#include "clase.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<estudiante> ordenarBucketSort(std::vector<estudiante> _estudiante){
    int n = _estudiante.size();
    if (n <= 0)
        return _estudiante; // return an empty vector if input is empty

    // Create 10 buckets for promedioGeneral ranges
    std::vector<std::vector<estudiante>> buckets(10);

    // Distribute students into buckets based on promedioGeneral
    for (estudiante value : _estudiante) {
        int bucketIndex = 9 - static_cast<int>(value.promedioGeneral / 10); // Invertir el índice
        buckets[bucketIndex].push_back(value);
    }

    // Sort each bucket by promedioSemestreAnterior and then by cantidadCursosAprobados
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(), [](const estudiante& a, const estudiante& b) {
            if (a.promedioSemestreAnterior == b.promedioSemestreAnterior) {
                return a.cantidadCursosAprobados > b.cantidadCursosAprobados;  // Mayor a menor
            }
            return a.promedioSemestreAnterior > b.promedioSemestreAnterior;  // Mayor a menor
        });
    }

    // Merge the sorted buckets into a single vector
    std::vector<estudiante> sortedEstudiantes;
    for (const auto& bucket : buckets) {
        sortedEstudiantes.insert(sortedEstudiantes.end(), bucket.begin(), bucket.end());
    }

    return sortedEstudiantes;
}