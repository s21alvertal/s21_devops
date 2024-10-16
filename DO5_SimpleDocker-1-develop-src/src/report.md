# S21_SimpleDocker

## Part1. Ready-made docker

* Возьмемо официальный docker-образ с nginx и выкачаем его при помощи команды `docker pull`

* Далее удостоверимся в наличии образа через команду `docker images`

* Наконец, запустим docker-образ через команду `docker run -d

![image](https://api.weeek.net/ws/656995/files/9d0d68af-9e1d-42d6-b4f9-102a9b16f7fc)

* Удостоверимся, что контейнер успешно запустился через команду `docker ps`

![image](https://api.weeek.net/ws/656995/files/9d0d68cb-5333-4b33-b1bf-21a5b5de6ffd)

* Теперь посмотрим информацию о контейнере через команду `docker inspect [container_id|container_name]`

![image](https://api.weeek.net/ws/656995/files/9d0d68e5-07ee-4b63-8bb3-e544f4e0530f)

* Выведем размер контейнера

![image](https://api.weeek.net/ws/656995/files/9d0d69e2-74da-4008-b8e9-43b32176cfd6)

* А теперь - список замапленных портов

![image](https://api.weeek.net/ws/656995/files/9d0d6a5c-62f1-4ff1-9ffc-d660c28758e3)

* И, наконец, IP контейнера

![image](https://api.weeek.net/ws/656995/files/9d0d74b8-c79d-4184-8a4b-ac1f05b30175)

* Остановим docker-образ командой `docker stop [container_id|container_name]` и проверим, что образ успешно остановился через уже знакомую команду `docker ps`

![image](https://api.weeek.net/ws/656995/files/9d0d7504-99a0-401f-a956-aff2e94e78d0)

* Теперь запустим docker-образ с портами 80:80 и 443:443 чере команду `docker run`

![image](https://api.weeek.net/ws/656995/files/9d0d75ac-252b-4744-b4a3-2cb8ccb73c9d)

* Удостоверимся, что все работает, открыв в браузере страницу по адресу `localhost`

![image](https://api.weeek.net/ws/656995/files/9d0d757f-0855-49b5-9d1e-c392516fc35a)

* Наконец, перезапустим контейнер через команду `docker restart [container_id|container_name]` и проверим, что контейнер снова запустился командой `docker ps`

![image](https://api.weeek.net/ws/656995/files/9d0d75f7-a53c-494d-8ac6-8f793468884f)

# Part2. Operations with container

* Для начала прочтем конфигурационный файл `nginx.conf` внутри docker-контейнера через команду `docker exec`

![image](https://api.weeek.net/ws/656995/files/9d0d76df-de71-47ac-bf01-94f61e133a4c)

* Теперь создадим локальный файл `nginx.conf` при помощи команды `touch nginx.conf` и настроем в нем выдачу страницы-статуса сервера по пути `/status`

![image](https://api.weeek.net/ws/656995/files/9d0d798b-a541-4a7d-a0d7-07baa8a9bbce)

* Наконец, перенесем созданный файл внутрь docker-образа командой `docker cp`

* И перезапустим nginx внутри docker-образа командой `docker exec [container_id|container_name] nginx -s reload`

![image](https://api.weeek.net/ws/656995/files/9d0d7c94-c011-4224-b090-d498fd4656a9)

* Убедимся, что все работает, проверив страницу по адресу `localhost/status`

![image](https://api.weeek.net/ws/656995/files/9d0d7c1b-d74d-4968-9251-8fca17329c85)

* Теперь экспортируем наш контейнер в файл `container.tar` командой `docker export`

* Затем удалим образ командой `docker rmi -f [image_id|repository]`, не удаляя перед этим контейнеры

![image](https://api.weeek.net/ws/656995/files/9d0d7d08-cde8-4122-84e7-a1d9e70aed5c)

* После чего удалим остановленный контейнер командой `docker rm [container_id|container_name]`

![image](https://api.weeek.net/ws/656995/files/9d0d7d66-6c95-4f77-9c3c-f6dd43fbe294)

* Теперь импортируем контейнер обратно командой `docker import` и запустим импортированный контейнер уже знакомой командой `dicker run`

![image](https://api.weeek.net/ws/656995/files/9d0d8395-81fd-4750-8db6-651052771da0)

* Наконец проверим, что по адресу `localhost/status` выдается страничка со статусом сервера nginx

![image](https://api.weeek.net/ws/656995/files/9d0d8379-d109-4fd8-8a82-3fe70cdebe41)

## Part3. Mini web server

* Чтобы создать свой мини веб-сервер, необходимо создать .c файл, в котором будет описана логика сервера (в нашем случае - вывод сообщения `Hello World!`), а также конфиг `nginx.conf`, который будет проксировать все запросы с порта 81 на порт 127.0.0.1:8080

![image](https://api.weeek.net/ws/656995/files/9d0d87d7-5e8f-4926-ac54-0f8b61b8d284)

![image](https://api.weeek.net/ws/656995/files/9d0d87c7-45bf-4d88-a2bf-916b3ad7bc8e)

* Теперь выкачаем новый docker-образ и на его основе запустим новый контейнер

![image](https://api.weeek.net/ws/656995/files/9d0d87f3-fff9-4522-8a62-9eac69bea00e)

* После перекинем конфиг и логику сервера в новый контейнер

![image](https://api.weeek.net/ws/656995/files/9d0d88c9-82d5-4954-b928-aa1347bb7d26)

* Затем установим требуемые утилиты для запуска мини веб-сервера на FastCGI, в частности `spawn-fcgi` и `libfcgi-dev`

* Наконец скомпилируем и запустим наш мини веб-сервер через команду `spawn-fcgi` на порту 8080

![image](https://api.weeek.net/ws/656995/files/9d1761bd-7b0d-4caa-b9e1-137704cc1eeb)

* Чтобы удостовериться, что все работает корректно, проверим, что в браузере по адресу `localhost:81` отдается написанная нами страница

![image](https://api.weeek.net/ws/656995/files/9d1761cf-a121-45e9-88f8-cf212363144d)

## Part4. Your own docker

* Напишем свой docker-образ, который собирает исходники 3-й части, запускает на порту `80`, после копирует внутрь написанный нами `nginx.conf` и, наконец, запускает `nginx` (ниже приведены файлы `run.sh` и `Dockerfile`, файлы `nginx.conf` и `server.c` остаются с 3-й части)

![image](https://api.weeek.net/ws/656995/files/9d17669b-7771-4133-8fe8-24d27ff59be9)

![image](https://api.weeek.net/ws/656995/files/9d1766a6-71e9-4934-813a-e6370c24a31a)

* Соберем написанный docker-образ через команду `docker build`, при этом указав имя и тэг нашего контейнера

![image](https://api.weeek.net/ws/656995/files/9d17671e-0728-4f2e-beb6-c643a2dc20cc)

* Теперь удостоверимся, что все собралось, проверив наличие соответствующего образа командой `docker images`

![image](https://api.weeek.net/ws/656995/files/9d176739-1361-4b4d-bdbc-b8b15cb07ca6)

* После запустим собранный docker-образ с мапингом порта `81` на порт `80` локальной машины, а также мапингом папки `./nginx` внутрь контейнера по адресу конфигурационных файлов nginx'а, и проверим, что страничка написанного сервера по адресу

![image](https://api.weeek.net/ws/656995/files/9d176d38-bf36-402c-aea4-e1ec982c4963)

![image](https://api.weeek.net/ws/656995/files/9d176d7e-67fd-4e87-8191-6099609c494a)

* Теперь добавим в файл `nginx.conf` проксирование странички `/status`, по которой необходимо отдавать статус сервера `nginx

