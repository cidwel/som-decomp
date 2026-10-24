; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $DCDD
map_stream_controls_cbdcdd:
    .byte $0F
