; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFBC
map_stream_controls_cbdfbc:
    .byte $03
