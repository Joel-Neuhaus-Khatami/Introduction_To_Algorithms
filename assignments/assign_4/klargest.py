#!/usr/bin/python3
# coding=utf-8
import random

# Universitetet på Pluto arrangerer hvert år en opptaksprøve hvor hver 
# student får en poengsum. Denne poengsummen brukes til å rangere søkerne 
# slik at de kk søkerne med høyest poengsum blir tilbudt en studieplass ved
# universitetet. Til dette trenger universitetet et program som kan velge ut de k

# k høyeste poengsummene fra en liste over alle poengsummene.

# Implementer metoden k_largest som tar inn en liste, A
# A, bestående av poengsummene til studentene og en verdi, kk, og returnerer en 
# liste bestående av de kk største poengsummene i AA. Metoden tar også inn nn, 
# som er lengden på listen AA. Hvis det er flere studenter med samme poengsum, og 
# kun noen av disse kan være en del av de k

# k som blir tilbydd plass, kan du selv velge hvilke av disse som kommer inn.

# Ønsker du teste programmet ditt lokalt, finnes det eksempeltester her.

# Merk: Det er ikke lov å bruke innebygd sortering, og algoritmen din bør ha en 
# gjennomsnittlig kjøretid på O(n) O(n) når AA består av unike poengsummer.

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
# Laveste mulige antall tall i generert instans.
numbers_lower = 3
# HÃ¸yest mulig antall tall i generert instans.
numbers_upper = 8
# Om denne verdien er 0 vil det genereres nye instanser hver gang.
# Om den er satt til et annet tall vil de samme instansene genereres
# hver gang, om verdiene over ikke endres.
seed = 0


def k_largest(A, n, k):
    # Skriv koden din her
    pass


# Sett med hardkodete tester pÃ¥ format: (A, k)
tests = [
    ([], 0),
    ([1], 0),
    ([1], 1),
    ([1, 2], 1),
    ([-1, -2], 1),
    ([-1, -2, 3], 2),
    ([1, 2, 3], 2),
    ([3, 2, 1], 2),
    ([3, 3, 3, 3], 2),
    ([4, 1, 3, 2, 3], 2),
    ([4, 5, 1, 3, 2, 3], 4),
    ([9, 3, 6, 1, 7, 3, 4, 5], 4),
]

def gen_examples(k, lower, upper):
    for _ in range(k):
        A = [
                random.randint(-50, 50)
                for _ in range(random.randint(lower, upper))
            ]
        yield A, random.randint(0, len(A))


if generate_random_tests:
    if seed:
        random.seed(seed)
    tests += list(gen_examples(
        random_tests,
        numbers_lower,
        numbers_upper,
    ))

failed = False
for A, k in tests:
    answer = sorted(A, reverse=True)[:k][::-1]
    student = k_largest(A[:], len(A), k)

    if type(student) != list:
        if failed:
            print("-"*50)
        failed = True
        print(f"""
Koden feilet for fÃ¸lgende instans:
A: {A}
n: {len(A)}
k: {k}

Metoden mÃ¥ returnere en liste
Ditt svar: {student}
""")
    else:
        student.sort()
        if student != answer:
            if failed:
                print("-"*50)
            failed = True
            print(f"""
Koden feilet for fÃ¸lgende instans:
A: {A}
n: {len(A)}
k: {k}

Ditt svar: {student}
Riktig svar: {answer}
""")

if not failed:
    print("Koden ga riktig svar for alle eksempeltestene")