; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0002
ordinary_graphics_header_numeric_20261013_db0000_decoded_size:
    .byte >$12D0, <$12D0 ; big-endian u16
