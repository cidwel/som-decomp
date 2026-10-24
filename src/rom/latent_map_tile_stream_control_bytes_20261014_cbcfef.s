; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFEF
map_stream_controls_cbcfef:
    .byte $00, $00
