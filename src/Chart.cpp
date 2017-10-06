#include "../include/Chart.h"
// Demo of sending data via temporary files.  The default is to send data to gnuplot directly
// through stdin.

// Compile it with:
//   g++ -o example-tmpfile example-tmpfile.cc -lboost_iostreams -lboost_system -lboost_filesystem

// #include <map>
// #include <vector>
// #include <cmath>

// #include "gnuplot-iostream.h"

// int main() {
// 	Gnuplot gp;

// 	std::vector<std::pair<double, double> > xy_pts_A;
// 	std::vector<std::pair<double, double> > xy_pts_B;

// 	xy_pts_A.push_back(std::make_pair(7888.3015 , 41.1025));
// 	xy_pts_A.push_back(std::make_pair(2871.0148 , 40.1065));
// 	xy_pts_A.push_back(std::make_pair(1458.1422 , 38.6771));
// 	xy_pts_A.push_back(std::make_pair(799.7169  , 36.8573));


// 	xy_pts_B.push_back(std::make_pair(7888.3015 , 41.1025));
// 	xy_pts_B.push_back(std::make_pair(2871.0148 , 40.1065));
// 	xy_pts_B.push_back(std::make_pair(1458.1422 , 38.6771));
// 	xy_pts_B.push_back(std::make_pair(799.7169  , 36.8573));
	

// 	std::vector<std::pair<double, double> > xy_pts_C;
// 	std::vector<std::pair<double, double> > xy_pts_D;

// 	xy_pts_C.push_back(std::make_pair(7664.2849 , 40.1103));
// 	xy_pts_C.push_back(std::make_pair(2357.3422 , 39.1153));
// 	xy_pts_C.push_back(std::make_pair(1353.9735 , 37.6890));
// 	xy_pts_C.push_back(std::make_pair(798.3182  , 32.8681));


// 	xy_pts_D.push_back(std::make_pair(7664.2849 , 40.1103));
// 	xy_pts_D.push_back(std::make_pair(2357.3422 , 39.1153));
// 	xy_pts_D.push_back(std::make_pair(1353.9735 , 37.6890));
// 	xy_pts_D.push_back(std::make_pair(798.3182  , 32.8681));

// 	gp << " set ylabel \"PSNR\" "<< std::endl;
// 	gp << " set xlabel \"Bit-Rate\" "<< std::endl;

// 	gp << " set encoding utf8"<< std::endl;

// 	gp << " set xrange [600:8000]\nset yrange [20:50] " << std::endl;
// 	gp << " set grid ytics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;
// 	gp << " set grid xtics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;


// 	gp <<"plot" << gp.file1d(xy_pts_A) << " lw 4 lt rgb '#FF0000'" << " with lines title 'Evaluater',"
// 				<< gp.file1d(xy_pts_B) << " using 1:2:(\"X\") with labels title '', " 
// 				<< gp.file1d(xy_pts_C) << " lw 4 lt rgb '#00FF00'" << " with lines title 'Reference', "
// 				<< gp.file1d(xy_pts_D) << " using 1:2:(\"O\") with labels title '' " << std::endl;


// }


// Demo of sending data via temporary files.  The default is to send data to gnuplot directly
// through stdin.
//
// Compile it with:
//   g++ -o example-tmpfile example-tmpfile.cc -lboost_iostreams -lboost_system -lboost_filesystem

//--------------------------------------------

// #include <map>
// #include <vector>
// #include <cmath>

// #include "gnuplot-iostream.h"

// int main() {
// 	Gnuplot gp;

// 	std::vector<std::pair<double, double> > xy_pts_A;
// 	std::vector<std::pair<double, double> > xy_pts_B;

// 	xy_pts_A.push_back(std::make_pair(22, 7888.3015 ));
// 	xy_pts_A.push_back(std::make_pair(27, 2871.0148 ));
// 	xy_pts_A.push_back(std::make_pair(32, 1458.1422 ));
// 	xy_pts_A.push_back(std::make_pair(37, 799.7169  ));


// 	xy_pts_B.push_back(std::make_pair(22, 7888.3015 ));
// 	xy_pts_B.push_back(std::make_pair(27, 2871.0148 ));
// 	xy_pts_B.push_back(std::make_pair(32, 1458.1422 ));
// 	xy_pts_B.push_back(std::make_pair(37, 799.7169  ));
	

// 	std::vector<std::pair<double, double> > xy_pts_C;
// 	std::vector<std::pair<double, double> > xy_pts_D;

// 	xy_pts_C.push_back(std::make_pair(22, 7664.2849 ));
// 	xy_pts_C.push_back(std::make_pair(27, 2357.3422 ));
// 	xy_pts_C.push_back(std::make_pair(32, 1353.9735 ));
// 	xy_pts_C.push_back(std::make_pair(37, 798.3182  ));


// 	xy_pts_D.push_back(std::make_pair(22, 7664.2849));
// 	xy_pts_D.push_back(std::make_pair(27, 2357.3422));
// 	xy_pts_D.push_back(std::make_pair(32, 1353.9735));
// 	xy_pts_D.push_back(std::make_pair(37, 798.3182 ));

