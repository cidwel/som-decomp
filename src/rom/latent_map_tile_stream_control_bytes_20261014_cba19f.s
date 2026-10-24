; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $A19F
map_stream_controls_cba19f:
    .byte $01, $01
