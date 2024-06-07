#!/bin/bash

git_script()
{
	git add .
	git commit -m "script"
	git push
	git clone git@github.com:julienmoulines/CPP.git CPP_TEST
}
git_script