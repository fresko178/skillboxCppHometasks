search_engine
==============
Thank you for choosing.

Description
------------
_This_ _software_ _can_ _serve_ _as_ _a_ _search_ _system_ _on_ _the_ _company's_ _corporate_ _portal_

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

