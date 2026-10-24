; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $A4A8
map_stream_controls_cba4a8:
    .byte $04, $0F
