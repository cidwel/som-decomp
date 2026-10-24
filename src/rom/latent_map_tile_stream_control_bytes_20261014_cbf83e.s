; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $F83E
map_stream_controls_cbf83e:
    .byte $00, $00, $00, $0F
