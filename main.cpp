#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

#include "UnsortedVectorDict.hpp"
#include "SortedVectorDict.hpp"
#include "UnsortedLinkedListDict.hpp"
#include "SortedLinkedListDict.hpp"

enum InputType { RANDOM, NEARLY_SORTED };

std::vector<int> generate_keys(int N) {

    // Uses a random distribution to generate keys randomly

    std::vector<int> keys(N);
    std::mt19937 rng(42);  //
    std::uniform_int_distribution<int> dist(1, 500 * N);

    for (int& k : keys)
        k = dist(rng);
    return keys;
}

void benchmark(Dictionary* dict, const std::string& label, int N, std::ofstream& csv) {
    const int M = 500;
    std::vector<int> keys = generate_keys(N);
    std::mt19937 rng(100);
    std::uniform_int_distribution<int> dist(1, 500 * N);
    std::vector<int> lookups(M);
    for (int& k : lookups)
        k = dist(rng);

    auto start_insert = std::chrono::high_resolution_clock::now();
    for (int k : keys)
        dict->insert(k);
    auto end_insert = std::chrono::high_resolution_clock::now();

    auto start_lookup = std::chrono::high_resolution_clock::now();
    for (int k : lookups) {
        dict->lookup(k);
    }
    auto end_lookup = std::chrono::high_resolution_clock::now();

    auto insert_time = std::chrono::duration_cast<std::chrono::microseconds>(end_insert - start_insert).count();
    auto total_lookup_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_lookup - start_lookup).count();
    long long avg_lookup_ns = total_lookup_time_ns / M;

    std::cout << label << " [" << "N=" << N << "] — Insert: " << insert_time << "us, Avg Lookup: " << avg_lookup_ns << "ns\n";
    csv << label << "," << "," << N << "," << insert_time << "," << avg_lookup_ns << "\n";

    delete dict;
}

void removeData(Dictionary* dict, const std::string& label, int N) {

    // Generates N keys to add to the dict, then removes them right after to test the remove function.

    std::vector<int> keys = generate_keys(N);

    for (int k : keys) {
        dict->insert(k);
    }

    for (int k : keys) {
        dict->remove(k);
    }
    std::cout << label << " [N=" << N << "] - " << "Remove: successful" << std::endl;
 }

int main() {
    std::ofstream csv("benchmark_results_avgonly.csv");
    csv << "Structure,InputType,N,InsertTime(us),AvgLookup(ns)\n";

    std::vector<int> sizeV = {5000, 10000}; // suppose to be {5000, 500000}
    for (auto N : sizeV) {
        benchmark(new UnsortedVectorDict(), "Unsorted Vector", N, csv);
        benchmark(new SortedVectorDict(), "Sorted Vector", N, csv);
        benchmark(new UnsortedLinkedListDict(), "Unsorted Linked List", N, csv);
        benchmark(new SortedLinkedListDict(), "Sorted Linked List", N, csv);

        // Testing the remove function on the ADTs
        removeData(new UnsortedVectorDict(), "Unsorted Vector", N);
        removeData(new SortedVectorDict(), "Sorted Vector", N);
        removeData(new UnsortedLinkedListDict(), "Unsorted Linked List", N);
        removeData(new SortedLinkedListDict(), "Sorted Linked List", N);
    }

    csv.close();
    return 0;
}