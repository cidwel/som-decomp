; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2D0
map_stream_controls_cbd2d0:
    .byte $00, $00, $0F
