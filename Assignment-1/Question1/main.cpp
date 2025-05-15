#include <QCoreApplication>
#include <QDebug>
#include "textanalyzer.h"
#include "commandlineparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    // Parse command line arguments
    CommandLineParser parser;
    parser.initialize(a);
    
    // Create analyzer and process files
    TextAnalyzer analyzer;
    
    // Process each file
    for (const QString& file : parser.getFiles()) {
        if (analyzer.analyzeFile(file, parser.getFlags())) {
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
