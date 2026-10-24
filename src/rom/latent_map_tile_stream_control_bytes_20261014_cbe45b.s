; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $E45B
map_stream_controls_cbe45b:
    .byte $00, $00, $0F
