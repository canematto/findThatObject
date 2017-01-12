#ifndef ICP_H_INCLUDED
#define ICP_H_INCLUDED

#include <vector>
#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "geometry.h"
#include "pclVisualizer.h"

using namespace Eigen;




class icp {
    private:
        MatrixXd firstCloud, secondCloud;
        Matrix4d initialGuess, finalGuess;



    public:
        struct eJzs {
            Vector3d e,z;
            MatrixXd J;

        };

        struct icpResults {
            MatrixXd newGuess;
            VectorXd chi;
            VectorXd sigma;
        };

        void setFirstCloud(const Ref<const MatrixXd>& cloud);
        void setSecondCloud(const Ref<const MatrixXd>& cloud);
        void setInitialGuess(const Ref<const Matrix4d>& x_guess);
        icpResults allignClouds(int n_it, double kernel_threshold);
        eJzs errorAndJacobianManifold(const Ref<const Matrix4d>& x,
                                        const Vector3d& p,
                                        const Vector3d& z);
        icpResults relaxAllignClouds(const Ref<const MatrixXd>& set1,
                                        const Ref<const MatrixXd>& set2);



        icp(const Ref<const MatrixXd>&  cloud1, const Ref<const MatrixXd>& cloud2);
        ~icp();
};



#endif // ICP_H_INCLUDED