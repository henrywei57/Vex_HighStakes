# VEXcode makefile 2019_03_26_01

# show compiler output
VERBOSE = 0

# include toolchain options
include vex/mkenv.mk

# location of the project source cpp and c files
SRC_C  = $(wildcard src/*.cpp) 
SRC_C += $(wildcard src/*.c)
SRC_C += $(wildcard src/*/*.cpp) 
SRC_C += $(wildcard src/*/*.c)

OBJ = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(SRC_C))) )

# location of include files that c and cpp files depend on
SRC_H  = $(wildcard include/*.h)
LV_SRC_H += $(wildcard lvgl/src/*.h) 
LV_SRC_H += $(wildcard lvgl/src/*/*.h)
LV_DST_H = $(addprefix $(BUILD)/include/, $(LV_SRC_H) )

# additional dependancies
SRC_A  = makefile

# project header file locations


# # build targets
# all: $(BUILD)/$(PROJECT).bin

# # include build rules
# include vex/mkrules.mk

$(BUILD)/include/%: %
	$(Q)$(MKDIR)
	$(Q) $(call copyfile,$^, $@)


# override default library name

# build targets
all: $(BUILD)/$(PROJECT).bin

# include build rules
include vex/mkrules.mk