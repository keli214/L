import torch
import torch.nn as nn

class StreamingConv(nn.Module):
  def __init__(self):
    super().__init__()
    self.time_step = 0
    self.curr_input = None 
    
  def from_pretrained(self, layer: nn.Conv1d):
    # take a pretrained layer and load the weights
    # bias is set to false
    self.weight = layer.weight
    self.kernel_size = layer.kernel_size[0]
    self.out_channels = layer.out_channels
    self.in_channels = layer.in_channels

  def forward(self, input_element: torch.Tensor):
    # input_element is shaped (batch_size, in_channels)
    # should return None if cannot produce a valid output yet
    batch_size = input_element.shape[0]
    # increment the time step
    self.time_step += 1
    # construct the curr_input
    if self.curr_input is None:
      self.curr_input = input_element.unsqueeze(2)
    else:
      self.curr_input = torch.cat((self.curr_input, input_element.unsqueeze(2)), dim=2)
      if self.time_step > self.kernel_size: 
        self.curr_input = self.curr_input[:, :, 1:] 
    if self.time_step >= self.kernel_size:
      # perform correlation [o, i, k] * [b, i, k] -> [b, o]
      output = torch.zeros((batch_size,self.out_channels))
      for b in range(batch_size):
        for k in range(self.out_channels):
          for c in range(self.in_channels):
            output[b][k] += torch.dot(self.curr_input[b][c], self.weight[k][c])
      return output
    return None