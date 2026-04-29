drink = ["tea", "coffee", "watter", "na3na3"]
hot = ["cold", "hot"]
size = ["small", "large"]
s = ["none", "showay", "med", "zyadh"]
milk = ["bdon", "with"]
ice = ["bdon" , "with"]

# --------------------------------
print("Welcome to our program!\n")

x = int(input("enter your order"))

# Unpack the values
drink_n = x & 0b0000_0011
hot_n = (x & 0b0000_0100) >> 2
size_n = (x & 0b0000_1000) >> 3
s_n = (x & 0b0011_0000) >> 4
milk_n = (x & 0b0100_0000) >> 6
ice_n = (x & 0b1000_0000) >> 7


print("Your order is:")
print("drink type: ", drink[drink_n])
print("hot/cold: ", hot[hot_n])
print("size: ", size[size_n])
print("suger: ", s[s_n])
print("milk: ", milk[milk_n])
print("ice: ", ice[ice_n])
