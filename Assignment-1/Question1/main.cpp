#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QDir>
#include "textanalyzer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("count");
    QCoreApplication::setApplicationVersion("1.0");

    // Create command line parser
    QCommandLineParser parser;
    parser.setApplicationDescription("Text file analyzer using regular expressions");
    parser.addHelpOption();
    parser.addVersionOption();

    // Add options
    QCommandLineOption optionA(QStringList() << "a", "Count words >4 chars starting with uppercase");
    QCommandLineOption optionB(QStringList() << "b", "Count hyphenated words");
    QCommandLineOption optionC(QStringList() << "c", "Count words starting and ending with same character");
    QCommandLineOption optionD(QStringList() << "d", "Count words not starting with a vowel");

    parser.addOption(optionA);
    parser.addOption(optionB);
    parser.addOption(optionC);
    parser.addOption(optionD);

    // Process the command line arguments
    parser.process(a);

    // Get positional arguments (files)
    const QStringList args = parser.positionalArguments();
    if (args.isEmpty()) {
        parser.showHelp(1);
    }

    // Show current working directory for debugging
    qDebug() << "Current working directory:" << QDir::currentPath();

    // Create analyzer and process files
    TextAnalyzer analyzer;
    QStringList flags;
    
    // Collect enabled flags
    if (parser.isSet(optionA)) flags << "-a";
    if (parser.isSet(optionB)) flags << "-b";
    if (parser.isSet(optionC)) flags << "-c";
    if (parser.isSet(optionD)) flags << "-d";

    // Process each file
    for (const QString& file : args) {
        if (analyzer.analyzeFile(file, flags)) {
            qDebug() << "\n***" << file << "***";
            QMap<QString, int> results = analyzer.getResults();
            
            // Print results in a specific order with descriptive text
            if (results.contains("-a")) {
                qDebug() << "Number of words longer than 4 letters that start with a capital:" << results["-a"];
            }
            if (results.contains("-b")) {
                qDebug() << "Number of hyphenated words:" << results["-b"];
            }
            if (results.contains("-c")) {
                qDebug() << "Number of words that start and end on the same letter:" << results["-c"];
            }
            if (results.contains("-d")) {
                qDebug() << "Number of words not starting with a vowel:" << results["-d"];
            }
        }
    }

    return 0;
}
