#include "include/sound.h"
#include "include/timer.h"
#include "include/video.h"

static const int SOUND_DEBUG = 0;

//! output sound to speaker
void play(uint32_t frequency) {

	if ((frequency<19) || (frequency>22000)) return;

	// 
	frequency = 1193180L / frequency;
	_outport(0x43, 0xB6);
	_outport(0x42, frequency & 0xFF);
	_outport(0x42, (frequency & 0xFF00) >> 8 );
	_outport(0x61, _inport(0x61) | 3);
}

void pause() {

	_outport(0x61, _inport(0x61) & 0xFC);
}

void beep(void) {
	beeplf(100, 261);
}

void beeplf(uint32_t length, uint32_t freq) {
	
	
	if (freq != 0) {
		play(freq);
	}
	wait(length);
	pause();
}
