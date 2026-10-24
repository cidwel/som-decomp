; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $72E8
map_stream_controls_cb72e8:
    .byte $00, $01, $8C
