club = ["Al Nassr", "Al Hilal", "Al Ahli", "Al Qadsiah", "Al-Taawoun", "Al Ittihad", "Al-Ettifaq", "Neom SC", "Al Hazem", "Al Khaleej", "Al-Fayha", "Al Fateh", "Al Shabab", "Al Kholood", "Damac", "Al Riyadh", "Al Akhdoud", "Al Najmah"]
result = ["Draw","First team win", "Second team win", "Cancel"]
mal3ab = ["First team", "Second team"]
botola = ["Dowre", "Kas Al Malk", "Kas Al Sobar", "Dowre Asia"]
hakam = ["global", "local"]


# --------------------------------
print("Welcome to our program!\n")
x = 0
while True:
    x = int(input("Enter 16 bit number or -1 to exit: "), 0)
    if x < 0:
        exit()

    # Unpack the values
    club1 = x & 0b0000_0000_0001_1111
    club2 = (x & 0b0000_0011_1110_0000) >> 5
    result_n = (x & 0b0000_1100_0000_0000) >> 10
    mal3ab_n = (x & 0b0001_0000_0000_0000) >> 12
    botola_n = (x & 0b0110_0000_0000_0000) >> 13
    hakam_n = (x & 0b1000_0000_0000_0000) >> 15

    # Error handling
    if club1 >= 18 or club2 >= 18:
        print("ValueError: The club number must be (0-17)")
        continue

    if club1 == club2:
        print("LogicalError: The club cannot play against itself")
        continue

    print("Your match result is:")
    print("Fisrt team:", club[club1])
    print("Second team:", club[club2])
    print("The result:", result[result_n])
    print("The mal3ab is for the:", mal3ab[mal3ab_n])
    print("The botola is:", botola[botola_n])
    print("The hakam is:", hakam[hakam_n])
