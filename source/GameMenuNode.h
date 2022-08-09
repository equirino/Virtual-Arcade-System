// GameMenuNode.h

#include "Node.h"
#include "MenuScreen.h"
#include "SimpleButton.h"
#include "Config.h"
#include "TetrisNode.h" // NEW LINE ADD THIS

class GameMenuNode : public Node
{
	TetrisNode* tetrisNode; // NEW LINE ADD THIS
public:
	// pass this in from main when you create it
	GameMenuNode(SDL_Renderer* renderer_in = nullptr, Node* parentNode_in = nullptr) : Node(renderer_in, parentNode_in)
	{
    tetrisNode = new TetrisNode(renderer_in, this); // NEW LINE ADD THIS
		children.push_back(tetrisNode); // NEW LINE ADD THIS

    MenuScreen* tetrisScreen = createMenuScreen();
		MenuScreen* froggerScreen = createMenuScreen();
		MenuScreen* brickBreakerScreen = createMenuScreen();

		// tetris screen
		ArcadeTexture* tetrisBackgroundImage = createImage(renderer_in, "gameMenuNodeImages/gameMenuNodeScreenBackgroundTexture.png", true);
		tetrisScreen->addTextureToScreen(tetrisBackgroundImage);

		ArcadeTexture* tetrisGameMenuText = createSimpleText(renderer_in, "fonts/retro/italic.ttf",100, "TETRIS", 255, 255, 0);
		tetrisGameMenuText->setPosition(windowWidth / 2 - tetrisGameMenuText->getWidth() / 2, 20);
		tetrisScreen->addTextureToScreen(tetrisGameMenuText);

		SimpleButton* tetrisPreviousButton = createSimpleButton(renderer_in, "gameMenuNodeImages/previousScreenButton.png");
		tetrisPreviousButton->setButtonPosition(25, windowHeight / 2 - tetrisPreviousButton->getHeight() / 2);
		tetrisPreviousButton->setButtonAction(createAction(MOVE_SCREENS, froggerScreen));
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

        this->setCurrentScreen(tetrisScreen);
    }
};

