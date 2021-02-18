#include "LR/Core.hpp"

using namespace std;

extern "C"
{
    #include "Lua542/include/lua.h"
    #include "Lua542/include/lauxlib.h"
    #include "Lua542/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Lua542/liblua54.a")
#endif

float x; //Player X
float y; //Player Y

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lua RPG !");
    sf::Texture texture;
    if (!texture.loadFromFile("images/player.png"))
    {
        cout << "failed to load player texture!" <<endl;
    }
    sf::Sprite Player;
    Player.setTexture(texture);
    Player.setPosition(sf::Vector2f(10.f, 50.f));
    Player.setScale(sf::Vector2f(0.5f, 2.f));
    while (window.isOpen())
    {
        sf::Event event;

            lua_State *L = luaL_newstate();
            int r = luaL_dofile(L,"LuaFiles/player.lua");
            if(r == LUA_OK){
                lua_getglobal(L, "x");
                if (lua_isnumber(L, -1)){
                    x = (float)lua_tonumber(L, -1);
                }
            }
            else{
                string errormsg = lua_tostring(L, -1);
                cout << errormsg << endl;
            }
            lua_close(L);
            lua_State *S = luaL_newstate();
            int t = luaL_dofile(S,"LuaFiles/player.lua");
            if(t == LUA_OK){
                lua_getglobal(L, "y");
                if (lua_isnumber(L, -1)){
                    y = (float)lua_tonumber(L, -1);
                }
            }
            else{
                string errormsg = lua_tostring(L, -1);
                cout << errormsg << endl;
            }
            lua_close(S);

        Player.move(sf::Vector2f(x, y));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Player);
        window.display();
    }

    return 0;
}
