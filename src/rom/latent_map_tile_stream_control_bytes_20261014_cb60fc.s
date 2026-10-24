; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $60FC
map_stream_controls_cb60fc:
    .byte $03
