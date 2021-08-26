/**
 * @file kdl_fwd_kin_tree_factory.h
 * @brief Tesseract KDL Forward kinematics tree factory.
 *
 * @author Levi Armstrong
 * @date April 15, 2018
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2013, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TESSERACT_KINEMATICS_KDL_FWD_KIN_TREE_FACTORY_H
#define TESSERACT_KINEMATICS_KDL_FWD_KIN_TREE_FACTORY_H

#include <tesseract_kinematics/core/forward_kinematics_tree_factory.h>
#include <tesseract_kinematics/kdl/kdl_fwd_kin_tree.h>

#ifdef SWIG
%shared_ptr(tesseract_kinematics::KDLFwdKinTreeFactory)
#endif  // SWIG

namespace tesseract_kinematics
{
class KDLFwdKinTreeFactory : public FwdKinTreeFactory
{
public:
  const std::string& getName() const override { return KDL_FWD_KIN_TREE_SOLVER_NAME; }

  ForwardKinematics::UPtr create(const std::string& name,
                                 const tesseract_scene_graph::SceneGraph& scene_graph,
                                 const tesseract_scene_graph::SceneState& scene_state,
                                 const std::vector<std::string>& joint_names) const override
  {
    try
    {
      return std::make_unique<KDLFwdKinTree>(name, scene_graph, scene_state, joint_names);
    }
    catch (...)
    {
      return nullptr;
    }
  }
};

}  // namespace tesseract_kinematics
#endif  // TESSERACT_KINEMATICS_KDL_FWD_KIN_TREE_FACTORY_H
