/*
Download and install curl library

After the library is installed use this
to find where the library is located
$curl-config --libs

response:
-L/data/data/com.termux/files/usr/lib -lcurl

And this to find the include files:
$curl-config --cflags

response:
-I/data/data/com.termux/files/usr/include

Using this at the command line with library properly installed:
This works:

gcc homesun.c -I/data/data/com.termux/files/usr/include -L/data/data/com.termux/files/usr/lib -lcurl -o sunhome


API to get sun rise/set and other sun related data.
https://api.sunrisesunset.io/json?lat=41.87092932&lng=-71.42788283

Home:
Latitude: 41°52'15"
(41.87092932)
Longitude: -71°-25'-40"
(-71.42788283)

Make a sunrise/sunset file
Make a sun locator file
Simple code:

 * <DESC>
 * Very simple HTTP GET
 * </DESC>
 */
#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.sunrisesunset.io/json?lat=41.87092932&lng=-71.42788283");
    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

