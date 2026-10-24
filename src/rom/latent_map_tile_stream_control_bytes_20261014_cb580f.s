; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $580F
map_stream_controls_cb580f:
    .byte $00, $00, $00, $0F
