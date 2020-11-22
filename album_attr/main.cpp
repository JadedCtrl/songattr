#include <iostream>
#include <InterfaceDefs.h>
#include <Message.h>
#include <MimeType.h>

// add the given attribute to a BMessage for use as attr info
// borrowed from mailserver, thanks!
static void addAttribute
( BMessage& msg, const char* name, const char* publicName, int32 type, int32 width )
{
	msg.AddString( "attr:name", name );
	msg.AddString( "attr:public_name", publicName );
	msg.AddInt32( "attr:type", type );
	msg.AddInt32( "attr:width", width );
	msg.AddInt32( "attr:alignment", B_ALIGN_LEFT );
	msg.AddBool( "attr:extra", false );
	msg.AddBool( "attr:viewable", true );
	msg.AddBool( "attr:editable", true );
}

// install the x-album filetype for folders containing music
int main ( int argc, char** argv )
{
	BMessage info;
	BMimeType mime( "audio/x-album" );
	if ( mime.IsInstalled() )	return 2;

	std::cout << "DAD";
	mime.GetAttrInfo( &info );

	mime.SetShortDescription( "Album" );
	mime.SetLongDescription( "Generic audio container" );

	addAttribute( info, "Audio:Artist", "",     B_STRING_TYPE, 200 );
	addAttribute( info, "Album:Title",  "",     B_STRING_TYPE, 200 );
	addAttribute( info, "Media:Year",   "Year", B_INT32_TYPE,  200 );

	mime.SetAttrInfo( &info );

	return 0;
}
