#include <psx/gx.h>
#include "../res/kid.tim.c"

#define NUM_SPRITES 4

typedef struct sprite
{
	int tx, ty; // Texture coordinates
	int x, y; // Position on screen
	uint8_t w, h; // Size
	int vx, vy; // Velocity
}
sprite_t;

uint16_t res_w;
uint16_t res_h;
struct gx_texture *texture;
uint16_t tex_w;
uint16_t tex_h;
sprite_t sprites[NUM_SPRITES];

sprite_t *InitSprite(int index, int x, int y, int tx, int ty, int vx, int vy)
{
	sprite_t *spr = &sprites[i];
	spr->x = x;
	spr->y = y;
	spr->vx = vx;
	spr->vy = vy;
	spr->tx = tx;
	spr->ty = ty;
	spr->w = tex_w;
	spr->h = tex_h;
	return spr;
}

void UpdateSprite(sprite_t *spr)
{
	int newx = spr->x + spr->vx;
	int newy = spr->y + spr->vy;
	if ((newx + spr->w) >= res_w || (newy + spr->h) >= res_h || newx <= 0 || newy <= 0)
	{
		int vx = spr->vx;
		spr->vx = -spr->vy;
		spr->vy = vx;
	}
	else
	{
		spr->x = newx;
		spr->y = newy;
	}
}

int main(void)
{
	GX_Init(GX_HRES_320, GX_VRES_240);
	
	GX_SetClearColor(GX_GRAY);
	
	GX_GetResolution(&res_w, &res_h);
	
	texture = GX_LoadTIM(kid_tim);
	GX_GetTextureDims(texture, &tex_w, &tex_h);
	
	InitSprite(0, 50, 50, 0, 0, -1, 1);
	InitSprite(1, 60, 30, 0, 0, 1, 1);
	InitSprite(2, 120, 20, 0, 0, -1, -1);
	InitSprite(3, 100, 80, 0, 0, 1, -1);
	
	while (1)
	{
		GX_Clear();
		
		GX_SelectTexture(texture);
		
		for (int i = 0; i < NUM_SPRITES; ++i)
		{
			sprite_t *spr = &sprites[i];
			UpdateSprite(spr);
			GX_DrawRectangleTextured(
				spr->x,
				spr->y,
				spr->w,
				spr->h,
				spr->tx,
				spr->ty
				);
		}
		
		GX_Sync();
    }
	
    return 0;
}
