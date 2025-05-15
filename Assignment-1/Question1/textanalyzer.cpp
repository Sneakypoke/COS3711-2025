#include "textanalyzer.h"
#include <QDebug>

TextAnalyzer::TextAnalyzer() {
    // Initialize regular expressions
    capitalLongWordsPattern = QRegularExpression("\\b[A-Z][a-zA-Z]{4,}\\b");
    hyphenatedWordsPattern = QRegularExpression("\\b\\w+-\\w+\\b");
    sameStartEndPattern = QRegularExpression("\\b(\\w)\\w*\\1\\b");
    nonVowelStartPattern = QRegularExpression("\\b[^aeiouAEIOU]\\w*\\b");
}

bool TextAnalyzer::analyzeFile(const QString& filename, const QStringList& flags) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not open file:" << filename;
        return false;
    }

    QTextStream in(&file);
    QString text = in.readAll().simplified();
    
    // Clear previous results
    results.clear();
    
    // If no flags specified, analyze all patterns
    if (flags.isEmpty()) {
        results["-a"] = countCapitalLongWords(text);
        results["-b"] = countHyphenatedWords(text);
        results["-c"] = countSameStartEndWords(text);
        results["-d"] = countNonVowelStartWords(text);
    } else {
        // Analyze only specified patterns
        for (const QString& flag : flags) {
            if (flag == "-a") results["-a"] = countCapitalLongWords(text);
            else if (flag == "-b") results["-b"] = countHyphenatedWords(text);
            else if (flag == "-c") results["-c"] = countSameStartEndWords(text);
            else if (flag == "-d") results["-d"] = countNonVowelStartWords(text);
        }
    }
    
    return true;
}

int TextAnalyzer::countCapitalLongWords(const QString& text) {
    int count = 0;
    QRegularExpressionMatchIterator it = capitalLongWordsPattern.globalMatch(text);
    while (it.hasNext()) {
        it.next();
        count++;
    }
    return count;
}

int TextAnalyzer::countHyphenatedWords(const QString& text) {
    int count = 0;
    QRegularExpressionMatchIterator it = hyphenatedWordsPattern.globalMatch(text);
    while (it.hasNext()) {
        it.next();
        count++;
    }
    return count;
}

int TextAnalyzer::countSameStartEndWords(const QString& text) {
    int count = 0;
    QRegularExpressionMatchIterator it = sameStartEndPattern.globalMatch(text);
    while (it.hasNext()) {
        it.next();
        count++;
    }
    return count;
}

int TextAnalyzer::countNonVowelStartWords(const QString& text) {
    int count = 0;
    QRegularExpressionMatchIterator it = nonVowelStartPattern.globalMatch(text);
    while (it.hasNext()) {
        it.next();
        count++;
    }
    return count;
} 