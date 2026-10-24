; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $8260
map_stream_controls_cb8260:
    .byte $0F
