; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B31E
ordinary_graphics_header_numeric_20261013_dbb31c_decoded_size:
    .byte >$09BA, <$09BA ; big-endian u16
