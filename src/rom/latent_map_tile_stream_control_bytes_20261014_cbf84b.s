; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $F84B
map_stream_controls_cbf84b:
    .byte $01, $5D
