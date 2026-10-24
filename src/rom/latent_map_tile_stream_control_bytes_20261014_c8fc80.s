; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FC80
map_stream_controls_c8fc80:
    .byte $0F
