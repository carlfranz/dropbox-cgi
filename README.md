# GTD Renamer

This is a project about the _Get Thing Done_ book I've read. The book suggests to place all the notes and all the stuff you need to process in one place. I choose to place on dropbox to have access and sync on all devices. The problem with the smartphone's dropbox application is that every text file you edit and put in the folder have the same name "miofile.txt" in italian. Also, if the file already exists, it does not suggest alternate filename like ("miofile_1.txt" or "miofile.txt (1)").  It is possible to rename the file to something different while saving, but I think fast notes should avoid this. To overcome this problem I've created a binary cgi that rename that particular file to a random string value. It works with the dropbox API and the webhook capability from the developer console [https://www.dropbox.com/developers/apps](https://www.dropbox.com/developers/apps). 

For the hackers, the auth code in the repo is invalid, trying it is a waste of time.

## Build
This project uses CGI, install on a webserver which allows cpp cgi.

    sudo apt install libcurl4-openssl-dev libcurlpp-dev  libjsoncpp-dev

    copy cgi in /usr/lib/cgi-bin
    
    
## Links
- https://en.wikibooks.org/wiki/JsonCpp
