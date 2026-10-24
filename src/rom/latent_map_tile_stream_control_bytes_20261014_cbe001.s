; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $E001
map_stream_controls_cbe001:
    .byte $0F
