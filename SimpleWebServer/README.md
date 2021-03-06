# GROUP PROJECT - Simple Web server

Author: Xin Chen, Mantai Lin

* Xin Chen is responsible to provide/write testable html pages, shell script and Makefile, build a basic framework of webserver, also process the multi-threads.
* Mantai Lin is responsbile to interpret the http request with static/dynamic content, implement CGI, also handle invalid http requests.

## Basic features

1. handle http request (GET)
2. interpret http request
3. send the http response to server
4. able to display content, including plain text, photos on browser
5. provide the ability to handle single thread, single process, and one connection per thread.

## The advanced features of this webserver

1. interpret simple web pages, including some html or css elements
2. Implement CGI
3. process multi-threads.

## Usage

```shell
git clone https://zetecx@bitbucket.org/zetecx/cis330-project.git
cd CIS330-Project/WebServer
make main
make run
```

Then, open browser and enter "localhost:5000"

## Note

* The default port is 5000 but user could run the project by 

```shell
./main 8000(port number)
```

* We provide links for all testable html pages within index.html but they can be accessed by "localhost:xxxx/{file path}" manually, e.g. localhost:5000/test/test1.png or localhost:5000/test/trivia.html.
* We can handle some 404/403 errors, such as invalid url, or urls which have wrong formats.
