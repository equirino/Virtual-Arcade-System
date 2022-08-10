// GameMenuNode.h

#include "Node.h"
#include "MenuScreen.h"
#include "SimpleButton.h"
#include "BrickBreakerNode.h"
#include "Config.h"
#include "TetrisNode.h"

class GameMenuNode : public Node
{
private:
    BrickBreakerNode* brickBreakerNode;
	TetrisNode* tetrisNode;
public:
	// pass this in from main when you create it
	GameMenuNode(SDL_Renderer* renderer_in = nullptr, Node* parentNode_in = nullptr) : Node(renderer_in, parentNode_in)
	{
        brickBreakerNode = new BrickBreakerNode(renderer_in, this);
		tetrisNode = new TetrisNode(renderer_in, this);
        children.push_back(brickBreakerNode);
		children.push_back(tetrisNode);

    	MenuScreen* tetrisScreen = createMenuScreen();
		MenuScreen* brickBreakerScreen = createMenuScreen();

		// tetris screen
		ArcadeTexture* tetrisBackgroundImage = createImage(renderer_in, "gameMenuNodeImages/gameMenuNodeScreenBackgroundTexture.png", true);
		tetrisScreen->addTextureToScreen(tetrisBackgroundImage);

		ArcadeTexture* tetrisGameMenuText = createSimpleText(renderer_in, "fonts/retro/italic.ttf",50, "TETRIS", 255, 255, 0);
		tetrisGameMenuText->setPosition(windowWidth / 2 - tetrisGameMenuText->getWidth() / 2, 20);
		tetrisScreen->addTextureToScreen(tetrisGameMenuText);

		SimpleButton* tetrisPreviousButton = createSimpleButton(renderer_in, "gameMenuNodeImages/previousScreenButton.png");
		tetrisPreviousButton->setButtonPosition(25, windowHeight / 2 - tetrisPreviousButton->getHeight() / 2);
		tetrisPreviousButton->setButtonAction(createAction(MOVE_SCREENS, brickBreakerScreen));
		tetrisScreen->addButtonToScreen(tetrisPreviousButton);

		SimpleButton* tetrisButton = createSimpleButton(renderer_in, "gameMenuNodeImages/tetrisGameButton.png");
		tetrisButton->setButtonPosition(windowWidth / 2 - tetrisButton->getButtonTexture()->getWidth() / 2,
			windowHeight / 2 - tetrisButton->getHeight() / 2);
		tetrisButton->setButtonAction(createAction(MOVE_NODES, tetrisNode));
		tetrisScreen->addButtonToScreen(tetrisButton);

		SimpleButton* tetrisNextButton = createSimpleButton(renderer_in, "gameMenuNodeImages/nextScreenButton.png");
		tetrisNextButton->setButtonPosition(windowWidth - tetrisNextButton->getWidth() - 25, windowHeight / 2 - tetrisNextButton->getWidth() / 2);
		tetrisNextButton->setButtonAction(createAction(MOVE_SCREENS, brickBreakerScreen));
		tetrisScreen->addButtonToScreen(tetrisNextButton);

		SimpleButton* tetrisMainMenuButton = createSimpleTextButton(renderer_in, "fonts/pixel/classic.ttf", 30, "MAIN MENU", 255, 0, 0);
		tetrisMainMenuButton->setButtonPosition(windowWidth / 2 - tetrisMainMenuButton->getWidth() / 2, windowHeight - 50);
		tetrisScreen->addButtonToScreen(tetrisMainMenuButton);
		tetrisMainMenuButton->setButtonAction(createAction(MOVE_NODES, getParentNode()));

		this->addScreen(tetrisScreen);


		// brickBreaker Screen
		ArcadeTexture* brickBreakerBackgroundImage = createImage(renderer_in, "gameMenuNodeImages/gameMenuNodeScreenBackgroundTexture.png", true);
		brickBreakerScreen->addTextureToScreen(brickBreakerBackgroundImage);

		ArcadeTexture* brickBreakerGameMenuText = createSimpleText(renderer_in, "fonts/retro/italic.ttf", 50, "BRICK BREAKER", 255, 255, 0);
		brickBreakerGameMenuText->setPosition(windowWidth / 2 - brickBreakerGameMenuText->getWidth() / 2, 20);
		brickBreakerScreen->addTextureToScreen(brickBreakerGameMenuText);

		SimpleButton* brickBreakerPreviousButton = createSimpleButton(renderer_in, "gameMenuNodeImages/previousScreenButton.png");
		brickBreakerPreviousButton->setButtonPosition(25, windowHeight / 2 - brickBreakerPreviousButton->getHeight() / 2);
		brickBreakerPreviousButton->setButtonAction(createAction(MOVE_SCREENS, tetrisScreen));
		brickBreakerScreen->addButtonToScreen(brickBreakerPreviousButton);
		
		SimpleButton* brickBreakerButton = createSimpleButton(renderer_in, "gameMenuNodeImages/brickBreakerGameButton.png");
		brickBreakerButton->setButtonPosition(windowWidth / 2 - brickBreakerButton->getWidth() / 2, windowHeight / 2 - brickBreakerButton->getHeight() / 2);
		brickBreakerButton->setButtonAction(createAction(MOVE_NODES, brickBreakerNode));
		brickBreakerScreen->addButtonToScreen(brickBreakerButton);
		
		SimpleButton* brickBreakerNextButton = createSimpleButton(renderer_in, "gameMenuNodeImages/nextScreenButton.png");
		brickBreakerNextButton->setButtonPosition(windowWidth - brickBreakerNextButton->getWidth() - 25, windowHeight / 2 - brickBreakerNextButton->getWidth() / 2);
		brickBreakerNextButton->setButtonAction(createAction(MOVE_SCREENS, tetrisScreen));
		brickBreakerScreen->addButtonToScreen(brickBreakerNextButton);

		SimpleButton* brickBreakerMainMenuButton = createSimpleTextButton(renderer_in, "fonts/pixel/classic.ttf", 30, "MAIN MENU", 255, 0, 0);
		brickBreakerMainMenuButton->setButtonPosition(windowWidth / 2 - brickBreakerMainMenuButton->getWidth() / 2, windowHeight - 50);
		brickBreakerMainMenuButton->setButtonAction(createAction(MOVE_NODES, getParentNode()));
		brickBreakerScreen->addButtonToScreen(brickBreakerMainMenuButton);

		this->addScreen(brickBreakerScreen);

		this->setCurrentScreen(tetrisScreen);
	}
};