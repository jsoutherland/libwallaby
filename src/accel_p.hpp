/*
 * accel_p.hpp
 *
 *  Created on: Dec 31, 2015
 *      Author: Joshua Southerland
 */

#ifndef SRC_ACCEL_P_HPP_
#define SRC_ACCEL_P_HPP_

namespace Private
{

short accel_x(unsigned char * alt_read_buffer = 0);

short accel_y(unsigned char * alt_read_buffer = 0);

short accel_z(unsigned char * alt_read_buffer =  0);

bool accel_calibrate();

bool accel_calibrated(unsigned char * alt_read_buffer = 0);

}

#endif /* SRC_ACCEL_P_HPP_ */
