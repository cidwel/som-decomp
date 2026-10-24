; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $DEC3
map_stream_controls_cbdec3:
    .byte $01, $9D
