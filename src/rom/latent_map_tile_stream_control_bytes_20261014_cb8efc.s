; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $8EFC
map_stream_controls_cb8efc:
    .byte $00, $00, $00, $00, $00, $00, $00, $00, $03
