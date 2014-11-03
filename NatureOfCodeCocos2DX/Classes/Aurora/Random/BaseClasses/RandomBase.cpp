//
//  RandomBase.cpp
//  NatureOfCodeCocos2DX
//
//  Created by Adrian Simionescu on 08/10/14.
//
//

#include "RandomBase.h"


namespace Aurora {
    namespace Random {
		//-------------------------------------------------------------------------
		// START = Random Base Interfaces
		//-------------------------------------------------------------------------
		IRandomBase::IRandomBase()
		{

		}
		
		IRandomBase::~IRandomBase()
		{

		}

		void IRandomBase::SetRandomNumberMode(RandomNumberMode randomNumberMode)
		{
			this->RandomNumberModeValue = randomNumberMode;
		}

		RandomNumberMode IRandomBase::GetRandomNumberMode() const
		{
			return(this->RandomNumberModeValue);
		}

		IRandomBaseBasic::IRandomBaseBasic() : IRandomBase()
		{

		}

		IRandomBaseBasic::~IRandomBaseBasic()
		{
			IRandomBase::~IRandomBase();
		}

		void IRandomBaseBasic::SetConstrainsRange(const mRECT &areaSize)
		{
			this->areaSize = areaSize;
		}

		const mRECT IRandomBaseBasic::GetConstrainsRange() const
		{
			return(this->areaSize);
		}

		IRandomBaseNormal::IRandomBaseNormal() //: IRandomBaseBasic()
		{

		}

		IRandomBaseNormal::~IRandomBaseNormal()
		{
			//IRandomBaseBasic::~IRandomBaseBasic();
		}

		IRandomBaseUniform::IRandomBaseUniform() //: IRandomBaseBasic()
		{

		}

		IRandomBaseUniform::~IRandomBaseUniform()
		{
			//IRandomBaseBasic::~IRandomBaseBasic();
		}

		IRandomBaseGaussian::IRandomBaseGaussian() //: IRandomBaseBasic()
		{

		}

		IRandomBaseGaussian::~IRandomBaseGaussian()
		{
			//IRandomBaseBasic::~IRandomBaseBasic();
		}

		IRandomBasePerlinNoise::IRandomBasePerlinNoise() //: IRandomBaseBasic()
		{

		}

		IRandomBasePerlinNoise::~IRandomBasePerlinNoise()
		{
			//IRandomBaseBasic::~IRandomBaseBasic();
		}

		IRandomBaseComplete::IRandomBaseComplete() : IRandomBaseUniform(), IRandomBaseGaussian(), IRandomBasePerlinNoise()
		{
			
		}

		IRandomBaseComplete::~IRandomBaseComplete()
		{
			IRandomBaseUniform::~IRandomBaseUniform();
			IRandomBaseGaussian::~IRandomBaseGaussian();
			IRandomBasePerlinNoise::~IRandomBasePerlinNoise();
		}

		//-------------------------------------------------------------------------
		// END = Random Base Interfaces
		//-----------------------------------------------------------------------

        RandomBase::RandomBase() : IRandomBaseBasic()
        {
            this->init();
        }

		RandomBase::RandomBase(const RandomBase &value) : IRandomBaseBasic()
		{
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());
		}

		RandomBase::~RandomBase()
		{
			IRandomBaseBasic::~IRandomBaseBasic();
		}
        
        void RandomBase::Constrain()
        {
			
        }
        
        void RandomBase::DoCalculations()
        {
			this->Constrain();
        }

		RandomBase& RandomBase::operator=(const RandomBase& value)
		{
			if(this == &value) { return(*this); }

			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());

