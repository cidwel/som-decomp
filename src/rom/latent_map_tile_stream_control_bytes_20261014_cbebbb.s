; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $EBBB
map_stream_controls_cbebbb:
    .byte $55, $55, $55
