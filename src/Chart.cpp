#include "Chart.h"


Chart::Chart(){

}

	
void Chart::generateChart(string label_x, string label_y, vector<double> psnr_eva, vector<double> rate_eva, vector<double> psnr_ref, vector<double> rate_ref, vector<double> qp, string name_test){
	Gnuplot gp;

	std::vector<std::pair<double, double>> xy_pts_A;
	std::vector<std::pair<double, double>> xy_pts_B;

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

	gp << " set ylabel " << label_y << " " << std::endl;
	gp << " set xlabel " << label_x << " "<< std::endl;
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

