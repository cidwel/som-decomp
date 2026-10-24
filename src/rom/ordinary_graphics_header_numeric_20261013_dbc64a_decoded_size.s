; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C64C
ordinary_graphics_header_numeric_20261013_dbc64a_decoded_size:
    .byte >$0BE1, <$0BE1 ; big-endian u16
