; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FD16
map_stream_controls_c8fd16:
    .byte $00, $67
