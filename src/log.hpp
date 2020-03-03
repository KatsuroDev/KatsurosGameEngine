//
//  log.hpp
//
//
//  Created by Thomas Lessard on 2020-03-02.
//

#ifndef log_hpp
#define log_hpp

class Log
{
public:
    static void Error(const char* msg);

    static void Warn(const char* msg);

    static void Info(const char* msg);
};

#endif /* log_hpp */
