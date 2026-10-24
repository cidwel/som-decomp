; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $D803
map_stream_controls_cbd803:
    .byte $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $0F
