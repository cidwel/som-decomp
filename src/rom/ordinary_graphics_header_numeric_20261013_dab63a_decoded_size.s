; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B63C
ordinary_graphics_header_numeric_20261013_dab63a_decoded_size:
    .byte >$07CC, <$07CC ; big-endian u16
