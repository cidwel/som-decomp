; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $D21D
map_stream_controls_cbd21d:
    .byte $00, $00, $00, $03
