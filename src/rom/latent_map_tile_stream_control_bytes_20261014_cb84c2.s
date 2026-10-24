; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $84C2
map_stream_controls_cb84c2:
    .byte $01, $10, $0F
