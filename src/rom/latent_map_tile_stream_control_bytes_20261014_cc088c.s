; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $088C
map_stream_controls_cc088c:
    .byte $00, $00, $00, $00, $00, $00, $03
