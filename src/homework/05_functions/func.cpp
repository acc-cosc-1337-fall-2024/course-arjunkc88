#include "func.h"//add include statements

//add function code here
double get_gc_content(const std::string& dna)
 {
    int count = 0;
    for(char nucleotide : dna) {
        if(nucleotide == 'C' || nucleotide == 'G') 
        {
            count++;
        }
    }
    return static_cast<double>(count) / dna.size();
}

// Function to reverse a DNA string
std::string get_reverse_string(std::string dna)
 {
    std::string reversed;
    for(int i = dna.size() - 1; i >= 0; i--) 
    {
        reversed += dna[i];
    }
    return reversed;
}

// Function to get the DNA complement
std::string get_dna_complement(std::string dna)
 {
    dna = get_reverse_string(dna); 
    for(char& nucleotide : dna) 
    {
        switch(nucleotide) 
        {
            case 'A': nucleotide = 'T'; break;
            case 'T': nucleotide = 'A'; break;
            case 'C': nucleotide = 'G'; break;
            case 'G': nucleotide = 'C'; break;
        }
    }
    return dna;
}
