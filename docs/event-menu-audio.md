# Native menu audio preset caller

C029D2 reconstructs 42 instruction bytes. All nine fixed presets are expanded
into the actual four-byte request and passed through the complete C30004 sender.
Nonmusic requests and the music/song/sample path use the actual APU packet bus
and acknowledgement state. No original audio payload is stored.

The original comparison passed 36 complete calls across four DB/flags/playing
and acknowledgement-delay contexts. All 25 instruction starts were observed.
All memory, peripherals, registers and ordered APU writes match; the stack is
relocated to1700 so that music workspace1E00..1FFF remains fully compared.
SPC waveforms, console timing and complete menu interaction remain open.
