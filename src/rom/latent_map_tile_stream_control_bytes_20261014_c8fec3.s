; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FEC3
map_stream_controls_c8fec3:
    .byte $00, $0E
