/*
 * camera.h
 *
 *  Created on: Jan 6, 2016
 *      Author: Nafis Zaman
 */

#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "wallaby/geom.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pixel
{
  int r;
  int g;
  int b;
} pixel;

enum Resolution
{
  LOW_RES,
  MED_RES,
  HIGH_RES,
};

// TODO: Change to camera_connect?
/**
 * Opens the default system camera for use at LOW_RES (160x120).
 * \return 1 on success, 0 on failure
 * \see camera_open_at_res
 * \see camera_open_device
 * \see camera_close
 * \ingroup camera
 */
int camera_open();

/**
 * Opens the default system camera for use at a given resolution.
 * \param res The resolution the camera should operate at. This can be:
 *   - LOW_RES (160x120)
 *   - MED_RES (320x240)
 *   - HIGH_RES (640x480)
 * \return 1 on success, 0 on failure
 * \see camera_open
 * \see camera_open_device
 * \see camera_close
 * \ingroup camera
 */
int camera_open_at_res(enum Resolution res);

/**
 * Opens a camera for use at a given resolution.
 * \param number The camera's id. 0 is the first camera, 1 is the second camera, etc.
 * \param res The resolution the camera should operate at. This can be:
 *   - LOW_RES (160x120)
 *   - MED_RES (320x240)
 *   - HIGH_RES (640x480)
 * \return 1 on success, 0 on failure
 * \see camera_open
 * \see camera_open_at_res
 * \see camera_close
 * \ingroup camera
 */
int camera_open_device(int number, enum Resolution res);

/**
 * Loads the config file specified by name.
 * \param name The configuration to load. Configuration file names are case sensitive.
 * \note You should NOT include the config file extension ".conf" in the name parameter.
 * \return 1 on success, 0 on failure.
 * \ingroup camera
 */
int camera_load_config(const char *name);

/**
 * Sets the camera's x resolution.
 * \param width The width in pixels
 * \ingroup camera
 */
void camera_set_width(int width);

/**
 * Sets the camera's y resolution.
 * \param height The height in pixels
 * \ingroup camera
 */
void camera_set_height(int height);

// TODO: New function?
/**
 * Sets the camera's x and y resolution.
 * \param width The width in pixels
 * \param height The height in pixels
 * \ingroup camera
 */
void camera_set_resolution(int width, int height);

/**
 * Gets the camera's x resolution.
 * \attention This value might be different than the previously set x resolution. Never assume the x resolution.
 * \return The camera's x resolution, in pixels.
 * \ingroup camera
 */
int get_camera_width(void);

/**
 * Gets the camera's y resolution.
 * \attention This value might be different than the previously set y resolution. Never assume the y resolution.
 * \return The camera's y resolution, in pixels.
 * \ingroup camera
 */
int get_camera_height(void);

/**
 * Updates the camera image used for processing.
 * \return 1 on success, 0 on failure.
 * \ingroup camera
 */
int camera_update(void);

/**
 * \param p The point at which the pixel lies.
 * \return The rgb value of the pixel located at point p.
 * \note A (r, g, b) value of (-1, -1, -1) will be returned for points that are out of range.
 * \ingroup camera
 */
pixel get_camera_pixel(point2 p);

/**
 * \return Number of channels in the current configuration.
 * \see get_object_count
 * \ingroup camera
 */
int get_channel_count(void);

/**
 * \param channel The channel to scan for objects.
 * \note Objects are sorted by area, largest first.
 * \return Number of objects in the given channel, -1 if channel doesn't exist.
 * \see get_channel_count
 * \ingroup camera
 */
int get_object_count(int channel);

/**
 * \return The string data associated with a given object on a given channel.
 * If there is no data associated, 0 is returned.
 * \note This data is not guaranteed to be null terminated.
 * \note This string pointer will be invalid after a call to camera_update()
 * \see get_object_data_length
 * \ingroup camera
 */
const char *get_object_data(int channel, int object);

/**
 * \return The data associated with the given channel and object as an integer. If the given channel or object doesn't exist, -1 is returned.
 * \see get_object_data
 */
int get_code_num(int channel, int object);

/**
 * \return The length of the string data associated with a given object on a given channel.
 * If there is no data associated, 0 is returned. If the channel or object is invalid, 0 is returned.
 * \see get_object_data
 * \ingroup camera
 */
int get_object_data_length(int channel, int object);

/**
 * \return The confidence, between 0 and 100, that given object on the given channel is significant.
 * If the channel or object doesn't exist, -1 is returned.
 * \note The confidence the percentage of the object's bounding box that the object occupies.
 * In other words, it is calculated as (blob_area / bbox_area) * 100
 * \ingroup camera
 */
int get_object_confidence(int channel, int object);

/**
 * \return The object's bounding box area. -1 is returned if the channel or object doesn't exist.
 * \ingroup camera
 */
int get_object_area(int channel, int object);

/**
 * \return The bounding box of the given object on the given channel.
 * \ingroup camera
 */
rectangle get_object_bbox(int channel, int object);
int get_object_bbox_ulx(int channel, int object);
int get_object_bbox_uly(int channel, int object);
int get_object_bbox_brx(int channel, int object);
int get_object_bbox_bry(int channel, int object);
int get_object_bbox_width(int channel, int object);
int get_object_bbox_height(int channel, int object);

/**
 * \return The (x, y) centroid of the given object on the given channel.
 * \ingroup camera
 */
point2 get_object_centroid(int channel, int object);
int get_object_centroid_column(int channel, int object);
int get_object_centroid_x(int channel, int object);
int get_object_centroid_row(int channel, int object);
int get_object_centroid_y(int channel, int object);

/**
 * \return The (x, y) center of the given object on the given channel.
 * \ingroup camera
 */
point2 get_object_center(int channel, int object);
int get_object_center_column(int channel, int object);
int get_object_center_x(int channel, int object);
int get_object_center_row(int channel, int object);
int get_object_center_y(int channel, int object);

// TODO: Change to camera_disconnect?
/**
 * Cleanup the current camera instance.
 * \see camera_open
 * \see camera_open_device
 * \ingroup camera
 */
void camera_close();

// TODO: Change to camera_set_config_base_path?
/**
 * Sets the path in which to look for camera configurations.
 * \param path the absolute directory path in which to look for camera configurations.
 * \ingroup camera
 */
void set_camera_config_base_path(const char *const path);

/**
 * Retrieves a row of the current camera frame as a BGR (BGR888) array.
 * \attention The returned pointer is invalid after camera_update() is called again.
 * \param row The number of the row to retrieve.
 * \return a BGR888 row of the current camera frame.
 * \ingroup camera
 */
const unsigned char *get_camera_frame_row(unsigned row);

/**
 * Retrieves the current camera frame as a BGR (BGR888) array.
 * \attention The returned pointer is invalid after camera_update() is called again.
 * \return the current BGR888 camera frame.
 * \ingroup camera
 */
const unsigned char *get_camera_frame();

unsigned get_camera_element_size();

#ifdef __cplusplus
}
#endif


#endif