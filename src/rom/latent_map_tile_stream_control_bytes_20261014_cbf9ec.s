; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $F9EC
map_stream_controls_cbf9ec:
    .byte $55, $57
