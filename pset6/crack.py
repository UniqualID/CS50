from crypt import crypt
import sys
def main():
    if len(sys.argv) != 2:
        print("Usage: python cracy.py <word>")
    origWord = sys.argv[1]
    salt = origWord[0:2]
    letters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for first in letters:
        for second in letters:
            for third in letters:
                for forth in letters:
                    for fifth in letters[1:]:
                        word = f"{first}{second}{third}{forth}{fifth}".strip()
                        cryptedWord = crypt(word, salt)
                        if cryptedWord != origWord:
                            print(f"{origWord}\t{salt}\t|\t{word}:\t{cryptedWord}")


if __name__ == "__main__":
    main()