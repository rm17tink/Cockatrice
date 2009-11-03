#ifndef CHATCHANNEL_H
#define CHATCHANNEL_H

#include <QList>
#include <QObject>
#include <QStringList>

class Server_ProtocolHandler;
class ChatEvent;

class Server_ChatChannel : public QObject, public QList<Server_ProtocolHandler *> {
	Q_OBJECT
signals:
	void channelInfoChanged();
private:
	QString name;
	QString description;
	bool autoJoin;
	QString joinMessage;
public:
	Server_ChatChannel(const QString &_name, const QString &_description, bool _autoJoin, const QString &_joinMessage);
	QString getName() const { return name; }
	QString getDescription() const { return description; }
	bool getAutoJoin() const { return autoJoin; }
	void addClient(Server_ProtocolHandler *client);
	void removeClient(Server_ProtocolHandler *client);
	void say(Server_ProtocolHandler *client, const QString &s);
	
	void sendChatEvent(ChatEvent *event);
};

#endif
