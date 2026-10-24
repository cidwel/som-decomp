; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $E100
map_stream_controls_cbe100:
    .byte $03
