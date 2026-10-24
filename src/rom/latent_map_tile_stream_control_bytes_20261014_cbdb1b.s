; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB1B
map_stream_controls_cbdb1b:
    .byte $01, $9D
