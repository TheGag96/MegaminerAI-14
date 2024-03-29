#include "animations.h"
#include "plants.h"

namespace visualizer
{
	void DrawFadedObject::animate(const float &t, AnimData *d, IGame *game)
	{
		// Set the color to red
		float scalar = t;
		if(m_fade == FadeIn)
		{
			scalar = t;
		}
		else if(m_fade == FadeOut)
		{
			scalar = 1 - t;
		}
		else
		{
			scalar = 1.0f;
		}

		//float color = m_data->fade
		game->renderer->setColor(Color(m_color.r, m_color.g, m_color.b, m_color.a * scalar));
	}

	void DrawQuad::animate( const float& t, AnimData* d, IGame* game )
	{
		DrawFadedObject::animate(t, d, game);

		game->renderer->drawQuad( m_data->x, m_data->y, m_data->width, m_data->height );
	}
	
	void DrawWinningScreen::animate( const float& t, AnimData* d, IGame* game )
	{
		DrawFadedObject::animate(t, d, game);

		game->renderer->drawQuad( m_data->x, m_data->y, m_data->width, m_data->height );
		game->renderer->setColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
		game->renderer->drawText( m_data->x + (m_data->width)/2, m_data->y + (m_data->height)/2, "Roboto", m_data->winner, 200.0f, IRenderer::Center);
	}

	void DrawCircle::animate( const float& t, AnimData* d, IGame* game )
	{
		DrawFadedObject::animate(t, d, game);

		game->renderer->drawCircle( m_data->x, m_data->y, m_data->radius, 1, 100 );
	}

	void DrawTexturedCircle::animate(const float &t, AnimData *d, IGame *game)
	{
		// TODO: move this logic to offset the circle out of here
		static float dt = 0.0f;
		dt += game->timeManager->getDt();

		DrawFadedObject::animate(t, d, game);

		float dx = 0.3 * cos(0.01*dt);
		float dy = 0.3 * sin(0.01*dt);
		game->renderer->drawTexturedCircle(m_data->x, m_data->y, m_data->radius, 1, 100, m_data->texture, 0.0f, dx, dy);

		dx = 0.1 * cos(0.012*dt);
		dy = 0.1 * sin(0.012*dt);
		game->renderer->drawTexturedCircle(m_data->x, m_data->y, m_data->radius, 1, 100, m_data->texture, 0.0f, 4*dx, 4*dy, -20*dy, -20*dx);
	}

	void DrawSprite::animate( const float& t, AnimData* d, IGame* game )
	{
		DrawFadedObject::animate(t, d, game);

		game->renderer->drawTexturedQuad( m_data->x, m_data->y, m_data->width, m_data->height, 1, m_data->texture );
	}

	void DrawAnimatedSprite::animate(const float &t, AnimData *d, IGame *game)
	{
		DrawFadedObject::animate(t, d, game);

		int currentFrame = (m_data->endFrame - m_data->startFrame) * t + m_data->startFrame;
		game->renderer->drawAnimQuad(m_data->x, m_data->y,
									 m_data->width, m_data->height,
									 m_data->texture, false, currentFrame);
	}
}
