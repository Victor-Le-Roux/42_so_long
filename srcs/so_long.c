#include "so_long.h"

int main(void)
{
void *mlx;
void *mlx_win;
int img_width = 64;
int img_height = 64;
void *img;

mlx = mlx_init();
mlx_win = mlx_new_window(mlx,1920,1080, "test");
img = mlx_xpm_file_to_image(mlx, FINN_D ,	&img_width , &img_height);
if(!img)
  return 0;
mlx_put_image_to_window(mlx,mlx_win,img, 100,100);
mlx_loop(mlx);
}
