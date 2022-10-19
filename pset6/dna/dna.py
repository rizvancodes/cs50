import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE.CSV SEQUENCE.TXT")
    # TODO: Read database file into a variable
    strs = []
    names = []
    filename = sys.argv[1]
    with open(filename) as f:
        reader = csv.DictReader(f)
        for row in reader:
            names.append(row['name'])
            row.pop('name')
            strs.append(row)

    profiles = dict(zip(names, strs))

    # TODO: Read DNA sequence file into a variable
    sequence = (open(sys.argv[2], "r")).read()

    # read column names into list
    columnList = []
    with open(filename) as f:
        reader = csv.reader(f, delimiter = ',')
        for row in reader:
            columnList = row
            break

    # TODO: Find longest match of each STR in DNA sequence
    subjectcount = {}
    for i in columnList[1:]:
        subjectcount[i] = None

    for keys in subjectcount.keys():
        subjectcount[keys] = str(longest_match(sequence, keys))

    # TODO: Check database for matching profiles
    result = check_profiles(subjectcount, profiles)
    if result[0]:
        print(result[1])
    else:
        print("No Match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

def check_profiles(subjectcount, profiles):
    for keys in profiles.keys():
        if subjectcount == profiles[keys]:
            return True, keys
    return False, "No Match"

main()
