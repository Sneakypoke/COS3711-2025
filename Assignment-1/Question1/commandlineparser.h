#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <QString>
#include <QStringList>
#include <QCommandLineParser>

class CommandLineParser {
public:
    CommandLineParser();
    
    // Initialize and process command line arguments
    void initialize(QCoreApplication& app);
    
    // Get the files to process
    QStringList getFiles() const { return m_files; }
    
    // Get the enabled flags
    QStringList getFlags() const { return m_flags; }

private:
    void setupOptions();
    void processFlags(const QString& combinedFlags);
    
    QCommandLineParser m_parser;
    QStringList m_files;
    QStringList m_flags;
}; 