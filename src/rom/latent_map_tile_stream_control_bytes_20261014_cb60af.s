; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $60AF
map_stream_controls_cb60af:
    .byte $0F
