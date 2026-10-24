; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $C43D
map_stream_controls_cbc43d:
    .byte $00, $00, $0F
