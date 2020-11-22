================================================================================
SONGATTR
================================================================================
songattr.sh uses FFMPEG to fill the Audio:* & Media:* attributes for audio
files. It will populate Audio:Artist, Audio:Album, Audio:Track, Media:Title,
and Media:Year, as possible. Additionally, if lyrics are embedded in the file,
it will set the non-standard Audio:Lyrics attribute.

In addition, it can set the Album:Artist and Media:Year attributes for the
parent directory (assumed to be the Album folder), using a custom audio/x-album
filetype. You can add the Album type to your system by building and running
album_attr/ once.

========================================
USAGE
========================================
usage: songattr [-ha] file
-h	print more detailed help info
-a	treat the parent directory as an Album file

Since songattr can only take one file at a time, you'll probably end up using
it like this:
	$ for file in ./*.mp3; do songattr "$file"; done

========================================
BORING STUFF
========================================
MIT License
Jaidyn Ann, jadedctrl@teknik.io
