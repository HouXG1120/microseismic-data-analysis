#include "readconfig.h"

#include <QMessageBox>

/**
 * @author: Ethan
 * @date: 2013-3-20
 */
ReadConfig::ReadConfig(const QString &fileName)
{
    file = new QFile(fileName);
    if(!file->open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(0,
                              "Load XML File Problem",
                              "Couldn't open xml file to load settings for database",
                              QMessageBox::Ok);
        return;
    }

    doc = new QDomDocument();
    if(!doc->setContent(file))
    {
        file->close();
        return;
    }
}

ReadConfig::~ReadConfig()
{
    delete file;
    file = 0;
    delete doc;
    doc = 0;
}

QString ReadConfig::getValue(const QString &nodeName)
{
    QString result = "";
    QDomElement docElem = doc->documentElement();  // ���ظ�Ԫ��
    QDomNode n = docElem.firstChild();   // ���ظ��ڵ�ĵ�һ���ӽڵ�

    while(!n.isNull()) // ����ڵ㲻Ϊ��
    {
        if (n.isElement())  //����ڵ���Ԫ��
        {
            QDomElement e = n.toElement();  //����ת��ΪԪ��
            // ����Ԫ�ر��
            qDebug() << qPrintable(e.tagName());
                   // << qPrintable(e.attribute("id")); // ����Ԫ��id���Ե�ֵ
            QDomNodeList list = e.childNodes(); // ���Ԫ�� e �������ӽڵ���б�
            for(int i=0; i<list.count(); i++) // �������б�
            {
                QDomNode node = list.at(i);
                if(node.isElement())
                {
                    qDebug() << " " << qPrintable(node.toElement().tagName())
                            << qPrintable(node.toElement().text());
                    if(nodeName.operator ==(node.toElement().tagName()))
                    {
                        result = node.toElement().text();
                        break;
                    }
                }
            }
        }
        n = n.nextSibling(); // ��һ���ֵܽڵ�
    }

    return result;
}
