# Makefile for Sphinx documentation

# You can set these variables from the command line.
SPHINXOPTS    ?=
SPHINXBUILD   ?= python -m sphinx
PAPER         ?=
BUILDDIR      ?= _build

# Internal variables.
PAPEROPT_a4     = -D latex_paper_size=a4
PAPEROPT_letter = -D latex_paper_size=letter
ALLSPHINXOPTS   = -d $(BUILDDIR)/doctrees $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) .
# the i18n builder cannot share the environment and doctrees with the builders
I18NSPHINXOPTS  = $(PAPEROPT_$(PAPER)) $(SPHINXOPTS) .

.PHONY: help build clean html doxygen

help:
	@echo "Sphinx and Breathe documentation build helper"
	@echo "Use \`make <target>' where <target> is one of:"
	@echo "  html       to make standalone HTML files"
	@echo "  doxygen    to run Doxygen to generate XML"
	@echo "  clean      to remove build artifacts"
	@echo "  cleanall   to remove all generated files including Doxygen output"

html: doxygen
	$(SPHINXBUILD) -b html $(ALLSPHINXOPTS) $(BUILDDIR)/html
	@echo
	@echo "Build finished. The HTML pages are in $(BUILDDIR)/html."

doxygen:
	@echo "Running Doxygen..."
	mkdir -p doxygen
	cd .. && doxygen Doxyfile && cd docs

clean:
	rm -rf $(BUILDDIR)/*

cleanall: clean
	rm -rf doxygen
