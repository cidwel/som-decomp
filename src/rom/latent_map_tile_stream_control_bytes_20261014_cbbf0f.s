; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF0F
map_stream_controls_cbbf0f:
    .byte $50, $16
