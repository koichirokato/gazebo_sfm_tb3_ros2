#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>
#include <random>

namespace gazebo
{
  class RandomBox : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
    {

      int seed;
      // Store the pointer to the model
      this->model = _parent;
      this->sdf = _sdf;

      sdf::ElementPtr modelElemSeed =
        this->sdf->GetElement("seed");

      std::random_device rnd;
      if (modelElemSeed)
        seed = modelElemSeed->Get<int>() * (this->model->GetId());
      else
        seed = rnd();
    
      std::mt19937 mt(seed);
      std::uniform_int_distribution<> rand100(0,99);

      ignition::math::Vector3d origin = this->sdf->Get<ignition::math::Vector3d>("origin");
      double rx_max = this->sdf->Get<double>("rx");
      double ry_max = this->sdf->Get<double>("ry");

      double rx = rand100(mt)/100.0 * rx_max;
      double ry = rand100(mt)/100.0 * ry_max;
      double t = rand100(mt)/100.0 * 2.0 * M_PI;
      double x = origin.X() + rx * cos(t);
      double y = origin.Y() + ry * sin(t);

      // ignition::math::Pose3d modelPose = this->model->WorldPose();
      // modelPose.Pos().X(x);
      // modelPose.Pos().Y(y);
      // this->model->SetWorldPose(modelPose, false, false);

      gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 10 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("diagonal", 0.0, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(x, y, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;
    sdf::ElementPtr sdf;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(RandomBox)
}
