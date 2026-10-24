; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $B387
map_stream_controls_cbb387:
    .byte $0E
