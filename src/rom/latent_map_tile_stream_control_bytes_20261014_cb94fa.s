; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $94FA
map_stream_controls_cb94fa:
    .byte $00, $00, $00, $00, $0F
