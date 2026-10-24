; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $A0BE
map_stream_controls_cba0be:
    .byte $00, $03
