#include <curl/curl.h>

int main() {
  CURL *curl;
  CURLcode res;
  char *response_string;

  // Initialize curl
  curl = curl_easy_init();
  if (curl) {
    // Set the URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");

    // Get the response
    res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      // Get the response string
      response_string = curl_easy_getinfo(curl, CURLINFO_RESPONSE_STRING);

      // Print the response string
      printf("%s\n", response_string);
    }

    // Free the response string
    curl_free(response_string);

    // Close the curl handle
    curl_easy_cleanup(curl);
  }

  return 0;
}
