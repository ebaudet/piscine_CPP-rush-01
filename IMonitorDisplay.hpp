#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

class IMonitorDisplay {
public:
    virtual void    init() = 0;
    virtual void    quit() = 0;
    virtual void    play() = 0;
    virtual ~IMonitorDisplay() = 0;
};

#endif // IMONITORDISPLAY

