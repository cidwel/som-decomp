; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $C816
map_stream_controls_cbc816:
    .byte $0F
