#include <sstream>
#include "Logger.h"

namespace Falltergeist
{
    Logger::Logger(const std::string& channel) : _channel(channel) {
    }

    Logger::Level Logger::level()
    {
        return _level;
    }

    void Logger::setLevel(Logger::Level level)
    {
        _level = level;
    }

    std::ostream &Logger::log(Logger::Level level, const std::string &subsystem)
    {
        // A /dev/null-like stream
        static std::ostream nullstream(nullptr);
        if (level < _level) {
            return nullstream;
        }
        std::string subsystemMsg = " ";
        if (subsystem.size() > 0) {
            subsystemMsg = " [" + subsystem + "] ";
        }

        return std::cout << levelString(level) << subsystemMsg << std::dec;
    }

    // Initial level; overridden with config option with default level LOG_INFO
    Logger::Level Logger::_level = Logger::Level::LOG_DEBUG;
    bool Logger::_useColors = true;

#if defined(__unix__) || defined(__APPLE__)
    const bool Logger::colorsSupported = true;
#else // Assume Windows
    const bool Logger::colorsSupported = false;
#endif

    const char *Logger::levelString(Logger::Level level)
    {
        if (_useColors && colorsSupported)
        {
            switch (level)
            {
                case Logger::Level::LOG_DEBUG:
                    return "[DEBUG]";
                case Logger::Level::LOG_INFO:
                    return "\x1b[32m[INFO]\x1b[0m";
                case Logger::Level::LOG_WARNING:
                    return "\x1b[33m[WARNING]\x1b[0m";
                case Logger::Level::LOG_ERROR:
                    return "\x1b[31m[ERROR]\x1b[0m";
                case Logger::Level::LOG_CRITICAL:
                    return "\x1b[31;1m[CRITICAL]\x1b[0m";
                default:
                    break;
            }
        }
        else
        {
            switch (level)
            {
                case Logger::Level::LOG_DEBUG:
                    return "[DEBUG]";
                case Logger::Level::LOG_INFO:
                    return "[INFO]";
                case Logger::Level::LOG_WARNING:
                    return "[WARNING]";
                case Logger::Level::LOG_ERROR:
                    return "[ERROR]";
                case Logger::Level::LOG_CRITICAL:
                    return "[CRITICAL]";
                default:
                    break;
            };
        }

        return "[UNKNOWN]";
    }

    std::ostream &Logger::debug(const std::string &subsystem)
    {
        return log(Logger::Level::LOG_DEBUG, subsystem);
    }

    std::ostream &Logger::info(const std::string &subsystem)
    {
        return log(Logger::Level::LOG_INFO, subsystem);
    }

    std::ostream &Logger::warning(const std::string &subsystem)
    {
        return log(Logger::Level::LOG_WARNING, subsystem);
    }

    std::ostream &Logger::error(const std::string &subsystem)
    {
        return log(Logger::Level::LOG_ERROR, subsystem);
    }

    std::ostream &Logger::critical(const std::string &subsystem)
    {
        return log(Logger::Level::LOG_CRITICAL, subsystem);
    }

    std::ostream& Logger::debug()
    {
        return log(Logger::Level::LOG_DEBUG, "");
    }

    std::ostream& Logger::info()
    {
        return log(Logger::Level::LOG_INFO, "");
    }

    std::ostream& Logger::warning()
    {
        return log(Logger::Level::LOG_WARNING, "");
    }

    std::ostream& Logger::error()
    {
        return log(Logger::Level::LOG_ERROR, "");
    }

    std::ostream& Logger::critical()
    {
        return log(Logger::Level::LOG_CRITICAL, "");
    }

    void Logger::useColors(bool useColors)
    {
        _useColors = useColors;
    }

    void Logger::setLevel(const std::string &level)
    {
        Logger::Level lvl = Logger::Level::LOG_NONE;

        if (level == "debug")
        {
            lvl = Level::LOG_DEBUG;
        }
        else if (level == "info")
        {
            lvl = Level::LOG_INFO;
        }
        else if (level == "warning")
        {
            lvl = Level::LOG_WARNING;
        }
        else if (level == "error")
        {
            lvl = Level::LOG_ERROR;
        }
        else if (level == "critical")
        {
            lvl = Level::LOG_CRITICAL;
        }
        else
        {
            warning("") << "Unknown level " << level << " ignored";
            return;
        }

        setLevel(lvl);

    }

    std::ostream& operator <<(std::ostream& lhs, const Point& rhs)
    {
        lhs << "(" << rhs.x() << "," << rhs.y() << ")";
        return lhs;
    }

    std::ostream& operator <<(std::ostream& lhs, const Size& rhs)
    {
        lhs << rhs.width() << "x" << rhs.height();
        return lhs;
    }

    std::string to_string(const Point& point)
    {
        std::ostringstream sstr;
        sstr << point;
        return sstr.str();
    }

    std::string to_string(const Size& size)
    {
        std::ostringstream sstr;
        sstr << size;
        return sstr.str();
    }
}
