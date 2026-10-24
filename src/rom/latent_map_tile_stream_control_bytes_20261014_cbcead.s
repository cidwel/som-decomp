; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEAD
map_stream_controls_cbcead:
    .byte $8E