// 	gp << " set ylabel \"Bit-Rate\" "<< std::endl;
// 	gp << " set xlabel \"QP\" "<< std::endl;

// 	gp << " set encoding utf8"<< std::endl;

// 	gp << " set xrange [20:40]\nset yrange [500:8000] " << std::endl;
// 	gp << " set grid ytics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;
// 	gp << " set grid xtics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;


// 	gp <<"plot" << gp.file1d(xy_pts_A) << " lw 4 lt rgb '#FF0000'" << " with lines title 'Evaluater',"
// 				<< gp.file1d(xy_pts_B) << " using 1:2:(\"X\") with labels title '', " 
// 				<< gp.file1d(xy_pts_C) << " lw 4 lt rgb '#00FF00'" << " with lines title 'Reference', "
// 				<< gp.file1d(xy_pts_D) << " using 1:2:(\"O\") with labels title '' " << std::endl;


// }

//--------------------------------------------
// #include <map>
// #include <vector>
// #include <cmath>

Chart::Chart(vector<double> psnr_eva, vector<double> rate_eva, vector<double> psnr_ref, vector<double> rate_ref, vector<double> qp, string name_test){
	this->psnr_eva 	= psnr_eva;
	this->rate_eva 	= rate_eva;
	this->psnr_ref 	= psnr_ref;
	this->rate_ref 	= rate_ref;
	this->qp 		= qp;
	this->name_test = name_test; 
}

	
void Chart::ChartPSNRxGP(){
	Gnuplot gp;

	std::vector<std::pair<double, double> > xy_pts_A;
	std::vector<std::pair<double, double> > xy_pts_B;

	for (int i = 0; i < psnr_eva.size(); ++i){
		xy_pts_A.push_back(std::make_pair(qp[i], psnr_eva[i]));
		xy_pts_B.push_back(std::make_pair(qp[i], psnr_eva[i]));
	}	

	std::vector<std::pair<double, double> > xy_pts_C;
	std::vector<std::pair<double, double> > xy_pts_D;

	for (int i = 0; i < psnr_ref.size(); ++i){
		xy_pts_C.push_back(std::make_pair(qp[i], psnr_ref[i]));
		xy_pts_D.push_back(std::make_pair(qp[i], psnr_ref[i]));
	}	

	gp << " set ylabel \"PSNR\" "<< std::endl;
	gp << " set xlabel \"QP\" "<< std::endl;
	gp << " set encoding utf8"<< std::endl;
	gp << " set xrange [20:40]\nset yrange [20:50] " << std::endl;
	gp << " set grid ytics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;
	gp << " set grid xtics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;
	gp << "set terminal png size 1024,786 enhanced font \"Helvetica,20\" " << std::endl;
	gp << "set output \'output.png\' " << std::endl;
	gp <<"plot" << gp.file1d(xy_pts_A) << " lw 4 lt rgb '#FF0000'" << " with lines title 'Evaluater',"
				<< gp.file1d(xy_pts_B) << " using 1:2:(\"X\") with labels title '', " 
				<< gp.file1d(xy_pts_C) << " lw 4 lt rgb '#00FF00'" << " with lines title 'Reference', "
				<< gp.file1d(xy_pts_D) << " using 1:2:(\"O\") with labels title '' " << std::endl;
}



void Chart::ChartBRxGP(){
	Gnuplot gp;

	std::vector<std::pair<double, double> > xy_pts_A;
	std::vector<std::pair<double, double> > xy_pts_B;

	for (int i = 0; i < rate_eva.size(); ++i){
		xy_pts_A.push_back(std::make_pair(qp[i], rate_eva[i]));
		xy_pts_B.push_back(std::make_pair(qp[i], rate_eva[i]));
	}	

	std::vector<std::pair<double, double> > xy_pts_C;
	std::vector<std::pair<double, double> > xy_pts_D;

	for (int i = 0; i < rate_ref.size(); ++i){
		xy_pts_C.push_back(std::make_pair(qp[i], rate_ref[i]));
		xy_pts_D.push_back(std::make_pair(qp[i], rate_ref[i]));
	}	

	gp << " set ylabel \"Bit-Rate\" "<< std::endl;
	gp << " set xlabel \"QP\" "<< std::endl;
	gp << " set encoding utf8"<< std::endl;
	gp << " set xrange [20:40]\nset yrange [20:50] " << std::endl;
	gp << " set grid ytics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;
	gp << " set grid xtics lt 0 lw 1 lc rgb \"#bbbbbb\" " << std::endl;
	gp << "set terminal png size 1024,786 enhanced font \"Helvetica,20\" " << std::endl;
	gp << "set output \'output.png\' " << std::endl;
	gp <<"plot" << gp.file1d(xy_pts_A) << " lw 4 lt rgb '#FF0000'" << " with lines title 'Evaluater',"
				<< gp.file1d(xy_pts_B) << " using 1:2:(\"X\") with labels title '', " 
				<< gp.file1d(xy_pts_C) << " lw 4 lt rgb '#00FF00'" << " with lines title 'Reference', "
				<< gp.file1d(xy_pts_D) << " using 1:2:(\"O\") with labels title '' " << std::endl;

}


