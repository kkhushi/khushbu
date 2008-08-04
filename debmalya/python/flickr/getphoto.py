#! /usr/bin/env python

import flickr
import urllib2
import os

a=os.getcwd();
print "current working directory is : " + a;	#making sure, where am I now !
id=raw_input("\nNow input your flickr id : ");  #Enter your numeric flickr id. Trying to fine tune the code here :(

pset_tag={};	#Building a Dictionary.

count = 1;


user=flickr.User(id);	#this functionreturns the actual flickr id.
uname=user.realname;	#quite simple... :P
#print "User's Real Name is : " + uname;
setlist=user.getPhotosets();	#this function gets all the photosets id user have
#print setlist;
print "\nUser " + uname + " has got following Photosets :\n"
for i in setlist :
	asd=i.title; 	# Retrieving the humane names of those sets :D
	print "\nphotoset id > %d >  " %count + asd + " set has photoes";
	questn=raw_input("Do you want to see which photoes? y/n :");	
	if questn == 'y' :	#this will show which fotoes the set has got.
		uuname = i.getPhotos();	
		for i2 in uuname :
			photo1 = i2.title;
			print photo1;

	pset_tag[count]=i; #setting up dictionary by name : flickr set id
	count= count + 1;

pset_choice=int(raw_input("\n Enter Photo Set id of your choice ( 0 to exit) :"));
if (pset_choice != 0 and pset_choice < count):

	set=pset_tag[pset_choice];
	print "Downloading All Photoes from set : " + set.title;

	direc=set.title; #now building the folder as setname at current directory
	os.mkdir(direc);

	plist=set.getPhotos();

	for per_foto in plist :

		purl=per_foto.getURL(size='Large', urlType='source') #here, urlType attribute could be 'url' but in that
	#							     #case, we'd get the whole messy html code.. :P
	#							     #this attrib helps to get the precise  foto url.
	#
		fotoname = per_foto.title + ".jpg";	
		print "\nDownloading photo " + fotoname;
		#print "From URL " + purl;	
		handler = urllib2.build_opener()  # Setting the build handler. spent 30 mins to get this concept :P
		b=handler.open(purl);	# earlier, i was fumbling to open. then i searched Python Library reference :)
		c=b.read();#
		
		path=a + "/" + direc + "/" + fotoname;
		input= file(path,"w");  #writing data into a file.
		input.write(c);
		input.close(); #cleaning upp...
		print "Complete..."
elif (pset_choice >= count):
	print "sorry... invalid photo id . Try again...";

print " \n\nThanks for using this. \nAuthor : ecntrk.k0mputer.g33k@gmail.com \nCourtesy : Flickr.com , Flickr API and Yahoo \n\n";
