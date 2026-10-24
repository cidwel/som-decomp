; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $90ED
map_stream_controls_cb90ed:
    .byte $00, $03
