; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $927C
map_stream_controls_cb927c:
    .byte $00, $00, $00, $00, $0F
