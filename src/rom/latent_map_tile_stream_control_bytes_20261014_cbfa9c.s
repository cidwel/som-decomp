; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FA9C
map_stream_controls_cbfa9c:
    .byte $55, $67
