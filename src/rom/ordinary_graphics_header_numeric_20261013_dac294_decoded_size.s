; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C296
ordinary_graphics_header_numeric_20261013_dac294_decoded_size:
    .byte >$0DAC, <$0DAC ; big-endian u16
