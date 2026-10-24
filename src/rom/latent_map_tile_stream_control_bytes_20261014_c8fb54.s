; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FB54
map_stream_controls_c8fb54:
    .byte $00, $00, $03
