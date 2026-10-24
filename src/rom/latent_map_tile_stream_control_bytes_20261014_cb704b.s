; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $704B
map_stream_controls_cb704b:
    .byte $00, $00, $00, $00, $00, $0F
