; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $8A19
map_stream_controls_cb8a19:
    .byte $00, $0F
