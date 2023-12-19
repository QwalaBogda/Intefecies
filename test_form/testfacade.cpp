#include <QtTest/QtTest>
#include "facade.h"

class TestFacade : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();  // Вызывается один раз перед запуском любого теста
    void cleanupTestCase();  // Вызывается после выполнения всех тестов
    void testGetLevels();  // Тест на получение списка уровней
    void testGetLevelData();  // Тест на чтение данных уровня
};

void TestFacade::initTestCase() {
    // Подготовка окружения для тестирования: создание файлов и директорий уровня, если это необходимо.
}

void TestFacade::cleanupTestCase() {
    // Очистка окружения после тестирования: удаление тестовых файлов и директорий.
}

void TestFacade::testGetLevels() {
    // Имитируем создание файлов уровней, если не хотим использовать настоящие
    QDir testDir("C:/levels/");
    QStringList files = {"level1.txt", "level2.txt", "level3.txt"};
    foreach (const QString &file, files) {
        QFile(testDir.filePath(file)).open(QIODevice::WriteOnly);
    }

    vector<string> levels = Facade::getLevels();

    // Проверяем, что количество уровней соответствует ожидаемому
    QCOMPARE(levels.size(), (size_t)files.size());

    // Проверяем, что имена уровней корректны
    // Список files должен быть преобразован в список с базовыми именами, так как completeBaseName() используется в методе getLevels()
    QStringList expectedLevelsBaseNames;
    for (const QString &fileName : files) {
        expectedLevelsBaseNames.push_back(QFileInfo(fileName).completeBaseName());
    }
    for (const string &levelName : levels) {
        QVERIFY(expectedLevelsBaseNames.contains(QString::fromStdString(levelName)));
    }

    // Удаляем тестовые файлы
    foreach (const QString &file, files) {
        QFile::remove(testDir.filePath(file));
    }
}

void TestFacade::testGetLevelData() {
    // Создаём тестовый файл уровня
    QString testLevelPath = "C:/levels/testLevel.txt";
    QFile testFile(testLevelPath);
    testFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&testFile);
    out << "3\n4\n----\n----\n----\n";
    testFile.close();

    // Запрашиваем данные уровня
    QString levelName = "testLevel";
    Level testData = Facade::get_level_data(levelName);

    // Проверяем корректность данных
    QCOMPARE(testData.h, 3);
    QCOMPARE(testData.w, 4);
    QCOMPARE(testData.leveldata.size(), (size_t)3);
    foreach (const QString &line, testData.leveldata) {
        QCOMPARE(line, QString("----"));
    }

    // Удаляем тестовый файл
    QFile::remove(testLevelPath);
}

QTEST_MAIN(TestFacade)
#include "test_facade.moc"
