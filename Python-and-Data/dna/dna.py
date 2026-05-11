import csv
import sys

def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    with open(database_file) as file:
        reader = csv.DictReader(file)

        str_names = reader.fieldnames[1:]
        people = list(reader)


    with open(sequence_file) as file:
        dna_sequence = file.read().strip()


    str_counts = {}
    for STR in str_names:
        str_counts[STR] = longest_match(dna_sequence, STR)


    for person in people:
        match = True
        for STR in str_names:
            if int(person[STR]) != str_counts[STR]:
                match = False
                break
        if match:
            print(person["name"])
            return

   
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
