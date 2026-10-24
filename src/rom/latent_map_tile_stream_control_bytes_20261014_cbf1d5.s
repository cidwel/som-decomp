; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $F1D5
map_stream_controls_cbf1d5:
    .byte $00, $0F
