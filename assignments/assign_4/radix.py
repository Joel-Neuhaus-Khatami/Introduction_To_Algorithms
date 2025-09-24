# coding=utf-8
import random
from string import ascii_lowercase

# Universitetet på Pluto ønsker også å sortere lister over studenter i leksikalsk rekkefølge. 
# Det vil si slik at for eksempel «a» kommer før «b» og «aab» kommer før «ab», men etter «aa». 
# Plutonske navn fungerer ikke slik som i Norge, og kan både være veldig korte (for eksempel «a») 
# eller veldig lange (mange tusener av tegn). Derfor er det ønskelig med en algoritme som sorterer 
# en liste i lineær tid basert på den totale lengden til alle strengene, og ikke som en funksjon 
# av den maksimale lengden til et navn. Plutonske navn kan også kun inneholde de små bokstavene 
# fra og med «a» til og med «z».

# Implementer en variant av RADIX-SORT

# RADIX-SORT som sorterer et sett med plutonske navn i leksikalsk rekkefølge. Metoden skal ta inn en 
# liste, A, lengden på listen, n, og den maksimale lengden, d, et navn kan ha. Metoden skal returnere 
# den sorterte listen. Sorteringen må gå i lineær tid basert på den totale lengden til alle strengene.

# Ønsker du teste programmet ditt lokalt, finnes det eksempeltester her.

# Testsettet pÃ¥ serveren er stÃ¸rre og mer omfattende enn dette.
# Hvis programmet ditt fungerer lokalt, men ikke nÃ¥r du laster det opp,
# er det gode sjanser for at det er tilfeller du ikke har tatt hÃ¸yde for.

# De lokale testene bestÃ¥r av to deler. Et sett med hardkodete
# instanser som kan ses lengre nedre, og muligheten for Ã¥ generere
# tilfeldige instanser. Genereringen av de tilfeldige instansene
# kontrolleres ved Ã¥ justere pÃ¥ verdiene under.

# Kontrollerer om det genereres tilfeldige instanser.
generate_random_tests = False
# Antall tilfeldige tester som genereres.
random_tests = 10
# Laveste mulige antall strenger i generert instans.
n_strings_lower = 3
# HÃ¸yest mulig antall strenger i generert instans.
n_strings_upper = 8
# Laveste mulige antall tegn i hver streng i generert instans.
n_chars_lower = 3
# HÃ¸yest mulig antall tegn i hver streng i generert instans.
n_chars_upper = 15
# Antall forskjellige bokstaver som kan brukes i strengene. MÃ¥ vÃ¦re mellom 1 og
# 26. Plukker de fÃ¸rste `n_diff_chars` bokstavene i alfabetet.
n_diff_chars = 5
# Om denne verdien er 0 vil det genereres nye instanser hver gang.
# Om den er satt til et annet tall vil de samme instansene genereres
# hver gang, om verdiene over ikke endres.
seed = 0

def char_to_int(char):
    if (char ==''):
        return -1
    return ord(char) - 97



def flexradix(A, n, d):
    # Skriv koden din her
    charValues = []
    for i in range(n):
        charRow = [] 
        for j in range(d):
            if j < len(A[i]):
                charRow.append(char_to_int(A[i][j]))
            else:
                charRow.append(-1) 
        charValues.append(charRow)  #

    for stringIndex in reversed(range(d)):
        k = 27
        counts = [0] * k
        sortedList = [0] * n
        sortedCharvalues = [0] * n

        for i in range(n):
            charInt = charValues[i][stringIndex]
            counts[charInt + 1] += 1 

        for i in range(1, k):
            counts[i] += counts[i - 1]
        
        for i in reversed(range(n)):
            charInt = charValues[i][stringIndex]
            sortedList[counts[charInt + 1] - 1] = A[i]
            sortedCharvalues[counts[charInt + 1] - 1] = charValues[i]
            counts[charInt + 1] -= 1

        A = sortedList
        charValues = sortedCharvalues

    return A

# Hardkodete instanser pÃ¥ format: (A, d)
tests = [
    ([], 1),
    (["a"], 1),
    (["a", "b"], 1),
    (["b", "a"], 1),
    (["a", "z"], 1),
    (["z", "a"], 1),
    (["ba", "ab"], 2),
    (["b", "ab"], 2),
    (["ab", "a"], 2),
    (["zb", "za"], 2),
    (["abc", "b"], 3),
    (["xyz", "y"], 3),
    (["abc", "b"], 4),
    (["xyz", "y"], 4),
    (["zyxy", "yxz"], 4),
    (["ab", "aaa"], 3),
    (["abc", "b", "bbbb"], 4),
    (["abcd", "abcd", "bbbb"], 4),
    (["abcd", "wxyz", "bbbb"], 4),
    (["abcd", "wxyz", "bazy"], 4),
    (["ab", "aab", "aaab", "aaaab", "aaaaab"], 6),
    (["a", "b", "c", "babcbababa"], 10),
    (["a", "b", "c", "babcbababa"], 10),
    (["w", "x", "y", "xxyzxyzxyz"], 10),
    (["b", "a", "y", "xxyzxyzxyz"], 10),
    (["jfiqdopvak", "nzvoquirej", "jfibopvmcq"], 10),
]

def gen_examples(k, nsl, nsu, ncl, ncu):
    for _ in range(k):
        strings = [
            "".join(random.choices(
                ascii_lowercase,
                k=random.randint(ncl, ncu)
            )) for _ in range(random.randint(nsl, nsu))
        ]
        yield (strings, max(map(len, strings)))


if generate_random_tests:
    ascii_lowercase = ascii_lowercase[:n_diff_chars]
    if seed:
        random.seed(seed)
    tests += list(gen_examples(
        random_tests,
        n_strings_lower,
        n_strings_upper,
        n_chars_lower,
        n_chars_upper,
    ))

failed = False
for A, d in tests:
    answer = sorted(A)
    student = flexradix(A[:], len(A), d)
    if student != answer:
        if failed:
            print("-"*50)
        failed = True

        print(f"""
Koden feilet for fÃ¸lgende instans:
A: {A}
n: {len(A)}
d: {d}

Ditt svar: {student}
Riktig svar: {answer}
""")

if not failed:
    print("Koden ga riktig svar for alle eksempeltestene")
