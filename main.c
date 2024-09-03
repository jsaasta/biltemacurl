#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define EXIT_NO_ARGS            1
#define ERR_CURL_EASY_PERFORM   -1

int main(int argc, char * argv[])
{
    if(argc != 2) {
        printf("Usage: %s [url]\n", argv[0]);
        return EXIT_NO_ARGS;
    }

    const char *arg_url = NULL;
    CURL *curl = curl_easy_init();
    CURLcode result;
    char url[2048];
    char query[2048];
    arg_url = argv[1];

    char *escaped_query = curl_easy_escape(curl, arg_url, 0);
    sprintf(query, "https://find.biltema.com/v4/web/typeahead/100/sv/?query=%s&from=0&take=20&IsPreferInStockAndNotPhasedOut=True&sortBy=recommended&sortDir=asc&Categories=", escaped_query);
    sprintf(url, "https://%s", arg_url);

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, query);
        result = curl_easy_perform(curl);
        if(result != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
            return ERR_CURL_EASY_PERFORM;
        }
        curl_easy_cleanup(curl);

    }

    return 0;


}
