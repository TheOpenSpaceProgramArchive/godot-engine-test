#ifndef COLORRECT_H
#define COLORRECT_H

#if defined(_WIN32) && defined(_GD_CPP_BINDING_IMPL)
#  define GD_CPP_BINDING_API __declspec(dllexport)
#elif defined(_WIN32)
#  define GD_CPP_BINDING_API __declspec(dllimport)
#else
#  define GD_CPP_BINDING_API
#endif


#include "core/CoreTypes.hpp"

#include <godot.h>



#include "Control.hpp"


namespace godot {



class GD_CPP_BINDING_API ColorRect : public Control {
public:

	void _init();



	void set_frame_color(const Color color);
	Color get_frame_color() const;
};

}
#endif
