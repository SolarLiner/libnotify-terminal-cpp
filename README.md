# libnotify-terminal-cpp
CLI that sends notifications with buttons and callbacks.  
[![Twitter](https://img.shields.io/twitter/url/https/github.com/SolarLiner/libnotify-terminal-cpp.svg?style=social)](https://twitter.com/intent/tweet?text=Wow:&url=https%3A%2F%2Fgithub.com%2FSolarLiner%2Flibnotify-terminal-cpp)
[![GitHub license](https://img.shields.io/github/license/SolarLiner/libnotify-terminal-cpp.svg)](https://github.com/SolarLiner/libnotify-terminal-cpp/blob/master/LICENSE)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/882bc5e87e074b2e836e522f710e9886)](https://www.codacy.com/app/solarliner/libnotify-terminal-cpp?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=SolarLiner/libnotify-terminal-cpp&amp;utm_campaign=Badge_Grade)
[![Build Status](https://travis-ci.org/SolarLiner/libnotify-terminal-cpp.svg?branch=feature%2Ftravis)](https://travis-ci.org/SolarLiner/libnotify-terminal-cpp) 

## Usage
Warning: Usage is not engraved in stone yet. Expect changes, especially in the beginning.
`libnotify-terminal BODY {options}`  
Note: Only the body is required.

```
Options:
    --title, -t     Adds a title to the notification
    --timeout       Sets the timeout in ms, if supported (default: 5000)
    --appname       Sets the host application
    --icon          Sets icon as freedesktop name
```
