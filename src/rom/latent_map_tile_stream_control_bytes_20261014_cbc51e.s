; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $C51E
map_stream_controls_cbc51e:
    .byte $00, $0F
