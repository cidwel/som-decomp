; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE25
map_stream_controls_cbbe25:
    .byte $00, $00, $03
