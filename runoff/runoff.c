#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates          max candidates kadar candidate oluştur demek bu
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        // atama yapıyoruz burada

        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string(" %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // üstte for i ve for j diye iç içe iki for açmıştık ki bu şunu temsil ediyordu:
            // i . oy verenin sıralamasında j. sıra
            // bu i ve j yi vote functionunun içine koyduk [voter] [rank] diye. Böylece preferences arrayindeki i. oy verenin j. sırası,
            // bu functionun içindeki i ye eşit oldu. bu functionun içindeki i de adayların isimleri aslında
            // atıyorum alice yerine 0, bob yerine 1 oluyor i.
            // özetle i. oy verenin j. tercihi 0(alice), veya 1(bob) gibi bir sonuç çıktı
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int adayNo = preferences[i][j];
            // preferences [i][j] aday kişilerden birini ifade ediyordu, bunu adayNo diye bir variable e atadık
            // eğer bu aday elenmişse diye kontrol ediyoruz şimdi:

            if (candidates[adayNo].eliminated == false)
            {
                candidates[adayNo].votes ++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // tek tek tüm candidateleri gez, eğer toplam oyların yarısını geçen varsa balkon konuşması

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // int minOy = 99999; for döngüsüyle candidate gez, içine if (candidate[i].votes < minOy && candidate[i].eliminated == false) minOy = bu

    int minOy;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < minOy && candidates[i].eliminated == false) // (candidate[i].eliminated == false)
        {
            minOy = candidates[i].votes;
        }
    }// minimum oy sayısını yollamamızı istiyor, maine yazıyor olsaydık elimine işlemini de burada yapardım ben.
    return minOy;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // elimizde en az 1 tane adayın oy sayısı minOy olarak var zaten. Eğer eşitlik varsa herkes aynıdır, yani minOy eşitse diğer oylara
    // tie deriz. değilse tie false döndürürüz.
    // veya bir candidate oyu alırız yine. ona eşit mi diye sorarız ama bu efektif olmaz.

    int zort = 0;   // eğer eşit olmayan çıkarsa eşitlik zortlar

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && candidates[i].eliminated == false)
        {
            zort ++;
        }
    }
    if (zort == 0)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}