# Waveform Generation Utility

This utility takes a .wav file and creates the type of file used
by the waveform generator.

## Requirements

### Input Requirements

Input must be in the form of a single-channel 16-bit signed PCM .wav file.
Additionally, the length of the sample should be such that a maximum of 255
data points should be sufficient to characterize the waveform. The below
screenshot shows the export settings for the free audio editing program
Audacity

![Export](../../images/export.jpg)

### Python Requirements

This project was designed for Python 3.7 and does not require any additional
dependencies.

## Usage

The following parameters are set by the user by editing main.py

### source_file

The name of the file to be read. This file should be located in the same folder
as main.py

### sample_name

The name of the sample, as will be displayed by the waveform generator. This
can be a maximum of 16 ASCII characters.

### sample_points

The number of points of data in the sample. More data points better reproduces
the original waveform, but fewer allows for a higher output frequency. Note that
this number should not exceed 255.

### output_file

The name of the file to be generated. Note that the files as loaded onto the
SD card must be named sequential numbers starting from 0 (e.g '0', '1', '2').
This setting can be adjusted each time a new waveform is created, or the user
can simply rename the file afterwards.
