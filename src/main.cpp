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

void Move(string diraction){
    if(diraction == "L"){
            lua_State *L = luaL_newstate();
            luaL_openlibs(L);
            int r = luaL_dofile(L,"LuaFiles/player.lua");
            if(r == LUA_OK){
                luaL_getglobal(L, "MoveLeft");
                if(lua_isfunction(L, -1)){
                    if(lua_pcall(L,0,0,0)){
                        
                    }
                }
            }
            else{
                string errormsg = lua_tostring(L, -1);
                cout << errormsg << endl;
            }
            lua_close(L);
    }
    if(diraction == "R"){
                    lua_State *L = luaL_newstate();
            luaL_openlibs(L);
            int r = luaL_dofile(L,"LuaFiles/player.lua");
            if(r == LUA_OK){
                luaL_getglobal(L, "MoveRight");
                if(lua_isfunction(L, -1)){
                    if(lua_pcall(L,0,0,0)){
                        
                    }
                }
            }
            else{
                string errormsg = lua_tostring(L, -1);
                cout << errormsg << endl;
            }
            lua_close(L);
    }
}

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
            luaL_openlibs(L);
            int r = luaL_dofile(L,"LuaFiles/player.lua");
            int t = luaL_dofile(L,"LuaFiles/player.lua");
            if(r == LUA_OK){
                lua_getglobal(L, "x");
                if (lua_isnumber(L, -1)){
                    x = (float)lua_tonumber(L, -1);
                }
                lua_getglobal(L, "y");
                if (lua_isnumber(L, -1)){
                    y = (float)lua_tonumber(L, -1);
                }
            }
            else{
                string errormsg = lua_tostring(L, -1);
                cout << errormsg << endl;
            }
            lua_close(L);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Move("L");
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Move("R");
        }
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
