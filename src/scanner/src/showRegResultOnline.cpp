#include <iostream>
#include <string>
#include <sstream>

#include <ros/ros.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/visualization/pcl_visualizer.h>

typedef pcl::PointXYZRGBA PointT;

// ***********************
// ******** PCLVisualizer
// ***********************
/*int
main (int argc, char **argv)
{
    ros::init (argc, argv, "showRegResultOnline");
    ros::NodeHandle nh;

    std::string filename = "/home/donyan/Desktop/kinect/src/scanner/data/result/registerResult.pcd";
    pcl::PointCloud<PointT>::Ptr cloud_ptr (new pcl::PointCloud<PointT>);

    // set up visualizer

    // --------------------------------------------
    // -----Open 3D viewer and add point cloud-----
    // --------------------------------------------

    //创建视窗对象并给标题栏设置一个名称“3D Viewer”
    pcl::visualization::PCLVisualizer viewer("viewer");
    //设置视窗的背景色，可以任意设置RGB的颜色，这里是设置为黑色
    viewer.setBackgroundColor (0, 0, 0);
    //用于改变显示点云的尺寸，可以利用该方法控制点云在视窗中的显示方法，
    viewer.addPointCloud<PointT> (cloud_ptr, "wholeCloud");
    //viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "wholeCloud");
    viewer.addCoordinateSystem (0.5);
    //viewer.setCameraPosition(0,0,-3.0,0,-1,0);
    //viewer.setCameraPosition(0,-0.5,1.0,0,0,-1);
    // viewer.setFullScreen(true);
    //通过设置照相机参数使得从默认的角度和方向观察点云
    viewer.initCameraParameters ();
    pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr);

    ros::Rate loop_rate(2);
    loop_rate.sleep();              // sleep two second at the beginning
    ros::Rate loop_rate_runtime(2);
    while (ros::ok() && !viewer.wasStopped())
    {
        // pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr);
        if (pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr) == -1){
          PCL_ERROR ("Couldn't read PCD file \n");
          continue;
        }
        std::cout << (cloud_ptr->size()) << endl;
        if (cloud_ptr->size() < 66) continue;

        //viewer.spinOnce();
        // viewer.spin();
        viewer.updatePointCloud( cloud_ptr, "wholeCloud" );
        viewer.spinOnce(777);
        //std::cout << *cloud_ptr << endl;
        // viewer.setCameraPosition(0,-0.5,1.0,0,0,-1);
        loop_rate_runtime.sleep();
    }

    return 0;
}*/

void viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{

	//设置背景颜色
	viewer.setBackgroundColor (255.0, 255.0, 255.0);
	
	//球体坐标
 //   pcl::PointXYZ o;
 //   o.x = 0;
 //   o.y = 0;
 //   o.z = 0;
	////添加球体
 //   viewer.addSphere (o, 1, "sphere", 0);
 //   std::cout << "i only run once" << std::endl;

}



// ********************
// ******** Cloudviewer
// ********************

int
main (int argc, char **argv)
{
    ros::init (argc, argv, "showRegResultOnline");
    ros::NodeHandle nh;
    std::string filename = "/home/donyan/Desktop/kinect/src/scanner/data/result/registerResult.pcd";
    pcl::PointCloud<PointT>::Ptr cloud_ptr (new pcl::PointCloud<PointT>);
    pcl::visualization::CloudViewer viewer("viewer");
    viewer.runOnVisualizationThreadOnce (viewerOneOff);//调用相应函数执行

    ros::Rate loop_rate(0.5);
    loop_rate.sleep();              // sleep two second at the beginning
    ros::Rate loop_rate_runtime(2);

    while (ros::ok())
    {
        // pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr);
        if (pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr) == -1){
          // PCL_ERROR ("Couldn't read PCD file \n");
          continue;
        }
        viewer.showCloud( cloud_ptr );
        loop_rate_runtime.sleep();
    }

    return 0;
}




