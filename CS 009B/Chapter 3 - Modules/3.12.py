import math

# An isotope has half-life T.
# Return the amount of a starting mass N0
# of the isotope that remains after time t,
def compute_Nt(N0, t, T):
    # Type your code here.
    return N0 * math.pow(math.e, ((-1) * 0.693 * t)/T)
# Return the half-life of an isotope given that
# a mass N0 decays to Nt after time t

def compute_T(N0, Nt, t):
    # Type your code here.
    return ((-1) * 0.693 * t)/(math.log(Nt/N0))
if __name__ == '__main__':
    choice = input()
    
    if choice == 'N':  # Calculate amount of material
        # TODO: Read N0, t, and T from one line of input and compute Nt
        #compute_Nt(int(input()), int(input()), float(input()))
        strinput = input()
        newstr = strinput.split()
        Nt = compute_Nt(int(newstr[0]), int(newstr[1]), float(newstr[2]))
        print(f'Nt = {Nt:.4f}')
    elif choice == 'T':                    # Calculate half-life
        # TODO: Read N0, Nt, and t from one line of input and compute T
        strinput = input()
        newstr = strinput.split()
        T = compute_T(int(newstr[0]), float(newstr[1]), int(newstr[2]))
        print(f'T = {T:.4f}')
    else:
        print("invalid choice")
