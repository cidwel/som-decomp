; Typed LZ header field; reserved byte and compressed payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A469
ordinary_graphics_header_numeric_20261013_dba467_decoded_size:
    .byte >$02C0, <$02C0 ; big-endian u16
