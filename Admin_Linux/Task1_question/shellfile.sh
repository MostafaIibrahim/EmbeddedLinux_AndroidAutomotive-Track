#!/bin/bash

cd ~
mkdir myDirectory
cd myDirectory
mkdir secondDirectory
cd secondDirectory
touch myNotePaper
cp ~/myDirectory/secondDirectory/myNotePaper ~/myDirectory/myNotePaper
mv myNotePaper myOldNotePaper
