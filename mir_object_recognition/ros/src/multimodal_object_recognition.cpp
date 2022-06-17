#include "mir_object_recognition/multimodal_object_recognition.hpp"

namespace perception_namespace
{
void MultiModalObjectRecognitionROS::declare_all_parameters()
{

    rcl_interfaces::msg::ParameterDescriptor descriptor1;
    descriptor1.description = "The size of a leaf (on x,y,z) used for downsampling.";
    rcl_interfaces::msg::FloatingPointRange range1;
    range1.set__from_value(0.0).set__to_value(1.0);
    descriptor1.floating_point_range = {range1};
    this->declare_parameter("voxel_leaf_size", 0.009, descriptor1);

    rcl_interfaces::msg::ParameterDescriptor descriptor2;
    descriptor2.description = "The field name used for filtering";
    this->declare_parameter("voxel_filter_field_name", "z", descriptor2);

    rcl_interfaces::msg::ParameterDescriptor descriptor3;
    descriptor3.description = "The minimum allowed field value a point will be considered from";
    rcl_interfaces::msg::FloatingPointRange range3;
    range3.set__from_value(-10.0).set__to_value(10.0);
    descriptor3.floating_point_range = {range3};
    this->declare_parameter("voxel_filter_limit_min", -0.15, descriptor3);

    rcl_interfaces::msg::ParameterDescriptor descriptor4;
    descriptor4.description = "The maximum allowed field value a point will be considered from";
    rcl_interfaces::msg::FloatingPointRange range4;
    range4.set__from_value(-10.0).set__to_value(10.0);
    descriptor4.floating_point_range = {range4};
    this->declare_parameter("voxel_filter_limit_max", 0.3, descriptor4);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor5;
    descriptor5.description = "Enable passthrough filter";
    this->declare_parameter("enable_passthrough_filter", false, descriptor5);

    rcl_interfaces::msg::ParameterDescriptor descriptor6;
    descriptor6.description = "The field name used for filtering";
    this->declare_parameter("passthrough_filter_field_name", "x", descriptor6);

    rcl_interfaces::msg::ParameterDescriptor descriptor7;
    descriptor7.description = "The minimum allowed field value a point will be considered from";
    rcl_interfaces::msg::FloatingPointRange range7;
    range7.set__from_value(-10.0).set__to_value(10.0);
    descriptor7.floating_point_range = {range7};
    this->declare_parameter("passthrough_filter_limit_min", 0.0, descriptor7);

    rcl_interfaces::msg::ParameterDescriptor descriptor8;
    descriptor8.description = "The maximum allowed field value a point will be considered from";
    rcl_interfaces::msg::FloatingPointRange range8;
    range8.set__from_value(-10.0).set__to_value(10.0);
    descriptor8.floating_point_range = {range8};
    this->declare_parameter("passthrough_filter_limit_max", 0.8, descriptor8);

    rcl_interfaces::msg::ParameterDescriptor descr_passthrough_filter_field_y;
    descr_passthrough_filter_field_y.description = "The field name used for filtering";
    this->declare_parameter("passthrough_filter_field_y", "y", descr_passthrough_filter_field_y);

    rcl_interfaces::msg::ParameterDescriptor descr_passthrough_filter_lim_min;
    descr_passthrough_filter_lim_min.description = "The minimum allowed field value a point will be considered from";
    rcl_interfaces::msg::FloatingPointRange range_passthrough_filter_lim_min;
    range_passthrough_filter_lim_min.set__from_value(-10.0).set__to_value(10.0);
    descr_passthrough_filter_lim_min.floating_point_range = {range_passthrough_filter_lim_min};
    this->declare_parameter("passthrough_filter_y_limit_min", -0.5, descr_passthrough_filter_lim_min);

    rcl_interfaces::msg::ParameterDescriptor descr_passthrough_filter_lim_max;
    descr_passthrough_filter_lim_max.description = "The maximum allowed field value a point will be considered from";
    rcl_interfaces::msg::FloatingPointRange range_passthrough_filter_lim_max;
    range_passthrough_filter_lim_max.set__from_value(-10.0).set__to_value(10.0);
    descr_passthrough_filter_lim_max.floating_point_range = {range_passthrough_filter_lim_max};
    this->declare_parameter("passthrough_filter_y_limit_max", 0.8, descr_passthrough_filter_lim_max);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor9;
    descriptor9.description = "Sphere radius for nearest neighbor search";
    rcl_interfaces::msg::FloatingPointRange range9;
    range9.set__from_value(0.0).set__to_value(0.5);
    descriptor9.floating_point_range = {range9};
    this->declare_parameter("normal_radius_search", 0.03, descriptor9);

    rcl_interfaces::msg::ParameterDescriptor descriptor10;
    descriptor10.description = "Use Open MP to estimate normal";
    this->declare_parameter("use_omp", false, descriptor10);

    rcl_interfaces::msg::ParameterDescriptor descriptor11;
    descriptor11.description = "The number of cores to use for OMP normal estimation";
    rcl_interfaces::msg::IntegerRange range11;
    range11.set__from_value(1).set__to_value(16);
    descriptor11.integer_range = {range11};
    this->declare_parameter("num_cores", 8, descriptor11);

    rcl_interfaces::msg::ParameterDescriptor descriptor12;
    descriptor12.description = "The maximum number of iterations the algorithm will run for";
    rcl_interfaces::msg::IntegerRange range12;
    range12.set__from_value(0).set__to_value(100000);
    descriptor12.integer_range = {range12};
    this->declare_parameter("sac_max_iterations", 1000, descriptor12);

    rcl_interfaces::msg::ParameterDescriptor descriptor13;
    descriptor13.description = "The distance to model threshold";
    rcl_interfaces::msg::FloatingPointRange range13;
    range13.set__from_value(0.0).set__to_value(1.0);
    descriptor13.floating_point_range = {range13};
    this->declare_parameter("sac_distance_threshold", 0.01, descriptor13);

    rcl_interfaces::msg::ParameterDescriptor descriptor14;
    descriptor14.description = "Model coefficient refinement";
    this->declare_parameter("sac_optimize_coefficients", true, descriptor14);

    rcl_interfaces::msg::ParameterDescriptor descriptor15;
    descriptor15.description = "The x axis to which the plane should be perpendicular, the eps angle > 0 to activate axis-angle constraint";
    rcl_interfaces::msg::FloatingPointRange range15;
    range15.set__from_value(0.0).set__to_value(1.0);
    descriptor15.floating_point_range = {range15};
    this->declare_parameter("sac_x_axis", 0.0, descriptor15);

    rcl_interfaces::msg::ParameterDescriptor descriptor16;
    descriptor16.description = "The y axis to which the plane should be perpendicular, the eps angle > 0 to activate axis-angle constraint";
    rcl_interfaces::msg::FloatingPointRange range16;
    range16.set__from_value(0.0).set__to_value(1.0);
    descriptor16.floating_point_range = {range16};
    this->declare_parameter("sac_y_axis", 0.0, descriptor16);

    rcl_interfaces::msg::ParameterDescriptor descriptor17;
    descriptor17.description = "The z axis to which the plane should be perpendicular, the eps angle > 0 to activate axis-angle constraint";
    rcl_interfaces::msg::FloatingPointRange range17;
    range17.set__from_value(0.0).set__to_value(1.0);
    descriptor17.floating_point_range = {range17};
    this->declare_parameter("sac_z_axis", 1.0, descriptor17);

    rcl_interfaces::msg::ParameterDescriptor descriptor18;
    descriptor18.description = "The maximum allowed difference between the model normal and the given axis in radians.";
    rcl_interfaces::msg::FloatingPointRange range18;
    range18.set__from_value(0.0).set__to_value(1.5707);
    descriptor18.floating_point_range = {range18};
    this->declare_parameter("sac_eps_angle", 0.09, descriptor18);

    rcl_interfaces::msg::ParameterDescriptor descriptor19;
    descriptor19.description = "The relative weight (between 0 and 1) to give to the angular distance (0 to pi/2) between point normals and the plane normal.";
    rcl_interfaces::msg::FloatingPointRange range19;
    range19.set__from_value(0.0).set__to_value(1.0);
    descriptor19.floating_point_range = {range19};
    this->declare_parameter("sac_normal_distance_weight", 0.05, descriptor19);

    rcl_interfaces::msg::ParameterDescriptor descriptor20;
    descriptor20.description = "The minimum height above the plane from which to construct the polygonal prism";
    rcl_interfaces::msg::FloatingPointRange range20;
    range20.set__from_value(0.0).set__to_value(5.0);
    descriptor20.floating_point_range = {range20};
    this->declare_parameter("prism_min_height", 0.01, descriptor20);

    rcl_interfaces::msg::ParameterDescriptor descriptor21;
    descriptor21.description = "The maximum height above the plane from which to construct the polygonal prism";
    rcl_interfaces::msg::FloatingPointRange range21;
    range21.set__from_value(0.0).set__to_value(5.0);
    descriptor21.floating_point_range = {range21};
    this->declare_parameter("prism_max_height", 0.1, descriptor21);

    rcl_interfaces::msg::ParameterDescriptor descriptor22;
    descriptor22.description = "Radius of the sphere that will determine which points are neighbors.";
    rcl_interfaces::msg::FloatingPointRange range22;
    range22.set__from_value(0.0).set__to_value(10.0);
    descriptor22.floating_point_range = {range22};
    this->declare_parameter("outlier_radius_search", 0.03, descriptor22);

    rcl_interfaces::msg::ParameterDescriptor descriptor23;
    descriptor23.description = "The number of neighbors that need to be present in order to be classified as an inlier.";
    rcl_interfaces::msg::IntegerRange range23;
    range23.set__from_value(0).set__to_value(1000);
    descriptor23.integer_range = {range23};
    this->declare_parameter("outlier_min_neighbors", 20, descriptor23);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor24;
    descriptor24.description = "The spatial tolerance as a measure in the L2 Euclidean space";
    rcl_interfaces::msg::FloatingPointRange range24;
    range24.set__from_value(0.0).set__to_value(2.0);
    descriptor24.floating_point_range = {range24};
    this->declare_parameter("cluster_tolerance", 0.02, descriptor24);

    rcl_interfaces::msg::ParameterDescriptor descriptor25;
    descriptor25.description = "The minimum number of points that a cluster must contain in order to be accepted";
    rcl_interfaces::msg::IntegerRange range25;
    range25.set__from_value(0).set__to_value(1000);
    descriptor25.integer_range = {range25};
    this->declare_parameter("cluster_min_size", 25, descriptor25);

    rcl_interfaces::msg::ParameterDescriptor descriptor26;
    descriptor26.description = "The maximum number of points that a cluster must contain in order to be accepted";
    rcl_interfaces::msg::IntegerRange range26;
    range26.set__from_value(0).set__to_value(2147483647);
    descriptor26.integer_range = {range26};
    this->declare_parameter("cluster_max_size", 20000, descriptor26);

    rcl_interfaces::msg::ParameterDescriptor descriptor27;
    descriptor27.description = "The minimum height of the cluster above the given polygon";
    rcl_interfaces::msg::FloatingPointRange range27;
    range27.set__from_value(0.0).set__to_value(5.0);
    descriptor27.floating_point_range = {range27};
    this->declare_parameter("cluster_min_height", 0.011, descriptor27);

    rcl_interfaces::msg::ParameterDescriptor descriptor28;
    descriptor28.description = "The maximum height of the cluster above the given polygon";
    rcl_interfaces::msg::FloatingPointRange range28;
    range28.set__from_value(0.0).set__to_value(5.0);
    descriptor28.floating_point_range = {range28};
    this->declare_parameter("cluster_max_height", 0.09, descriptor28);

    rcl_interfaces::msg::ParameterDescriptor descriptor29;
    descriptor29.description = "The maximum length of the cluster";
    rcl_interfaces::msg::FloatingPointRange range29;
    range29.set__from_value(0.0).set__to_value(5.0);
    descriptor29.floating_point_range = {range29};
    this->declare_parameter("cluster_max_length", 0.25, descriptor29);

    rcl_interfaces::msg::ParameterDescriptor descriptor30;
    descriptor30.description = "The minimum height of the cluster above the given polygon";
    rcl_interfaces::msg::FloatingPointRange range30;
    range30.set__from_value(0.0).set__to_value(5.0);
    descriptor30.floating_point_range = {range30};
    this->declare_parameter("cluster_min_distance_to_polygon", 0.04, descriptor30);

    rcl_interfaces::msg::ParameterDescriptor descriptor31;
    descriptor31.description = "Center cluster";
    this->declare_parameter("center_cluster", false, descriptor31);

    rcl_interfaces::msg::ParameterDescriptor descriptor32;
    descriptor32.description = "Pad cluster so that it has the same size";
    this->declare_parameter("pad_cluster", true, descriptor32);

    rcl_interfaces::msg::ParameterDescriptor descriptor33;
    descriptor33.description = "The size of the padded cluster";
    rcl_interfaces::msg::IntegerRange range33;
    range33.set__from_value(128).set__to_value(4096);
    descriptor33.integer_range = {range33};
    this->declare_parameter("padded_cluster_size", 2048, descriptor33);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor34;
    descriptor34.description = "The height of the object above the workspace";
    rcl_interfaces::msg::FloatingPointRange range34;
    range34.set__from_value(0.0).set__to_value(2.0);
    descriptor34.floating_point_range = {range34};
    this->declare_parameter("object_height_above_workspace", 0.022, descriptor34);

    rcl_interfaces::msg::ParameterDescriptor descriptor35;
    descriptor35.description = "The height of the container pose";
    rcl_interfaces::msg::FloatingPointRange range35;
    range35.set__from_value(0.0).set__to_value(2.0);
    descriptor35.floating_point_range = {range35};
    this->declare_parameter("container_height", 0.07, descriptor35);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor36;
    descriptor36.description = "RGB bounding box/ROI adjustment in pixel";
    rcl_interfaces::msg::IntegerRange range36;
    range36.set__from_value(0).set__to_value(50);
    descriptor36.integer_range = {range36};
    this->declare_parameter("rgb_roi_adjustment", 2, descriptor36);

    rcl_interfaces::msg::ParameterDescriptor descriptor37;
    descriptor37.description = "Allowed RGB bounding box min diagonal";
    rcl_interfaces::msg::IntegerRange range37;
    range37.set__from_value(0).set__to_value(500);
    descriptor37.integer_range = {range37};
    this->declare_parameter("rgb_bbox_min_diag", 21, descriptor37);

    rcl_interfaces::msg::ParameterDescriptor descriptor38;
    descriptor38.description = "Allowed RGB bounding box max diagonal";
    rcl_interfaces::msg::IntegerRange range38;
    range38.set__from_value(0).set__to_value(500);
    descriptor38.integer_range = {range38};
    this->declare_parameter("rgb_bbox_max_diag", 175, descriptor38);

    rcl_interfaces::msg::ParameterDescriptor descriptor39;
    descriptor39.description = "Passthrough filter min for the generated pc from rgb proposal";
    rcl_interfaces::msg::FloatingPointRange range39;
    range39.set__from_value(-1.0).set__to_value(1.0);
    descriptor39.floating_point_range = {range39};
    this->declare_parameter("rgb_cluster_filter_limit_min", 0.0060, descriptor39);

    rcl_interfaces::msg::ParameterDescriptor descriptor40;
    descriptor40.description = "Passthrough filter max for the generated pc from rgb proposal";
    rcl_interfaces::msg::FloatingPointRange range40;
    range40.set__from_value(-1.0).set__to_value(1.0);
    descriptor40.floating_point_range = {range40};
    this->declare_parameter("rgb_cluster_filter_limit_max", 0.35, descriptor40);

    rcl_interfaces::msg::ParameterDescriptor descriptor41;
    descriptor41.description = "Remove cloud cluster generated from RGB ROI";
    this->declare_parameter("rgb_cluster_remove_outliers", true, descriptor41);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor42;
    descriptor42.description = "Enable ROI filter";
    this->declare_parameter("enable_roi", true, descriptor42);

    rcl_interfaces::msg::ParameterDescriptor descriptor43;
    descriptor43.description = "Base link to laser distance";
    rcl_interfaces::msg::FloatingPointRange range43;
    range43.set__from_value(0.0).set__to_value(1.0);
    descriptor43.floating_point_range = {range43};
    this->declare_parameter("roi_base_link_to_laser_distance", 0.350, descriptor43);

    rcl_interfaces::msg::ParameterDescriptor descriptor44;
    descriptor44.description = "Max object pose x distance to base link";
    rcl_interfaces::msg::FloatingPointRange range44;
    range44.set__from_value(0.0).set__to_value(2.0);
    descriptor44.floating_point_range = {range44};
    this->declare_parameter("roi_max_object_pose_x_to_base_link", 0.700, descriptor44);

    rcl_interfaces::msg::ParameterDescriptor descriptor45;
    descriptor45.description = "Min height of objects";
    rcl_interfaces::msg::FloatingPointRange range45;
    range45.set__from_value(0.0).set__to_value(1.0);
    descriptor45.floating_point_range = {range45};
    this->declare_parameter("roi_min_bbox_z", 0.03, descriptor45);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rcl_interfaces::msg::ParameterDescriptor descriptor46;
    descriptor46.description = "Enable rgb object detection and recognition";
    this->declare_parameter("enable_rgb_recognizer", true, descriptor46);

    rcl_interfaces::msg::ParameterDescriptor descriptor47;
    descriptor47.description = "Enable pointcloud object detection and recognition";
    this->declare_parameter("enable_pc_recognizer", true, descriptor47);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    rcl_interfaces::msg::ParameterDescriptor descriptor48;
    descriptor48.description = "Octree resolution";
    rcl_interfaces::msg::FloatingPointRange range48;
    range48.set__from_value(0.0).set__to_value(2.0);
    descriptor48.floating_point_range = {range48};
    this->declare_parameter("octree_resolution", 0.0025, descriptor48);
}

void MultiModalObjectRecognitionROS::get_all_parameters()
{
    this->get_parameter("voxel_leaf_size", voxel_leaf_size_);
    this->get_parameter("voxel_filter_field_name", voxel_filter_field_name_);
    this->get_parameter("voxel_filter_limit_min", voxel_filter_limit_min_);
    this->get_parameter("voxel_filter_limit_max", voxel_filter_limit_max_);
    this->get_parameter("enable_passthrough_filter", enable_passthrough_filter_);
    this->get_parameter("passthrough_filter_field_name", passthrough_filter_field_name_);
    this->get_parameter("passthrough_filter_limit_min", passthrough_filter_limit_min_);
    this->get_parameter("passthrough_filter_field_y", passthrough_filter_field_y_);
    this->get_parameter("passthrough_filter_limit_max", passthrough_filter_y_limit_max_);
    this->get_parameter("passthrough_filter_y_limit_min", passthrough_filter_y_limit_min_);
    this->get_parameter("passthrough_filter_y_limit_max", passthrough_filter_limit_max_);
    this->get_parameter("normal_radius_search", normal_radius_search_);
    this->get_parameter("use_omp", use_omp_);
    this->get_parameter("num_cores", num_cores_);
    this->get_parameter("sac_max_iterations", sac_max_iterations_);
    this->get_parameter("sac_distance_threshold", sac_distance_threshold_);
    this->get_parameter("sac_optimize_coefficients", sac_optimize_coefficients_);
    this->get_parameter("sac_x_axis", sac_x_axis_);
    this->get_parameter("sac_y_axis", sac_y_axis_);
    this->get_parameter("sac_z_axis", sac_z_axis_);
    this->get_parameter("sac_eps_angle", sac_eps_angle_);
    this->get_parameter("sac_normal_distance_weight", sac_normal_distance_weight_);
    this->get_parameter("prism_min_height", prism_min_height_);
    this->get_parameter("prism_max_height", prism_max_height_);
    this->get_parameter("outlier_radius_search", outlier_radius_search_);
    this->get_parameter("outlier_min_neighbors", outlier_min_neighbors_);
    this->get_parameter("cluster_tolerance", cluster_tolerance_);
    this->get_parameter("cluster_min_size", cluster_min_size_);
    this->get_parameter("cluster_max_size", cluster_max_size_);
    this->get_parameter("cluster_min_height", cluster_min_height_);
    this->get_parameter("cluster_max_height", cluster_max_height_);
    this->get_parameter("cluster_max_length", cluster_max_length_);
    this->get_parameter("cluster_min_distance_to_polygon", cluster_min_distance_to_polygon_);
    this->get_parameter("center_cluster", center_cluster_);
    this->get_parameter("pad_cluster", pad_cluster_);
    this->get_parameter("padded_cluster_size", padded_cluster_size_);
    this->get_parameter("octree_resolution", octree_resolution_);
    this->get_parameter("object_height_above_workspace", object_height_above_workspace_);
    this->get_parameter("container_height", container_height_);
    this->get_parameter("enable_rgb_recognizer", enable_rgb_recognizer_);
    this->get_parameter("enable_pc_recognizer", enable_pc_recognizer_);
    this->get_parameter("rgb_roi_adjustment", rgb_roi_adjustment_);
    this->get_parameter("rgb_bbox_min_diag", rgb_bbox_min_diag_);
    this->get_parameter("rgb_bbox_max_diag", rgb_bbox_max_diag_);
    this->get_parameter("rgb_cluster_filter_limit_min", rgb_cluster_filter_limit_min_);
    this->get_parameter("rgb_cluster_filter_limit_max", rgb_cluster_filter_limit_max_);
    this->get_parameter("rgb_cluster_remove_outliers", rgb_cluster_remove_outliers_);
    this->get_parameter("enable_roi", enable_roi_);
    this->get_parameter("roi_base_link_to_laser_distance", roi_base_link_to_laser_distance_);
    this->get_parameter("roi_max_object_pose_x_to_base_link", roi_max_object_pose_x_to_base_link_);
    this->get_parameter("roi_min_bbox_z", roi_min_bbox_z_);

    scene_segmentation_ros_->setVoxelGridParams(voxel_leaf_size_, voxel_filter_field_name_,
        voxel_filter_limit_min_, voxel_filter_limit_max_);
    scene_segmentation_ros_->setPassthroughParams(enable_passthrough_filter_,
        passthrough_filter_field_name_, 
        passthrough_filter_limit_min_,
        passthrough_filter_limit_max_,
        passthrough_filter_field_y_,
        passthrough_filter_y_limit_min_,
        passthrough_filter_y_limit_max_);
    scene_segmentation_ros_->setNormalParams(normal_radius_search_, use_omp_, num_cores_);
    Eigen::Vector3f axis(sac_x_axis_, sac_y_axis_, sac_z_axis_);
    scene_segmentation_ros_->setSACParams(sac_max_iterations_, sac_distance_threshold_,
        sac_optimize_coefficients_, axis, sac_eps_angle_,
        sac_normal_distance_weight_);
    scene_segmentation_ros_->setPrismParams(prism_min_height_, prism_max_height_);
    scene_segmentation_ros_->setOutlierParams(outlier_radius_search_, outlier_min_neighbors_);
    scene_segmentation_ros_->setClusterParams(cluster_tolerance_, cluster_min_size_, cluster_max_size_,
        cluster_min_height_, cluster_max_height_, cluster_max_length_,
        cluster_min_distance_to_polygon_);

}

rcl_interfaces::msg::SetParametersResult
MultiModalObjectRecognitionROS::parametersCallback(
    const std::vector<rclcpp::Parameter> &parameters)
{
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "success";
    RCLCPP_INFO(this->get_logger(), "Hello from callback");
    
    for (const auto &param : parameters)
    {
        RCLCPP_INFO(this->get_logger(), "%s", param.get_name().c_str());
        RCLCPP_INFO(this->get_logger(), "%s", param.value_to_string().c_str());
        if (param.get_name() == "voxel_leaf_size")
        {
            this->voxel_leaf_size_ = param.get_value<double>();
        }
        if (param.get_name() == "voxel_filter_field_name")
        {
            this->voxel_filter_field_name_ = param.get_value<std::string>();
        }
        if (param.get_name() == "voxel_filter_limit_min")
        {
            this->voxel_filter_limit_min_ = param.get_value<double>();
        }
        if (param.get_name() == "voxel_filter_limit_max")
        {
            this->voxel_filter_limit_max_ = param.get_value<double>();
        }
        if (param.get_name() == "enable_passthrough_filter")
        {
            this->enable_passthrough_filter_ = param.get_value<bool>();
        }
        if (param.get_name() == "passthrough_filter_field_name")
        {
            this->passthrough_filter_field_name_ = param.get_value<std::string>();
        }
        if (param.get_name() == "passthrough_filter_limit_min")
        {
            this->passthrough_filter_limit_min_ = param.get_value<double>();
        }
        if (param.get_name() == "passthrough_filter_limit_max")
        {
            this->passthrough_filter_limit_max_ = param.get_value<double>();
        }
        if (param.get_name() == "passthrough_filter_field_y")
        {
            this->passthrough_filter_field_y_ = param.get_value<std::string>();
        }
        if (param.get_name() == "passthrough_filter_y_limit_min")
        {
            this->passthrough_filter_y_limit_min_ = param.get_value<double>();
        }
        if (param.get_name() == "passthrough_filter_y_limit_max")
        {
            this->passthrough_filter_y_limit_max_ = param.get_value<double>();
        }
        if (param.get_name() == "normal_radius_search")
        {
            this->normal_radius_search_ = param.get_value<double>();
        }
        if (param.get_name() == "use_omp")
        {
            this->use_omp_ = param.get_value<bool>();
        }
        if (param.get_name() == "num_cores")
        {
            this->num_cores_ = param.get_value<int>();
        }
        if (param.get_name() == "sac_max_iterations")
        {
            this->sac_max_iterations_ = param.get_value<int>();
        }
        if (param.get_name() == "sac_distance_threshold")
        {
            this->sac_distance_threshold_ = param.get_value<double>();
        }
        if (param.get_name() == "sac_optimize_coefficients")
        {
            this->sac_optimize_coefficients_ = param.get_value<bool>();
        }
        if (param.get_name() == "sac_x_axis")
        {
            this->sac_x_axis_ = param.get_value<bool>();
        }
        if (param.get_name() == "sac_y_axis")
        {
            this->sac_y_axis_ = param.get_value<bool>();
        }
        if (param.get_name() == "sac_z_axis")
        {
            this->sac_z_axis_ = param.get_value<bool>();
        }
        if (param.get_name() == "sac_eps_angle")
        {
            this->sac_eps_angle_ = param.get_value<double>();
        }
        if (param.get_name() == "sac_normal_distance_weight")
        {
            this->sac_normal_distance_weight_ = param.get_value<double>();
        }
        if (param.get_name() == "prism_min_height")
        {
            this->prism_min_height_ = param.get_value<double>();
        }
        if (param.get_name() == "prism_max_height")
        {
            this->prism_max_height_ = param.get_value<double>();
        }
        if (param.get_name() == "outlier_radius_search")
        {
            this->outlier_radius_search_ = param.get_value<double>();
        }
        if (param.get_name() == "outlier_min_neighbors")
        {
            this->outlier_min_neighbors_ = param.get_value<double>();
        }
        if (param.get_name() == "cluster_tolerance")
        {
            this->cluster_tolerance_ = param.get_value<double>();
        }
        if (param.get_name() == "cluster_min_size")
        {
            this->cluster_min_size_ = param.get_value<int>();
        }
        if (param.get_name() == "cluster_max_size")
        {
            this->cluster_max_size_ = param.get_value<int>();
        }
        if (param.get_name() == "cluster_min_height")
        {
            this->cluster_min_height_ = param.get_value<double>();
        }
        if (param.get_name() == "cluster_max_height")
        {
            this->cluster_max_height_ = param.get_value<double>();
        }
        if (param.get_name() == "cluster_max_length")
        {
            this->cluster_max_length_ = param.get_value<double>();
        }
        if (param.get_name() == "cluster_min_distance_to_polygon")
        {
            this->cluster_min_distance_to_polygon_ = param.get_value<double>();
        }
        if (param.get_name() == "center_cluster")
        {
            this->center_cluster_ = param.get_value<bool>();
        }
        if (param.get_name() == "pad_cluster")
        {
            this->pad_cluster_ = param.get_value<bool>();
        }
        if (param.get_name() == "padded_cluster_size")
        {
            this->padded_cluster_size_ = param.get_value<int>();
        }
        if (param.get_name() == "octree_resolution")
        {
            this->octree_resolution_ = param.get_value<double>();
        }
        if (param.get_name() == "object_height_above_workspace")
        {
            this->object_height_above_workspace_ = param.get_value<double>();
        }
        if (param.get_name() == "container_height")
        {
            this->container_height_ = param.get_value<double>();
        }
        if (param.get_name() == "enable_rgb_recognizer")
        {
            this->enable_rgb_recognizer_ = param.get_value<bool>();
        }
        if (param.get_name() == "enable_pc_recognizer")
        {
            this->enable_pc_recognizer_ = param.get_value<bool>();
        }
        if (param.get_name() == "rgb_roi_adjustment")
        {
            this->rgb_roi_adjustment_ = param.get_value<int>();
        }
        if (param.get_name() == "rgb_bbox_min_diag")
        {
            this->rgb_bbox_min_diag_ = param.get_value<int>();
        }
        if (param.get_name() == "rgb_bbox_max_diag")
        {
            this->rgb_bbox_max_diag_ = param.get_value<int>();
        }
        if (param.get_name() == "rgb_cluster_filter_limit_min")
        {
            this->rgb_cluster_filter_limit_min_ = param.get_value<double>();
        }
        if (param.get_name() == "rgb_cluster_filter_limit_max")
        {
            this->rgb_cluster_filter_limit_max_ = param.get_value<double>();
        }
        if (param.get_name() == "rgb_cluster_remove_outliers")
        {
            this->rgb_cluster_remove_outliers_ = param.get_value<bool>();
        }
        if (param.get_name() == "enable_roi")
        {
            this->enable_roi_ = param.get_value<bool>();
        }
        if (param.get_name() == "roi_base_link_to_laser_distance")
        {
            this->roi_base_link_to_laser_distance_ = param.get_value<double>();
        }
        if (param.get_name() == "roi_max_object_pose_x_to_base_link")
        {
            this->roi_max_object_pose_x_to_base_link_ = param.get_value<double>();
        }
        if (param.get_name() == "roi_min_bbox_z")
        {
            this->roi_min_bbox_z_ = param.get_value<double>();
        }
    }
    
    scene_segmentation_ros_->setVoxelGridParams(voxel_leaf_size_, voxel_filter_field_name_,
        voxel_filter_limit_min_, voxel_filter_limit_max_);
    scene_segmentation_ros_->setPassthroughParams(enable_passthrough_filter_,
        passthrough_filter_field_name_, 
        passthrough_filter_limit_min_,
        passthrough_filter_limit_max_,
        passthrough_filter_field_y_,
        passthrough_filter_y_limit_min_,
        passthrough_filter_y_limit_max_);
    scene_segmentation_ros_->setNormalParams(normal_radius_search_, use_omp_, num_cores_);
    Eigen::Vector3f axis(sac_x_axis_, sac_y_axis_, sac_z_axis_);
    scene_segmentation_ros_->setSACParams(sac_max_iterations_, sac_distance_threshold_,
        sac_optimize_coefficients_, axis, sac_eps_angle_,
        sac_normal_distance_weight_);
    scene_segmentation_ros_->setPrismParams(prism_min_height_, prism_max_height_);
    scene_segmentation_ros_->setOutlierParams(outlier_radius_search_, outlier_min_neighbors_);
    scene_segmentation_ros_->setClusterParams(cluster_tolerance_, cluster_min_size_, cluster_max_size_,
        cluster_min_height_, cluster_max_height_, cluster_max_length_,
        cluster_min_distance_to_polygon_);

    return result;
}


MultiModalObjectRecognitionROS::MultiModalObjectRecognitionROS(const rclcpp::NodeOptions& options) : 
                    rclcpp_lifecycle::LifecycleNode("mmor_node",options),
// MultiModalObjectRecognitionROS::MultiModalObjectRecognitionROS(const std::string &node_name, bool intra_process_comms) : 
//                     rclcpp_lifecycle::LifecycleNode(node_name,
//                     rclcpp::NodeOptions().use_intra_process_comms(intra_process_comms)),
                    bounding_box_visualizer_pc_("output/bounding_boxes", Color(Color::IVORY)),
                    cluster_visualizer_rgb_("output/tabletop_cluster_rgb", true),
                    cluster_visualizer_pc_("output/tabletop_cluster_pc"),
                    label_visualizer_rgb_("output/rgb_labels", Color(Color::SEA_GREEN)),
                    label_visualizer_pc_("output/pc_labels", Color(Color::IVORY))

{
    RCLCPP_INFO(get_logger(), "constructor called");
    this->declare_parameter<std::string>("target_frame_id", "base_link");
    this->get_parameter("target_frame_id", target_frame_id_);
    this->declare_parameter<bool>("debug_mode_", false);
    this->get_parameter("debug_mode_", debug_mode_);
    this->declare_parameter<std::string>("logdir", "/tmp/");
    this->get_parameter("logdir", logdir_);
    scene_segmentation_ros_ = SceneSegmentationROSSPtr(new SceneSegmentationROS());
  
    MultiModalObjectRecognitionROS::declare_all_parameters();
    object_info_path_ = "mir_object_recognition/ros/config/objects.yaml";
}

void MultiModalObjectRecognitionROS::synchronizeCallback(const std::shared_ptr<sensor_msgs::msg::Image> &image,
                                                         const std::shared_ptr<sensor_msgs::msg::PointCloud2> &cloud)
{

    RCLCPP_INFO(get_logger(), "synchro callback");
    RCLCPP_INFO(get_logger(), "TS: [%u]; [%u]", image->header.stamp.sec, cloud->header.stamp.sec);
    // sensor_msgs::msg::PointCloud2 transformed_msg;
    // this->preprocessPointCloud(tf_listener_, tf_buffer_, target_frame_id_, cloud, transformed_msg);
    this->preprocessPointCloud(cloud);
}

bool MultiModalObjectRecognitionROS::preprocessPointCloud(const std::shared_ptr<sensor_msgs::msg::PointCloud2> &cloud_msg)
{
    RCLCPP_INFO(get_logger(), "preprocess point cloud");
    sensor_msgs::msg::PointCloud2 msg_transformed;
    msg_transformed.header.frame_id = target_frame_id_;
    if (!mpu::pointcloud::transformPointCloudMsg(tf_buffer_, target_frame_id_, *cloud_msg, msg_transformed))
    {
        RCLCPP_ERROR(this->get_logger(),"Unable to transform pointcloud. Are you sure target_frame_id_ and pointcloud_source_frame_id are set correctly?");
        RCLCPP_ERROR(this->get_logger(),"pointcloud_source_frame_id: %s, target_frame_id: %s", pointcloud_source_frame_id_.c_str(), target_frame_id_.c_str());
        RCLCPP_ERROR(this->get_logger(),"pointcloud_source_frame_id may need to be arm_cam3d_camera_color_frame or fixed_camera_link");
        RCLCPP_ERROR(this->get_logger(),"target_frame_id may need to be base_link or base_link_static");
        return false;
    }
    std::shared_ptr<pcl::PCLPointCloud2> pc2 = std::make_shared<pcl::PCLPointCloud2>();
    pcl_conversions::toPCL(msg_transformed, *pc2);
    pc2->header.frame_id = msg_transformed.header.frame_id;

    cloud_ = PointCloudBSPtr(new PointCloud);
    pcl::fromPCLPointCloud2(*pc2, *cloud_);

    RCLCPP_INFO(get_logger(), "Point cloud transformed.");
    return true;
}

void MultiModalObjectRecognitionROS::publishDebug(mas_perception_msgs::msg::ObjectList &combined_object_list,
                                                std::vector<PointCloud::Ptr> &clusters_3d,
                                                std::vector<PointCloud::Ptr> &clusters_2d)
{
    RCLCPP_INFO(this->get_logger(), "Inside the publish debug function");
    RCLCPP_INFO_STREAM(this->get_logger(), "Cloud list: " << recognized_cloud_list_.objects.size());
    RCLCPP_INFO_STREAM(this->get_logger(), "RGB list: " << recognized_image_list_.objects.size());
    RCLCPP_INFO_STREAM(this->get_logger(), "Combined object list: "<< combined_object_list.objects.size());
    const Eigen::Vector3f normal = scene_segmentation_ros_->getPlaneNormal();
    std::string names = "";
    if (recognized_cloud_list_.objects.size() > 0)
    {
        // Bounding boxes
        if (clusters_3d.size() > 0)
        {
            mas_perception_msgs::msg::BoundingBoxList bounding_boxes;
            cluster_visualizer_pc_.publish(clusters_3d, target_frame_id_);
            // cluster_visualizer_pc_.publish<PointT>(clusters_3d, target_frame_id_);
            bounding_boxes.bounding_boxes.resize(clusters_3d.size());
            for (int i=0; i < clusters_3d.size(); i++)
            {
                mpu::object::BoundingBox bbox;
                mpu::object::get3DBoundingBox(clusters_3d[i], normal, bbox, bounding_boxes.bounding_boxes[i]);
            }
            if (bounding_boxes.bounding_boxes.size() > 0)
            {
                bounding_box_visualizer_pc_.publish(bounding_boxes.bounding_boxes, target_frame_id_);
            }
        }
        // PCL Pose array for debug mode only
        geometry_msgs::msg::PoseArray pcl_object_pose_array;
        pcl_object_pose_array.header.frame_id = target_frame_id_;
        // pcl_object_pose_array.header.stamp = rclcpp::Time::now();
        pcl_object_pose_array.header.stamp = rclcpp::Clock().now();
        pcl_object_pose_array.poses.resize(recognized_cloud_list_.objects.size());
        std::vector<std::string> pcl_labels;
        int pcl_count = 0;
        for (int i=0; i < combined_object_list.objects.size(); i++)
        {
            if (combined_object_list.objects[i].database_id < 99)
            {
                names += combined_object_list.objects[i].name + ", ";
                pcl_object_pose_array.poses[pcl_count] = combined_object_list.objects[i].pose.pose;
                pcl_labels.push_back(combined_object_list.objects[i].name);
                pcl_count++;
            }
        }
        RCLCPP_INFO_STREAM(this->get_logger(),"[Cloud] Objects: " << names);
        // Publish pose array
        if (pcl_object_pose_array.poses.size() > 0)
        {
            pub_pc_object_pose_array_->publish(pcl_object_pose_array);
        }
        // Publish label visualizer
        if ((pcl_labels.size() == pcl_object_pose_array.poses.size()) &&
            (pcl_labels.size() > 0) && (pcl_object_pose_array.poses.size() > 0))
        {
            label_visualizer_pc_.publish(pcl_labels, pcl_object_pose_array);
        }
    }
    if (clusters_2d.size() > 0)
    {
        // cluster_visualizer_rgb_.publish<PointT>(clusters_2d, target_frame_id_);
        cluster_visualizer_rgb_.publish(clusters_2d, target_frame_id_);
        // RGB Pose array for debug mode only
        geometry_msgs::msg::PoseArray rgb_object_pose_array;
        rgb_object_pose_array.header.frame_id = target_frame_id_;
        rgb_object_pose_array.header.stamp = rclcpp::Clock().now();
        rgb_object_pose_array.poses.resize(recognized_image_list_.objects.size());
        std::vector<std::string> rgb_labels;
        int rgb_count = 0;
        names = "";
        for (int i = 0; i < combined_object_list.objects.size(); i++)
        {
            if (combined_object_list.objects[i].database_id > 99)
            {
                names += combined_object_list.objects[i].name + ", ";
                rgb_object_pose_array.poses[rgb_count] = combined_object_list.objects[i].pose.pose;
                rgb_labels.push_back(combined_object_list.objects[i].name);
                rgb_count++;
            }
        }
        RCLCPP_INFO_STREAM(this->get_logger(),"[RGB] Objects: "<< names);
        // Publish pose array
        if (rgb_object_pose_array.poses.size() > 0)
        {
        pub_rgb_object_pose_array_->publish(rgb_object_pose_array);
        }
        // Publish label visualizer
        if ((rgb_labels.size() == rgb_object_pose_array.poses.size()) &&
            (rgb_labels.size() > 0) && (rgb_object_pose_array.poses.size() > 0))
        {
        label_visualizer_rgb_.publish(rgb_labels, rgb_object_pose_array);
        }
    }
}

void MultiModalObjectRecognitionROS::segmentPointCloud(mas_perception_msgs::msg::ObjectList &object_list,
                                                       std::vector<PointCloudBSPtr> &clusters,
                                                       std::vector<mpu::object::BoundingBox> boxes)
{
    PointCloudBSPtr cloud = PointCloudBSPtr(new PointCloud);
    cloud->header.frame_id = target_frame_id_;

    scene_segmentation_ros_->getCloudAccumulation(cloud);

    // if the cluster is centered,it looses the correct location of the object
    // scene_segmentation_ros_->segmentCloud(cloud, object_list, clusters, boxes,
    //                                       center_cluster_ = false, pad_cluster_, padded_cluster_size_);

    
    // get workspace height
    std_msgs::msg::Float64 workspace_height_msg;
    workspace_height_msg.data = scene_segmentation_ros_->getWorkspaceHeight();
    pub_workspace_height_->publish(workspace_height_msg);

    PointCloudBSPtr cloud_debug(new PointCloud);

    // for testing plane detection, findPlane is directly called here.
    scene_segmentation_ros_->findPlane(cloud, cloud_debug);

    sensor_msgs::msg::PointCloud2 ros_pc2;
    pcl::toROSMsg(*cloud_debug, ros_pc2);
    ros_pc2.header.frame_id = target_frame_id_;
    pub_debug_cloud_plane_->publish(ros_pc2);
}

void MultiModalObjectRecognitionROS::recognizeCloudAndImage()
{
    mas_perception_msgs::msg::ObjectList cloud_object_list;
    std::vector<PointCloudBSPtr> clusters_3d;
    std::vector<mpu::object::BoundingBox> boxes;

    this->segmentPointCloud(cloud_object_list, clusters_3d, boxes);

    if (data_collection_)
    {
        std::string filename;
        for (auto& cluster : clusters_3d)
        {
            filename = "";
            filename.append("pcd_cluster_");
            // filename.append(std::to_string(cluster -> header.timestamp)); // get the proper format for the timestamp
            mpu::object::savePcd(cluster, logdir_, filename);
            // ROS_INFO_STREAM("\033[1;35mSaving point cloud to \033[0m" << logdir_);
        }
            // Save raw image
        cv_bridge::CvImagePtr raw_cv_image;
        if (mpu::object::getCVImage(image_msg_, raw_cv_image))
        {
            std::string filename = "";
            filename.append("rgb_raw_");
            // filename.append(std::to_string(raw_cv_image->header.timestamp)); // get the proper format for the timestamp
            mpu::object::saveCVImage(raw_cv_image, logdir_, filename);
            // ROS_INFO_STREAM("Image:" << filename << " saved to " << logdir_);
        }
        else
        {
            RCLCPP_ERROR(get_logger(),"Cannot generate cv image...");
        }

        return;
    }
}

void MultiModalObjectRecognitionROS::loadObjectInfo(const std::string &filename)
{
    RCLCPP_INFO(get_logger(), "Into my function!");
    YAML::Node config = YAML::LoadFile(filename);
    mas_perception_msgs::msg::Object object1;
    if (config["object_info"])
    {
        for (unsigned j = 0; j < config[0]["object"].size(); ++j)
        {
            Object f;
            f.name = config[0]["object"][j]["name"].as<std::string>();
            f.shape = config[0]["object"][j]["shape"].as<std::string>();
            f.color = config[0]["object"][j]["color"].as<std::string>();
            RCLCPP_INFO(get_logger(), "%s %s %s", f.name.c_str(), f.shape.c_str(), f.color.c_str());
            if (f.shape == object1.shape.SPHERE)
            {
                round_objects_.insert(f.name);
            }
            object_info_.push_back(f);
        }
        
        RCLCPP_INFO(get_logger(), "Object info is loaded!");
    }
    else
    {
        RCLCPP_WARN(get_logger(), "No object info is provided!");
        return;
    }    
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
MultiModalObjectRecognitionROS::on_configure(const rclcpp_lifecycle::State &)
{
    // This callback is supposed to be used for initialization and
    // configuring purposes.
    // We thus initialize and configure our publishers and timers.
    // The lifecycle node API does return lifecycle components such as
    // lifecycle publishers. These entities obey the lifecycle and
    // can comply to the current state of the node.
    // As of the beta version, there is only a lifecycle publisher
    // available.

    RCLCPP_INFO(get_logger(), "on_configure() is called.");

    image_sub_.subscribe(this, "input_image_topic");
    cloud_sub_.subscribe(this, "input_cloud_topic");
    publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("transformer/pointcloud",10);
    pub_pc_object_pose_array_ = this->create_publisher<geometry_msgs::msg::PoseArray>("output/pc_object_pose_array", 10);
    pub_rgb_object_pose_array_  = this->create_publisher<geometry_msgs::msg::PoseArray>("output/rgb_object_pose_array", 10);

    // msg_sync_.reset(new Sync(msgSyncPolicy(10), image_sub_, cloud_sub_));
    msg_sync_ = std::make_shared<Sync>(msgSyncPolicy(10), image_sub_, cloud_sub_);

    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    callback_handle_ = this->add_on_set_parameters_callback(
        std::bind(&MultiModalObjectRecognitionROS::parametersCallback, this, std::placeholders::_1));

    MultiModalObjectRecognitionROS::get_all_parameters();
    MultiModalObjectRecognitionROS::loadObjectInfo(object_info_path_);

    // publish workspace height
    pub_workspace_height_ = this->create_publisher<std_msgs::msg::Float64>("workspace_height", 1);

    // publish debug
    pub_debug_cloud_plane_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("output/debug_cloud_plane", 1);

    // We return a success and hence invoke the transition to the next
    // step: "inactive".
    // If we returned TRANSITION_CALLBACK_FAILURE instead, the state machine
    // would stay in the "unconfigured" state.
    // In case of TRANSITION_CALLBACK_ERROR or any thrown exception within
    // this callback, the state machine transitions to state "errorprocessing".
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
MultiModalObjectRecognitionROS::on_activate(const rclcpp_lifecycle::State &)
{
    RCUTILS_LOG_INFO_NAMED(get_name(), "on_activate() is called.");

    // Let's sleep for 2 seconds.
    // We emulate we are doing important
    // work in the activating phase.
    pub_workspace_height_ -> on_activate(); 
    pub_debug_cloud_plane_ -> on_activate();
    std::this_thread::sleep_for(2s);

    msg_sync_->registerCallback(&MultiModalObjectRecognitionROS::synchronizeCallback, this);

    // We return a success and hence invoke the transition to the next
    // step: "active".
    // If we returned TRANSITION_CALLBACK_FAILURE instead, the state machine
    // would stay in the "inactive" state.
    // In case of TRANSITION_CALLBACK_ERROR or any thrown exception within
    // this callback, the state machine transitions to state "errorprocessing".
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
MultiModalObjectRecognitionROS::on_deactivate(const rclcpp_lifecycle::State &)
{
    RCUTILS_LOG_INFO_NAMED(get_name(), "on_deactivate() is called.");

    image_sub_.unsubscribe();
    cloud_sub_.unsubscribe();

    // We return a success and hence invoke the transition to the next
    // step: "inactive".
    // If we returned TRANSITION_CALLBACK_FAILURE instead, the state machine
    // would stay in the "active" state.
    // In case of TRANSITION_CALLBACK_ERROR or any thrown exception within
    // this callback, the state machine transitions to state "errorprocessing".
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
MultiModalObjectRecognitionROS::on_cleanup(const rclcpp_lifecycle::State &)
{
    // In our cleanup phase, we release the shared pointers to the
    // timer and publisher. These entities are no longer available
    // and our node is "clean".
    // obj_list_pub_.reset();

    RCUTILS_LOG_INFO_NAMED(get_name(), "on cleanup is called.");

    msg_sync_.reset();
    this->remove_on_set_parameters_callback(callback_handle_.get());

    // We return a success and hence invoke the transition to the next
    // step: "unconfigured".
    // If we returned TRANSITION_CALLBACK_FAILURE instead, the state machine
    // would stay in the "inactive" state.
    // In case of TRANSITION_CALLBACK_ERROR or any thrown exception within
    // this callback, the state machine transitions to state "errorprocessing".
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
MultiModalObjectRecognitionROS::on_shutdown(const rclcpp_lifecycle::State &state)
{
    // In our shutdown phase, we release the shared pointers to the
    // timer and publisher. These entities are no longer available
    // and our node is "clean".
    // obj_list_pub_.reset();

    RCUTILS_LOG_INFO_NAMED(
        get_name(),
        "on shutdown is called from state %s.",
        state.label().c_str());

    // We return a success and hence invoke the transition to the next
    // step: "finalized".
    // If we returned TRANSITION_CALLBACK_FAILURE instead, the state machine
    // would stay in the current state.
    // In case of TRANSITION_CALLBACK_ERROR or any thrown exception within
    // this callback, the state machine transitions to state "errorprocessing".
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

} //end of namespace


/**
 * A lifecycle node has the same node API
 * as a regular node. This means we can spawn a
 * node, give it a name and add it to the executor.
 */
// int main(int argc, char *argv[])
// {
//     // force flush of the stdout buffer.
//     // this ensures a correct sync of all prints
//     // even when executed simultaneously within the launch file.
//     setvbuf(stdout, NULL, _IONBF, BUFSIZ);

//     rclcpp::init(argc, argv);

//     rclcpp::executors::SingleThreadedExecutor exe;

//     std::shared_ptr<MultiModalObjectRecognitionROS> mmor_lc_node =
//         std::make_shared<MultiModalObjectRecognitionROS>("multimodal_object_recognition", false);

//     exe.add_node(mmor_lc_node->get_node_base_interface());

//     exe.spin();

//     rclcpp::shutdown();

//     return 0;
// }


RCLCPP_COMPONENTS_REGISTER_NODE(perception_namespace::MultiModalObjectRecognitionROS)