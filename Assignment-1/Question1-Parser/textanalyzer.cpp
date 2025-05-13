#include "textanalyzer.h"
#include <QDebug>
#include <QFileInfo>
#include <QDir>

// Define the static member
const QRegularExpression TextAnalyzer::whitespacePattern("\\s+");

TextAnalyzer::TextAnalyzer() {
    // Initialize regular expressions
    capitalLongWordsPattern = QRegularExpression("\\b[A-Z][a-zA-Z]{4,}\\b");
    hyphenatedWordsPattern = QRegularExpression("\\b\\w+-\\w+\\b");
    sameStartEndPattern = QRegularExpression("\\b(\\w)\\w*\\1\\b");
    nonVowelStartPattern = QRegularExpression("\\b[^aeiouAEIOU]\\w*\\b");
}

bool TextAnalyzer::analyzeFile(const QString& filename, const QStringList& flags) {
    QFileInfo fileInfo(filename);
    
    // If the file doesn't exist, try to find it in the current working directory
    if (!fileInfo.exists()) {
        QString currentPath = QDir::currentPath();
        QString alternativePath = QDir(currentPath).filePath(filename);
        fileInfo.setFile(alternativePath);
        
        if (!fileInfo.exists()) {
            qDebug() << "Error: Could not find file" << filename;
            qDebug() << "Tried paths:";
            qDebug() << "  -" << filename;
            qDebug() << "  -" << alternativePath;
            qDebug() << "Current working directory:" << currentPath;
            return false;
        }
    }

    QFile file(fileInfo.absoluteFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not open file" << fileInfo.absoluteFilePath();
        qDebug() << "Error details:" << file.errorString();
        return false;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    text = preprocessText(text);
    
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

QString TextAnalyzer::preprocessText(const QString& text) {
    // Remove extra whitespace and normalize line endings
    QString processed = text.simplified();
    processed.replace(whitespacePattern, " ");
    return processed;
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

void TextAnalyzer::showUsage() const {
    qDebug() << "Usage: count [options] file1 [file2 ...]";
    qDebug() << "Options:";
    qDebug() << "  -a    Count words >4 chars starting with uppercase";
    qDebug() << "  -b    Count hyphenated words";
    qDebug() << "  -c    Count words starting and ending with same character";
    qDebug() << "  -d    Count words not starting with a vowel";
    qDebug() << "If no options specified, all patterns will be analyzed.";
} 