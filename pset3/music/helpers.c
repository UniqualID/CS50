// Helper functions for music
#include <math.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdio.h>
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return (fraction[0] - '0') * (8 / (int)(fraction[2] - '0'));
}


// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char num, sharp, octave;
    double frequency;
    int semitones;
    num = note[0];
    if (strlen(note) == 3)
    {
        sharp = note[1];
        octave = note[2];
    }
    else
    {
        sharp = ' ';
        octave = note[1];
    }
    int octDiff = (octave - '0') - 4 ;
    frequency = 440.0 * pow(2.0, octDiff);

    switch (num)
    {
        case 'A':
            semitones = 0;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
        case 'B':
            semitones = 2;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
        case 'C':
            semitones = -9;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
        case 'D':
            semitones = -7;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
        case 'E':
            semitones = -5;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
        case 'F':
            semitones = -4;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
        case 'G':
            semitones = -2;
            if (sharp == '#')
                semitones++;
            else if (sharp == 'b')
                semitones--;
            break;
    }
    int final = round(frequency * pow(2, semitones/12.0));
    return final;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0] == '\0')
    {
       return true;
    }
    return false;
}