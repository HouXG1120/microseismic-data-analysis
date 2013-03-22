#ifndef READCONFIG_H
#define READCONFIG_H

#include <QString>
#include <QFile>
#include <QDomDocument>
#include <QtDebug>

/**
 * @author: Ethan
 * @date: 2013-3-20
 */
class ReadConfig
{
public:
    ReadConfig(const QString &fileName);

    ~ReadConfig();

    /**
     * ��ȡ�����ļ��е�ֵ
     *
     * @param key ���õļ�
     * @param type ���ͱ�ǩ
     *
     * @return �������Ӧ��ֵ
     */
    QString getValue(const QString &node);

private:
    QFile *file;
    QDomDocument *doc;

};

#endif // READCONFIG_H
