import torch
import torch.nn as nn




weight = 1.0

bug = 0.0

class Linear(nn.Module):
    def __init__(self, imgsz, bias=True):
        super().__init__()
        self.linear1 = torch.nn.Linear(imgsz, imgsz, bias=bias)
        # Initialize weights to 1.0 and biases to 0.0
        if(bug != 1.0):
            self.linear1.weight.data.fill_(weight)
        else:
            self.linear1.weight.data.fill_(0.5)
        if bias and bug != 2.0:
            self.linear1.bias.data.fill_(0.0)
        else:
            self.linear1.bias.data.fill_(2.0)

    def forward(self, x):
        return self.linear1(x).sum()
    
# Define and compile the model
def linear():
    return Linear(imgsz=11)  # Example size 11, you can change as needed

def valuew():
    return weight

# module = torch_mlir.compile(linear(), torch.ones(
#      1, 11), output_type=torch_mlir.OutputType.LINALG_ON_TENSORS)

# print(module)