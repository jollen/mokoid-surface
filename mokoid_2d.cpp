#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "surfaceflinger.h"

#define RGBA8888(r, g, b, a)	\
	((((r) & 0xff) <<  0) |	\
	 (((g) & 0xff) <<  8) |	\
	 (((b) & 0xff) << 16) |	\
	 (((a) & 0xff) << 24))

static void draw(char *buf, int w, int h, int stride)
{
	int x, y;

	for (y = 0; y < h; y++) {
		char *row = buf + stride * y;

		for (x = 0; x < w; x++) {
			int r, g, b, a;

			r = 0xff;
			g = 0x00;
			b = 0x00;
			a = 0xff;

			((uint32_t *) row)[x] = RGBA8888(r, g, b, a);
		}
	}
}

static void demo(int x, int y, int w, int h)
{
	char *buf;
	int stride = 300;

	if (!surfaceflinger_init(x, y, w, h, &stride)) {
		printf("failed to initialize surfaceflinger\n");
		return;
	}

    buf = surfaceflinger_lock();
	draw(buf, w, h, stride);
    surfaceflinger_unlock();

	sleep(5);

	surfaceflinger_fini();
}

int main(int argc, char **argv)
{
	demo(10, 10, 200, 200);

	return 0;
}
