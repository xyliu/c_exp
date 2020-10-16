#include <stdio.h>
#include <assert.h>
#include <drm.h>
#include <xf86drm.h>
#include <i915_drm.h>

int ex1()
{
	int fds[3], fd;
	int i;

	for(i = 0; i < 3; i++) {
		fds[i] = drmOpenWithType("i915", NULL, DRM_NODE_RENDER);
		assert(fds[i] >= 0);
		printf("fd[%d]:%x\n", i, fds[i]);
	}

	for(i = 0; i < 3; i++)
		drmClose(fds[i]);
	return 0;
}


static uint32_t create_gem_buffer(int fd, uint64_t size)
{
	int rc;
	struct drm_i915_gem_create gc = {
		.size = size,
	};

	rc = drmIoctl(fd, DRM_IOCTL_I915_GEM_CREATE, &gc);
	assert(rc == 0);
	return gc.handle;
}


static void destroy_gem_buffer(int fd, uint32_t handle)
{
	int rc;
	struct drm_gem_close gc = {
		.handle = handle,
	};

	rc = drmIoctl(fd, DRM_IOCTL_GEM_CLOSE, &gc);
	assert(rc == 0);
}

int ex2()
{
	uint32_t buf_handle[3];
	int fd;
	int i;
	int mode = 0;

	fd = drmOpenWithType("i915", NULL, DRM_NODE_RENDER);
	assert(fd >= 0);

	for(i = 0; i < 3; i++) {
		buf_handle[i] = create_gem_buffer(fd, 4096);
		printf("[create] buf_handle[%x]: %x\n", i, buf_handle[i]);
		if (mode == 0)
			destroy_gem_buffer(fd, buf_handle[i]);
	}

	if (mode == 1) {
		for(i = 0; i < 3; i++) {
			printf("[destroy] buf_handle[%x]: %x\n", i, buf_handle[i]);
			destroy_gem_buffer(fd, buf_handle[i]);
		}
	}

	drmClose(fd);
	return 0;
}

int main(void)
{
	return ex2();
}

