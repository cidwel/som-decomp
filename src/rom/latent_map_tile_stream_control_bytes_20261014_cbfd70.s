; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD70
map_stream_controls_cbfd70:
    .byte $00, $00, $00, $00, $00, $00, $00, $03
