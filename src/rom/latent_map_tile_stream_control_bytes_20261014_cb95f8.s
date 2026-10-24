; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $95F8
map_stream_controls_cb95f8:
    .byte $00, $00, $00, $00, $03
