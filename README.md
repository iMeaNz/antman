
# antman
The goal of this project is to compress data. You will write two programs.  
The first one will take a file as input and compress it.  
The second one will take a compressed file as input and translate it back to its original state.  

## antman (compression algorithm)
Your antman binary is the one that will compress files. It will take two parameters. The first one is the path
to the file we want compressed. The second one is a number corresponding to the type of file it is (see
‘Lossless Compression’).  
Your program will then print a compressed version of the file on the standard output. It should be possible
to redirect the compressed data to a file.  

## giantman (decompression algorithm)
Your giantman binary is the one that will recover files from their compressed format.  
It will take two parameters. The first one is the path of a file containing compressed data.   
The second one is a number corresponding to the type of file it originaly was.  
Your program will then print the readable file the compressed data was based of on the standard output.

## Requirements
### Must
• The antman binary must write a compressed version of the file it got as a parameter on the standard
output.  
• The giantman binary must write the original version of the compressed file it got as a parameter on
the standard output.  
• The original file printed by giantman must be the exact same as the one that antman got as parameter.  
• The programs must work with files containing any value.  
• The programs must compress files sometimes.  
• The programs mustn’t take an unreasonable time to run, even on large files.  
• The programs must work with files that you only have permission to read from.  
### Should
• The compressed file shouldn’t be bigger than the original file.  
• The programs should take into account the given filetype.  
• The programs should compress files everytime.  
### Could
• You could define new and/or more precise filetypes and use them.  
• You could push a quantified analysis of your different compression algorithms as a bonus.  
• You could propose new challenges for your peers and organise a competition.  
• The programs could gather informations from the file itself (extension, size) and use them as indicators.
____
![example1](https://github.com/iMeaNz/mantman/blob/main/example.png?raw=true)
