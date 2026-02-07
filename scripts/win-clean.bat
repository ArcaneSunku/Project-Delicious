@echo off
title=Window Cleanscript
echo Cleaning build output...

if exist bin (
    rmdir /S /Q bin
)

if exist bin-int (
    rmdir /S /Q bin-int
)

echo Clean complete.