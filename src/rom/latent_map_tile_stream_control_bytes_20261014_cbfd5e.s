; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD5E
map_stream_controls_cbfd5e:
    .byte $00, $00, $00, $00, $03
