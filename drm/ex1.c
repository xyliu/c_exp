#include <stdio.h>
#include <assert.h>
#include <xf86drm.h>

int main(void)
{
	int fds[3], fd;
	int i;

	for(i=0 ; i<3; i++) {
		fds[i] = drmOpenWithType("i915", NULL, DRM_NODE_RENDER);
		assert(fds[i] >= 0);

		printf("fd[%d]:%x\n", i, fds[i]);
	}

	for(i=0;i<3;i++)
		drmClose(fds[i]);
	return 0;
}

