#ifndef GOCXMLOBJECTTHREAD_H
#define GOCXMLOBJECTTHREAD_H

#include <QThread>

class GOCXMLObjectThread : public QThread
{
	Q_OBJECT

public:
	GOCXMLObjectThread(QObject *parent);
	virtual ~GOCXMLObjectThread();

private:
	
};

#endif // GOCXMLOBJECTTHREAD_H
