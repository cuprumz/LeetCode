#!/bin/bash


url="https://leetcode.com/problems/"
if [ $# == 0 ] || [ $# == 1 ]
then
  echo "usage: ./setup.sh id name"
else
  num=$#
  id=$1
  underscope=$2
  dash=$2
  space=$2
  int=0
  for w in $*
  do
    if [ ${int} == 0 ] || [ ${int} == 1 ]
    then
      let "int++"
      continue
    fi
    underscope="${underscope}_${w}"
    dash="${dash}-${w}"
    space="${space} ${w}"
  done
  mkdir "src/${underscope}"
  echo "### ${space}" > "src/${underscope}/README.md"
  echo "| ${id} | [${underscope}](${url}${dash}/) | xx | [Rust](./src/${underscope}/solution.rs) | [dir](./src/${underscope}/) |" >> README.md
fi
