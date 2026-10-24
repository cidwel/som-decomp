; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $94CB
map_stream_controls_cb94cb:
    .byte $08, $07
