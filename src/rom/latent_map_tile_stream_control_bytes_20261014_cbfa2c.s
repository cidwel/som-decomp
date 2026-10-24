; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FA2C
map_stream_controls_cbfa2c:
    .byte $55, $9E
