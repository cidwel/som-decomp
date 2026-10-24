; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $C3FD
map_stream_controls_cbc3fd:
    .byte $00, $00, $00, $00, $0F
