# C-API

Capi capi deh

## Run?

```
./make.sh && ./build.sh && ./run.sh

curl http://localhost:8080/hello

response:
{"message": "hi from get hello"}
```

## Docker?

```
docker build . -t fariswd/capi
docker run --name capi -p 8080:8080 -d fariswd/capi
docker exec -it capi bash /app/run.sh
```

## Route

```
GET /hello
* NotFound
```

fariswd  
2023  
😭
