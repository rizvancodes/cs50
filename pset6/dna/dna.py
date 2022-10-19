import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE.CSV SEQUENCE.TXT")
    # TODO: Read database file into a variable
    id = []
    filename = sys.argv[1]
    with open(filename) as f:
        reader = csv.DictReader(f)
        for row in reader:
            id.append(row)

    profiles = {}
    for item in id:
        for j in item:
            profiles[item[j]] = None
            item.pop('name')
            break

    for keys in profiles.keys():
        for item in id:
            profiles[keys] = item

    print(profiles)


    # TODO: Read DNA sequence file into a variable
    sequence = (open(sys.argv[2], "r")).read()
    print(sequence)

    # read column names into list
    columnList = []
    with open(filename) as f:
        reader = csv.reader(f, delimiter = ',')
        for row in reader:
            columnList = row
            break
    print(columnList)

    # TODO: Find longest match of each STR in DNA sequence
    subjectcount = {}
    for i in columnList[1:]:
        subjectcount[i] = None
    print(subjectcount)

    for keys in subjectcount.keys():
        subjectcount[keys] = longest_match(sequence, keys)
    print(subjectcount)

    # TODO: Check database for matching profiles
    result = check_profiles(subjectcount, profiles)
    print(result)


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

def check_profiles(sequencecount, profiles):
    for keys in profiles.keys():
        if sequencecount == profiles[keys]:
            return 1, keys

main()
