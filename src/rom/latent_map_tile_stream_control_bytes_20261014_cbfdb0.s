; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FDB0
map_stream_controls_cbfdb0:
    .byte $00, $00, $00, $00, $03
