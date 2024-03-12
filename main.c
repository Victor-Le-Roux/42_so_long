// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512
#define WIDTH_HERO 104
#define HEIGHT_HERO 232
static mlx_image_t* hero;

void ft_hook(void* param)
{
	mlx_t* mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W)&& hero->instances[0].y > 0)
		hero->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S)&& hero->instances[0].y < HEIGHT - HEIGHT_HERO)
		hero->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A)&& hero->instances[0].x > 0 )
		hero->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D)&& hero->instances[0].x < WIDTH - WIDTH_HERO) 
		hero->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;
	mlx_texture_t* img_hero;
	img_hero = mlx_load_png("./sprite/hero_idle.png");
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	
	hero = mlx_texture_to_image(mlx,img_hero);
	if(!hero)
	{	
		mlx_delete_texture(img_hero);
		mlx_terminate(mlx);
		return EXIT_FAILURE;
	}
	mlx_image_to_window(mlx,hero,0,0);
	mlx_loop_hook(mlx,ft_hook,mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

