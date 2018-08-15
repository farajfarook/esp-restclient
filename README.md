# esp-restclient
ESP8266 REST Client

Supporting Protocols

- HTTP
- HTTPS

Supporting Methods

- GET
- POST
- PUT
- PATCH
- DELETE

This client uses BearSSL Secure wifi client for the HTTPS connections.


## Usage HTTP

```
#include <RestClient.h>
...
void setup()
{
  // Connect to WIFI
  ...
  
  // Create a REST Client for http://reqres.in/api/
  RestClient client("reqres.in", 80, "http", "/api/");
}

void loop()
{
  String response;
  rest.get("users/2", &response);
  Serial.println(response);
  delay(1000);
}
```

## Usage HTTPS - with all new BearSSL Secure client

```
#include <RestClient.h>
...
void setup()
{
  // Connect to WIFI
  ...
  
  // Create a REST Client for https://reqres.in/api/
  RestClient client("reqres.in", 443, "https", "/api/");
}

void loop()
{
  String response;
  rest.get("users/2", &response);
  Serial.println(response);
  delay(1000);
}
```
