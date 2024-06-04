#include <QStringList>

class Inventory {
public:
    Inventory();

    void addItem(const QString& item);
    void removeItem(const QString& item);
    QStringList getItems() const;

private:
    QStringList items;
};
