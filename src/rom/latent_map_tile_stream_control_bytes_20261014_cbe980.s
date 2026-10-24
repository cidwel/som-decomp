; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $E980
map_stream_controls_cbe980:
    .byte $00, $26
