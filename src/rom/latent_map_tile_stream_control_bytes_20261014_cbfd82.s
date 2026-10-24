; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD82
map_stream_controls_cbfd82:
    .byte $00, $00, $00, $00, $03
