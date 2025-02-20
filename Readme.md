# SealID
SealID is a software to craeting a token.
The **token** is compose with key and an id.

You can use the token key to generate a new ids. The id is derived from key. As such it work with digital signature.

**However the id is not a cryptograph signature.**

## Arguments:

**KeyFilename**: Create a new ID with key.

**--save filename**: Save the output in a file with filename.

**--check KeyFileName IDFileName**: Check if the Key in *KeyFileName* generate de Id in *IDFileName*.

**--showtag filename**: Print the tag od the id in *filename*

## Exemple:

```
./run.sh key
```
Create and print a new ID.

```
./run.sh key --save newID
```
Create and save a ID in file with name = "newID".

```
./run.sh key THK
```
Create a new ID with THK tag.

```
./run.sh key THK --save newID
```
Create a new ID with THK tag and save ID in file with name = "newID".

```
./run --showid newID
```
Print the ID that in the file with name = "newID".

```
./run --showtag newID
```
Print the ID tag that in the file with name = "newID".

```
./run --check key newID
```
Check if the key generate that ID.