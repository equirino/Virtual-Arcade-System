// GameNode.h

#include "Node.h"
#include "Config.h"
#include "BrickBreakerGame.h"


class BrickBreakerNode : public Node
{
    public: 
        BrickBreakerNode(SDL_Renderer* renderer_in, Node* parentNode_in): Node(renderer_in, parentNode_in)
        {
            BrickBreakerGame* game = new BrickBreakerGame;
            //game->addTextureToScreen(createImage(renderer_in, "brickBreakerNodeImages/brickBreakerScreen.png", true));

            Ball* ball = new Ball;
            ArcadeTexture* ballTexture = createImage(renderer_in, "brickBreakerNodeImages/ballTexture.png");

            ball->setGameObjectTexture(ballTexture);
            ball->setState(true);

            game->addEntity(ball);
            game->addMovingEntity(ball);
            game->setBall(ball);

            game->setisNewGame(true);
            game->setGameState(true);

            this->addScreen(game);
            this->setCurrentScreen(game);
        }
};