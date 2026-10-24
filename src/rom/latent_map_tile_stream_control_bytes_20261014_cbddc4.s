; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $DDC4
map_stream_controls_cbddc4:
    .byte $0E
