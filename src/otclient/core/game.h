/*
 * Copyright (c) 2010-2011 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef GAME_H
#define GAME_H

#include "declarations.h"
#include <otclient/net/declarations.h>

class Game
{
public:
    void init();
    void terminate();

    void loginWorld(const std::string& account,
                    const std::string& password,
                    const std::string& worldHost, int worldPort,
                    const std::string& characterName);
    void logout();

    void onLogin();
    void onLogout();

    void walk(Otc::Direction direction);
    void turn(Otc::Direction direction);

    bool isOnline() { return m_online; }

    LocalPlayerPtr getLocalPlayer() { return m_localPlayer; }
    ProtocolGamePtr getProtocolGame() { return m_protocolGame; }

private:
    LocalPlayerPtr m_localPlayer;
    ProtocolGamePtr m_protocolGame;
    bool m_online;
};

extern Game g_game;

#endif