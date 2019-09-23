#include<iostream>
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
//"/home/donyan/Desktop/kinect/src/scanner/data/1.pcd"
typedef pcl::PointXYZRGBA PointT;
int
main (int argc, char **argv)
{

    std::string filename = argv[1];
    pcl::PointCloud<PointT>::Ptr cloud_ptr (new pcl::PointCloud<PointT>);
    pcl::visualization::CloudViewer viewer("viewer");


    while (!viewer.wasStopped())
    {
        // pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr);
        if (pcl::io::loadPCDFile<PointT> (filename, *cloud_ptr) == -1){
          // PCL_ERROR ("Couldn't read PCD file \n");
          continue;
        }

        viewer.showCloud( cloud_ptr );
    }

    return 0;
}


