# SealID
SealID is a software to craeting a token.
The **token** is compose with key and an id.

You can use the token key to generate a new ids. The id is derived from key. As such it work with digital signature.

**However the id is not a cryptograph signature.**

## Arguments:
**--save filename**: Save the output in a file with filename.

**--check KeyFileName IDFileName**: Check if the Key in *KeyFileName* generate de Id in *IDFileName*.