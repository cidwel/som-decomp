; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $CEFC
map_stream_controls_cbcefc:
    .byte $0D
