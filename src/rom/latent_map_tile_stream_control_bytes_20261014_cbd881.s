; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $D881
map_stream_controls_cbd881:
    .byte $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $0F
