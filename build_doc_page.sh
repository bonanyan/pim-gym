#!/bin/bash
if [ -e docs ]
then 
    rm -rf docs
fi

cd sphinx_doc
make clean
make html
mv build/html ../docs
cd ..
touch docs/.nojekyll
open docs/index.html
