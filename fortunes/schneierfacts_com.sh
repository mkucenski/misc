#!/bin/sh

for X in $(seq 1 53); do
	curl "https://www.schneierfacts.com/facts/search?page=${X}&q=.&s=Search&utf8=✓" | grep '<li><a href="/facts/'
done
