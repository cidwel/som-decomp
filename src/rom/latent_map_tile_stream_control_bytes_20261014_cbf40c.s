; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $F40C
map_stream_controls_cbf40c:
    .byte $00, $00, $00, $0F
