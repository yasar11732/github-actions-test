#include <stdio.h>
#include <curl/curl.h>
#include <libxml/xmlwriter.h>

int main(void) {
    curl_global_init(CURL_GLOBAL_ALL);
    puts("Another dummy change to trigger rebuild.");
    xmlTextWriterPtr writer;
    writer = xmlNewTextWriterFilename("test.xml", 0);
    xmlTextWriterStartDocument(writer, NULL, "UTF-8", NULL);
    xmlTextWriterStartElement(writer, "Powersettings");
    xmlTextWriterWriteElement(writer, "PowerScheme", "Testing"); xmlTextWriterEndElement(writer);
    xmlTextWriterWriteElement(writer, "CPUSpeed", "Adaptive"); xmlTextWriterEndElement(writer);
    xmlTextWriterWriteElement(writer, "Dummy", "dummy"); xmlTextWriterEndElement(writer);
    xmlTextWriterEndElement(writer);
    xmlTextWriterEndDocument(writer);
    xmlFreeTextWriter(writer);
    curl_global_cleanup();
}