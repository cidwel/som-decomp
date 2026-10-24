; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEF8
ordinary_graphics_header_numeric_20261013_dacef6_decoded_size:
    .byte >$0BB5, <$0BB5 ; big-endian u16
