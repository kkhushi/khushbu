#!/usr/lib/env python
import os
import urllib2
import flickr
u = raw_input("Enter user_id:\t")
s = raw_input("Enter set to download:\t")
d = "/home/khushbu/Pictures/"+s
os.mkdir(d)
user = flickr.User(u)
set = user.getPhotosets()

for photoset in set:
  if photoset.title == s:
    set = photoset

photos = set.getPhotos()

for photo in photos:
  url = photo.getURL(size ='Large')
  link = urllib2.urlopen(url)
  data = link.read()
  x = data.find('<p><img src="')
  a = data[x+13 :x +76 ]
  opener1 = urllib2.build_opener()
  page1 = opener1.open(a)
  my_picture = page1.read()
  filename = d + "/" +photo.title + ".jpg" 
  fout = open(filename, "wb")
  fout.write(my_picture)
  fout.close()
  

 
  
