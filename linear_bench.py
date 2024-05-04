import torch
import torch as nn
import torch.nn.init as init  # Import torch.nn.init

import re


from linear_test import Linear

from linear_test import valuew

##new code for parsing simulation log file FOR OPENHLS.
#######################################################################################################################################################
output_value = None

with open("simulate.log", "r") as file:
    simulation_log = file.read()

# Regular expression pattern to extract the output value
pattern = r"Output value:\s*([\d.e+-]+)"

# Search for the pattern in the log text
match = re.search(pattern, simulation_log)

if match:
    output_value = match.group(1)
    print("Output value:", output_value)
else:
    print("Output value not found in the simulation log.")

def convert_flopco(output_value):
    # Convert output value to binary string
    binary_string = bin(int(output_value, 16))[2:]  # Convert to binary and remove '0b' prefix
    # Pad the binary string with zeros to the left to make it 12 bits long
    padded_binary_string = binary_string.zfill(12)
    return padded_binary_string

binary_output = convert_flopco(output_value)
print("Binary representation of output value:", binary_output)

def convert_binary_to_decimal(binary_value):
    # Extract relevant bits according to the encoding scheme
    sign_bit = int(binary_value[0])  # Sign bit
    exponent_bits = binary_value[3:8]  # Exponent bits
    fraction_bits = binary_value[8:12]  # Fraction bits

    # Calculate the exponent value
    exponent = int(exponent_bits, 2) - 15

    # Calculate the fraction value
    # Calculate the fraction value
    fraction = sum((int(bit) * (2 ** (-i))) for i, bit in enumerate(fraction_bits, start=1))

    # Calculate the final decimal value using the specified encoding
    decimal_value = (-1) ** sign_bit * 2 ** exponent * (1 + fraction)

    return decimal_value

vectorC = convert_binary_to_decimal(binary_output)
print("Final representation of output value:", vectorC)

#########################################################################################################################################################

#new code for parsing log file from ScaleHLS

with open("forward_csim.log", "r") as file:
    text = file.read()

# Define the regular expression pattern
pattern = r"Value of v62 after function call: (\d+)"

# Find the matching pattern in the text
match = re.search(pattern, text)

vectorB = None
# Extract the vectorB after the specified text
if match:
    vectorB = int(match.group(1))
    print("vectorB after 'Value of v62 after function call':", vectorB)
else:
    print("No match found.")

###########################################################################################################################################################


# Cod that insantiates PyTorch TestBench.
def make_linear(size=11, simplify_weights=False, bias=True):
    with torch.no_grad():
        mod = Linear(size, bias=bias)
        mod.eval()
        print(mod)
        
        mod.eval()

        print("Weights:")
        for name, param in mod.named_parameters():
            if param.requires_grad:
                print(name, param.data)

        return mod

model = make_linear()

size = 11

# Create a tensor filled with all 2s
input_tensor = torch.full((size,), 1.0)

# # Forward pass
output_tensor = model(input_tensor)

# # Print input tensor and output
print("Input Tensor:")
print(input_tensor)
print("\nOutput Tensor:")
print(output_tensor)



###########################################################################################################################################################
#Compares all 3 vectors to each other.

# Convert output tensor to a scalar value
vectorA = output_tensor.item()

# vectorB = vectorA

# Calculate the acceptable range as 10% of vectorA
acceptable_range = vectorA * 0.1


# Check if the absolute difference between vectorA and vectorC
# is within the acceptable range
within_tolerance = abs(vectorA - vectorC) <= acceptable_range

if(within_tolerance != True):
    print("Bug in OpenHLS")
elif(vectorA != vectorB):
    print("Bug in ScaleHLS")

# Check if all three values are within_margin
if ((vectorA == vectorB) & within_tolerance):
    print("Passed Verification Test.")
else:
    print("Did Not Pass Verification Test.")    
#############################################################################################################################################################


