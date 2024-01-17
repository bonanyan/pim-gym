cd sphinx_doc
make clean
make html
cp -r build/html/* ../docs/
cd ..
open docs/index.html
