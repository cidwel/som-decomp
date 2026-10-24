; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $AEAE
map_stream_controls_cbaeae:
    .byte $00, $23
