search_engine
==============
Thank you for choosing.

### What is this for
_This_ _software_ _can_ _serve_ _as_ _a_ _search_ _engine_ _on_ _a_ _company's_ _corporate_ _portal_. _The_ _solutions_ _applied_ _in_ _it_ _can_ _be_ _built_ _into_ _a_ _search_ _engine_ _running_ _on_ _the_ _web_.
### What should do
_The_ _search_ _engine_ _must_ _go_ _through_ _all_ _the_ _files_ _and_ _index_ _them_ _so_ _that_ _it_ _can_ _then_ _find_ _the_ _most_ _relevant_ _documents_ _for_ _any_ _search_ _query_, _the_ _relevance_ _of_ _which_ _is_ _also_ _calculated_. _Files_ _are_ _crawled_ _at_ _the_ _frequency_ _specified_ _in_ _the_ _configuration_ _file_.
### How to use
_The_ _application_ _configuration_ _file_ _specifies_ _the_ _names_ _files_ _for_ _which_ _the_ _engine_ _will_ _search_. _The_ _user_ _sets_ _the_ _request_ _through_ _the_ _requests.json_ _JSON_ _file_, _which_ _is_ _a_ _set_ _of_ _words_ _by_ _which_ _to_ _find_ _documents_. _Search_ _results_ _are_ _ranked_, _are_ _sorted_ _and_ _at_ _the_ _end_ _the_ _program_ _generates_ _the_ _answers.json_ _file_, _in_ _which_ _it_ _writes_ _the_ _search_ _results_.


## Tools

**bin/config.json** - сonfiguration file

     field config --> max_responses     the maximum number of responses to one request
     field config --> timer_sec         the frequency with which it is necessary to re-index the database, re-upload files and calculate their search engine rating
     field config --> files             contains the paths to the files to be searched

**bin/requests.json** - contains requests that need to be processed by the search engine

**answers.json** - contains the results of the search engine

**resources/** - contains files for analysis

Recommendation
---------------
- OS Linux 4.19.0-20-amd64 x86_64
- cmake 3.18.4
- gcc 10.2.1
---
Compiling
----------
- cmake CMakeLists.txt
- make

