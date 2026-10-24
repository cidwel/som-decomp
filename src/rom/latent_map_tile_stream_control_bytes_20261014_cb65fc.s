; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $65FC
map_stream_controls_cb65fc:
    .byte $0F
