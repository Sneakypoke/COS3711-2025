#include "commandlineparser.h"
#include <QCoreApplication>
#include <algorithm>

CommandLineParser::CommandLineParser() {
    setupOptions();
}

void CommandLineParser::initialize(QCoreApplication& app) {
    // Set application info
    app.setApplicationName("count");
    app.setApplicationVersion("1.0");
    
    // Process arguments
    m_parser.process(app);
    
    // Get files
    m_files = m_parser.positionalArguments();
    
    // If no files specified, use defaults
    if (m_files.isEmpty()) {
        m_files << "file1.txt" << "file2.txt";
        return;
    }
    
    // Handle both separate (-a -b) and combined (-ab) flags
    QString combinedFlags;
    for (const QString& arg : std::as_const(m_files)) {
        if (arg.startsWith("-") && arg.length() > 1) {
            combinedFlags += arg.mid(1);
            m_files.removeOne(arg);
        }
    }
    
    processFlags(combinedFlags);
}

void CommandLineParser::setupOptions() {
    m_parser.setApplicationDescription("Text file analyzer using regular expressions");
    m_parser.addHelpOption();
    m_parser.addVersionOption();
    
    // Add options
    m_parser.addOption(QCommandLineOption("a", "Count words >4 chars starting with uppercase"));
    m_parser.addOption(QCommandLineOption("b", "Count hyphenated words"));
    m_parser.addOption(QCommandLineOption("c", "Count words starting and ending with same character"));
    m_parser.addOption(QCommandLineOption("d", "Count words not starting with a vowel"));
}

void CommandLineParser::processFlags(const QString& combinedFlags) {
    // Process individual flags
    if (combinedFlags.contains('a') || m_parser.isSet("a")) m_flags << "-a";
    if (combinedFlags.contains('b') || m_parser.isSet("b")) m_flags << "-b";
    if (combinedFlags.contains('c') || m_parser.isSet("c")) m_flags << "-c";
    if (combinedFlags.contains('d') || m_parser.isSet("d")) m_flags << "-d";
} 