			return(*this);
		}
		void RandomBase::init()
		{
			this->SetConstrainsRange(mRECT(0,0));
			this->SetRandomNumberMode(RandomNumberMode::Normal);
		}


		void RandomBase::init(const mRECT &areaSize, RandomNumberMode randomNumberMode)
		{
			this->SetConstrainsRange(areaSize);
			this->SetRandomNumberMode(randomNumberMode);
		}

		

		RandomBaseComplete::RandomBaseComplete() : RandomBase()
		{
			this->init();
		}

		RandomBaseComplete::RandomBaseComplete(const RandomBaseComplete &value) : RandomBase(value)
		{
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());
		}

		RandomBaseComplete::~RandomBaseComplete()
		{
			RandomBase::~RandomBase();
			IRandomBaseComplete::~IRandomBaseComplete();
		}

		void RandomBaseComplete::DoCalculations()
		{
			RandomBase::DoCalculations();

			switch(this->GetRandomNumberMode())
            {
			case RandomNumberMode::Normal:
				{
					this->NormalCalculations();
				} break;

			case RandomNumberMode::Uniform:
				{
					this->UniformCalculations();
				} break;


			case RandomNumberMode::Gaussian:
				{
					this->GaussianCalculations();
				} break;

			case RandomNumberMode::Perlin:
				{
					this->PerlinNoiseCalculations();
				} break;

			default:
				{
					this->NormalCalculations();
				} break;
			}
  
        
			this->Constrain();
		}

		void RandomBaseComplete::Constrain()
		{
			RandomBase::Constrain();

		}

		void RandomBaseComplete::NormalCalculations()
		{
			
		}

		void RandomBaseComplete::UniformCalculations()
		{

		}

		void RandomBaseComplete::GaussianCalculations()
		{

		}

		void RandomBaseComplete::PerlinNoiseCalculations()
		{

		}

		RandomBaseComplete& RandomBaseComplete::operator=(const RandomBaseComplete& value)
		{
			if(this == &value) { return(*this); }

			RandomBase::operator=(value);
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());

			return(*this);
		}

		void RandomBaseComplete::init()
		{
			RandomBase::init();
			this->SetRandomNumberMode(RandomNumberMode::Normal);
		}

		void RandomBaseComplete::init(const mRECT &areaSize, RandomNumberMode randomNumberMode)
		{
			RandomBase::init(areaSize, randomNumberMode);
		}

		RandomBasePerlinNoise::RandomBasePerlinNoise() : RandomBase()
		{
			this->init();
		}

		RandomBasePerlinNoise::RandomBasePerlinNoise(const RandomBasePerlinNoise &value) : RandomBase(value)
		{
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());
		}

		RandomBasePerlinNoise::~RandomBasePerlinNoise()
		{
			RandomBase::~RandomBase();
			IRandomBasePerlinNoise::~IRandomBasePerlinNoise();
		}

		void RandomBasePerlinNoise::DoCalculations()
		{
			RandomBase::DoCalculations();
			this->PerlinNoiseCalculations();
		}

		void RandomBasePerlinNoise::PerlinNoiseCalculations()
		{

		}

		RandomBasePerlinNoise& RandomBasePerlinNoise::operator=(const RandomBasePerlinNoise& value)
		{
			if(this == &value) { return(*this); }

			RandomBase::operator=(value);
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());

			return(*this);
		}

		void RandomBasePerlinNoise::init()
		{
			RandomBase::init();
			this->SetRandomNumberMode(RandomNumberMode::Perlin);
		}

		void RandomBasePerlinNoise::init(const mRECT &areaSize, RandomNumberMode randomNumberMode)
		{
			RandomBase::init(areaSize, randomNumberMode);
		}

		RandomBaseGaussian::RandomBaseGaussian() : RandomBase()
		{
			this->init();
		}

		RandomBaseGaussian::RandomBaseGaussian(const RandomBaseGaussian &value) : RandomBase(value)
		{
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());
		}

		RandomBaseGaussian::~RandomBaseGaussian()
		{
			RandomBase::~RandomBase();
			IRandomBaseGaussian::~IRandomBaseGaussian();
		}

		void RandomBaseGaussian::DoCalculations()
		{
			RandomBase::DoCalculations();
			this->GaussianCalculations();
		}

		void RandomBaseGaussian::GaussianCalculations()
		{

		}

		RandomBaseGaussian& RandomBaseGaussian::operator=(const RandomBaseGaussian& value)
		{
			if(this == &value) { return(*this); }

			RandomBase::operator=(value);
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());

			return(*this);
		}

		void RandomBaseGaussian::init()
		{
			RandomBase::init();
			this->SetRandomNumberMode(RandomNumberMode::Gaussian);
		}

		void RandomBaseGaussian::init(const mRECT &areaSize, RandomNumberMode randomNumberMode)
		{
			RandomBase::init(areaSize, randomNumberMode);
		}

		RandomBaseUniform::RandomBaseUniform() : RandomBase()
		{
			this->init();
		}

		RandomBaseUniform::RandomBaseUniform(const RandomBaseUniform &value) : RandomBase(value)
		{
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());
		}

		RandomBaseUniform::~RandomBaseUniform()
		{
			RandomBase::~RandomBase();
			IRandomBaseUniform::~IRandomBaseUniform();
		}

		void RandomBaseUniform::DoCalculations()
		{
			RandomBase::DoCalculations();
			this->UniformCalculations();
		}

		void RandomBaseUniform::UniformCalculations()
		{

		}

		RandomBaseUniform& RandomBaseUniform::operator=(const RandomBaseUniform& value)
		{
			if(this == &value) { return(*this); }

			RandomBase::operator=(value);
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());

			return(*this);
		}

		void RandomBaseUniform::init()
		{
			RandomBase::init();
			this->SetRandomNumberMode(RandomNumberMode::Uniform);
		}

		void RandomBaseUniform::init(const mRECT &areaSize, RandomNumberMode randomNumberMode)
		{
			RandomBase::init(areaSize, randomNumberMode);
		}

		RandomBaseNormal::RandomBaseNormal() : RandomBase()
		{
			this->init();
		}

		RandomBaseNormal::RandomBaseNormal(const RandomBaseNormal &value) : RandomBase(value)
		{
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());
		}

		RandomBaseNormal::~RandomBaseNormal()
		{
			RandomBase::~RandomBase();
			IRandomBaseNormal::~IRandomBaseNormal();
		}

		void RandomBaseNormal::DoCalculations()
		{
			RandomBase::DoCalculations();
			this->NormalCalculations();
		}

		void RandomBaseNormal::NormalCalculations()
		{

		}

		RandomBaseNormal& RandomBaseNormal::operator=(const RandomBaseNormal& value)
		{
			if(this == &value) { return(*this); }

			RandomBase::operator=(value);
			this->init(value.GetConstrainsRange(), value.GetRandomNumberMode());

			return(*this);
		}

		void RandomBaseNormal::init()
		{
			RandomBase::init();
			this->SetRandomNumberMode(RandomNumberMode::Normal);
		}

		void RandomBaseNormal::init(const mRECT &areaSize, RandomNumberMode randomNumberMode)
		{
			RandomBase::init(areaSize, randomNumberMode);
		}


    }; // END OF NAMESPACE Random
}; // END OF NAMESPACE Aurora