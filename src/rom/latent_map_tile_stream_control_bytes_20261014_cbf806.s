; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $F806
map_stream_controls_cbf806:
    .byte $00, $00, $00, $0F
