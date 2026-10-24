; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $0100
map_stream_controls_cc0100:
    .byte $0F
