#ifndef BONEATTACHMENT_H
#define BONEATTACHMENT_H

#if defined(_WIN32) && defined(_GD_CPP_BINDING_IMPL)
#  define GD_CPP_BINDING_API __declspec(dllexport)
#elif defined(_WIN32)
#  define GD_CPP_BINDING_API __declspec(dllimport)
#else
#  define GD_CPP_BINDING_API
#endif


#include "core/CoreTypes.hpp"

#include <godot.h>



#include "Spatial.hpp"


namespace godot {



class GD_CPP_BINDING_API BoneAttachment : public Spatial {
public:

	void _init();



	void set_bone_name(const String bone_name);
	String get_bone_name() const;
};

}
#endif
