#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <QString>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QMap>

class TextAnalyzer {
public:
    TextAnalyzer();
    
    // Main analysis function
    bool analyzeFile(const QString& filename, const QStringList& flags);
    
    // Get results
    QMap<QString, int> getResults() const { return results; }
    
private:
    // Pattern matching functions
    int countCapitalLongWords(const QString& text);
    int countHyphenatedWords(const QString& text);
    int countSameStartEndWords(const QString& text);
    int countNonVowelStartWords(const QString& text);
    
    // Regular expressions
    QRegularExpression capitalLongWordsPattern;
    QRegularExpression hyphenatedWordsPattern;
    QRegularExpression sameStartEndPattern;
    QRegularExpression nonVowelStartPattern;
    
    // Results storage
    QMap<QString, int> results;
};

#endif // TEXTANALYZER_H 