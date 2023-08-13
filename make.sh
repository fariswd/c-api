#!/usr/bin/env bash

mkdir download
curl https://ftp.gnu.org/gnu/libmicrohttpd/libmicrohttpd-latest.tar.gz --output download/libmicrohttpd.tar.gz

mkdir lib
tar -xf download/libmicrohttpd.tar.gz -C lib

for folder in "lib"/*; do
  if [ -d "$folder" ]; then
    old_folder_name=$(basename "$folder")

    # Remove dashes from the end of the folder name
    new_folder_name=${old_folder_name%%-*}

    echo $new_folder_name

    # Rename the folder
    mv "lib/$old_folder_name" "lib/$new_folder_name"

    cd lib/$new_folder_name
    ./configure
    make
    cd ../..
  fi
done

exit 0;