* Теперь перезапустим `nginx` в своем docker-образе командой `nginx -s reload`

* Наконец, проверим, что по адресу `localhost/status` выдается страничка со статусом сервера `nginx`

![image](https://api.weeek.net/ws/656995/files/9d1771f3-e71d-460a-9be5-810dcdaaf953)

## Part5. Dockle

* Просканируем docker-образ из предыдущего задания на предмет наличия ошибок командой `dockle [image_id|repository]`

![image](https://api.weeek.net/ws/656995/files/9d1772d9-bb56-4a39-a56f-726d6e8f8f98)

* Далее исправим конфигурационные файлы docker-образа так, чтобы при проверке через утилиту `dockle` не возникало ошибок и предупреждений (для Part5 я создал отдельный контейнер с тэгом `part5`, куда подгрузил измененные конфиги)

![image](https://api.weeek.net/ws/656995/files/9d1777db-8b4d-4c43-b504-ca7b5454c5f0)

![image](https://api.weeek.net/ws/656995/files/9d1777a2-3413-4a74-84c0-ff88bba0c561)

## Part6. Basic Docker Compose

* Для начала остановим все запущенные контейнеры командой `docker stop`

![image](https://api.weeek.net/ws/656995/files/9d17788f-5cef-403b-a821-da0afed3521a)

* Затем изменим конфигурационные файлы (их можно найти в папке `src/part6_compose`)

* Теперь сбилдим контейнер командой `docker-compose build`

![image](https://api.weeek.net/ws/656995/files/9d17e264-990a-4f98-87e3-94146152de73)

* После необходимо поднять сбилженный контейнер командой `docker compose up`

![image](https://api.weeek.net/ws/656995/files/9d17e27e-db7a-4b3e-bcb1-0b27ca5beb7b)

* В завершение насладимся плодами своей усердной работы, удостоверившись, что по адресу `localhost` отдается страничка с надписью `Hello World!`

![image](https://api.weeek.net/ws/656995/files/9d17e2b1-5731-4a2e-b106-f987ac5cd9d5)
