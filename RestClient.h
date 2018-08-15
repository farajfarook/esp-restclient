#ifndef RestClient_h
#define RestClient_h

#include <Arduino.h>
#include <WiFiClientSecure.h>

class RestClient
{
  public:
    RestClient(String host)
    {
        RestClient(host, 80);
    }

    RestClient(String host, int port)
    {
        RestClient(host, port, "http");
    }

    RestClient(String host, int port, String protocol)
    {
        RestClient(host, port, protocol, "");
    }

    RestClient(String host, int port, String protocol, String basePath);

    int request(String method, String path, const char *body, String *response);

    void setHeader(String header);
    
    void setContentType(String contentType);
    
    void setProtocol(String protocol);
    
    int get(String path)
    {
        return request("GET", path, NULL, NULL);
    }
    
    int get(String path, String *response)
    {
        return request("GET", path, NULL, response);
    }
    
    int post(String path, String body)
    {
        return request("POST", path, body.c_str(), NULL);
    }
    
    int post(String path, String body, String *response)
    {
        return request("POST", path, body.c_str(), response);
    }
    
    int patch(String path, String body)
    {
        return request("PATCH", path, body.c_str(), NULL);
    }
    
    int patch(String path, String body, String *response)
    {
        return request("PATCH", path, body.c_str(), response);
    }
    
    int put(String path, String body)
    {
        return request("PUT", path, body.c_str(), NULL);
    }
    
    int put(String path, String body, String *response)
    {
        return request("PUT", path, body.c_str(), response);
    }

    int del(String path)
    {
        return request("DELETE", path, NULL, NULL);
    }

    int del(String path, String *response)
    {
        return request("DELETE", path, NULL, response);
    }
    
    int del(String path, String body)
    {
        return request("DELETE", path, body.c_str(), NULL);
    }

    int del(String path, String body, String *response)
    {
        return request("DELETE", path, body.c_str(), response);
    }

  private:
    WiFiClient *client;    
    int _readResponse(String *response);    
    String host;
    int port;
    int num_headers;
    String headers[10];
    String contentType;
    int ssl;
    String basePath;
};

#endif
