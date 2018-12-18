#include<QtWidgets/QApplication>
#include<qgsapplication.h>

#include "GISers.h"

int main(int argc, char *argv[])
{
	QgsApplication myApp(argc, argv, true);
	QgsApplication::setPrefixPath("D:/OSGeo4W64/apps/qgis", true); 
	QgsApplication::initQgis();

	GISers* mygis = new GISers();
	mygis->show();
	return myApp.exec();
}
