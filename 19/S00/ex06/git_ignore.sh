#!/bin/bash
git status --ignored -s | sed 's/ M //g' | sed 's/?? //g'
#cat .gitignore
