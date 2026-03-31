# Configuration file for the Sphinx documentation builder.

import os
import sys

# Add the source directory to sys.path
sys.path.insert(0, os.path.abspath('.'))

# Project information
project = 'C++ Design Patterns and Basics'
copyright = '2026, Development Team'
author = 'Sandeep'
release = '1.0'
version = '1.0.0'

# General configuration
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.viewcode',
    'sphinx.ext.todo',
    'breathe',
]

# Breathe configuration
breathe_projects = {
    'CppDesignPatterns': './doxygen/xml'
}
breathe_default_project = 'CppDesignPatterns'
breathe_domain_by_extension = {
    'hpp': 'cpp',
    'cpp': 'cpp',
    'h': 'cpp',
}

# Source file suffixes
source_suffix = {
    '.rst': 'restructuredtext'
}

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that should be ignored
exclude_patterns = ['_build']

# The theme to use for HTML and HTML Help pages.
html_theme = 'sphinx_rtd_theme'

# Theme options
html_theme_options = {
    'logo_only': False,
    'display_version': True,
    'prev_next_buttons_location': 'bottom',
    'style_external_links': False,
    'vcs_pageview_mode': '',
    'style_nav_header_background': '#2980B9',
}

# Add any paths that contain custom static files
html_static_path = ['_static']

# HTML output options
html_logo = None
html_title = f'{project} {version}'
html_use_smartypants = True

# smartquotes are disabled for now
smartquotes_action = 'qe'

# The name of the Pygments (syntax highlighting) style to use.
pygments_style = 'sphinx'

# If true, `todo` and `todoList` produce output, else they produce nothing.
todo_include_todos = True

# Additional configuration
master_doc = 'index'
