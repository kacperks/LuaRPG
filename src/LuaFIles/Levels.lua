local textures[5]

X = 0
Y = 0

function generate(type,sizeX,sizeY):
    if type == "big" then
        X = sizeX * 5
        Y = sizeY * 5
        for i=sizeX * 5,a.n do
            --generate the level x 
        end
        for i=sizeY * 5,a.n do
            --generate the level Y
        end
    end
    if type == "small" then
        X = sizeX
        Y = sizeY
        for i=sizeX ,a.n do
            --generate the level x 
        end
        for i=sizeY ,a.n do
            --generate the level Y
        end
    end
end