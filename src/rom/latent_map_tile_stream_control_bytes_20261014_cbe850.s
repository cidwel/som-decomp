; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $E850
map_stream_controls_cbe850:
    .byte $92, $6E
