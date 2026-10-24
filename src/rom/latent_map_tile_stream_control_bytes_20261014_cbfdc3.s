; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FDC3
map_stream_controls_cbfdc3:
    .byte $03
