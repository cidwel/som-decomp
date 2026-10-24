; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD1E
map_stream_controls_cbfd1e:
    .byte $00, $00, $00, $00, $03
