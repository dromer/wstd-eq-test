NAME = wstd_eq

FILES_DSP = $(wildcard *.cpp)
FILES_DSP += $(wildcard *.c)

DPF_TARGET_DIR = ../../bin
DPF_BUILD_DIR = ../../build
DPF_PATH = ../../dpf

include ../../dpf/Makefile.plugins.mk

LINK_FLAGS += -lpthread
CFLAGS += -Wno-unused-parameter
CXXFLAGS += -Wno-unused-parameter


	
TARGETS += lv2_dsp
	
TARGETS += vst2
	
TARGETS += vst3
	
TARGETS += jack
	


all: $(TARGETS)