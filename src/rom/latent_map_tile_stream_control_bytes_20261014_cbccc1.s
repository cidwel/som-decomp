; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCC1
map_stream_controls_cbccc1:
    .byte $0F
