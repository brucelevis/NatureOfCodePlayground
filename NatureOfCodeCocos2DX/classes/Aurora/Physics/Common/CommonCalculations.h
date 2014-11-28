#ifndef NatureOfCodeCocos2DX_CommonCalculations_h
#define NatureOfCodeCocos2DX_CommonCalculations_h



#include "PhysicsConstants.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Physics {


		class CommonCalculations 
		{
		public:
			const static std::function<Aurora::Math::VECTOR2D(const Aurora::Math::VECTOR2D&, float)> NormalEarthGravityCalculations;
			

		};
	}; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora


#endif