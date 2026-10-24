; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FEA9
map_stream_controls_c8fea9:
    .byte $00, $00, $00, $00, $00, $00, $00, $0F
