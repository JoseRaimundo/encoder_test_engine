#ifndef InputVideo_H
#define InputVideo_H

#include <string>


using namespace std;

class InputVideo{

	public:
		InputVideo(string video_nome, string video_paht, string video_wdt, string video_hgt, string video_subsampling, string frames, string bit_depth);
		~InputVideo();
		string getVideoNome();
		string getVideoPaht();
		string getVideoWdt();
		string getVideoHgt();
		string getVideoSubsampling();
		string getFrames();
		string getBitDepth();

		void setVideoNome(string video_nome);
		void setVideoPaht(string video_paht);
		void setVideoWdt(string video_wdt);
		void setVideoHgt(string video_hgt);
		void setVideoSubsampling(string video_subsampling);
		void setFrames(string frames);
		void setBitDepth(string bit_depth);

	private:
		string video_nome; 
		string video_paht;
		string video_wdt;
		string video_hgt;
		string video_subsampling;
		string frames;
		string bit_depth;
};
#endif
