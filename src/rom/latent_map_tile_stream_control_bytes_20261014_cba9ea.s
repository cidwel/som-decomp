; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $A9EA
map_stream_controls_cba9ea:
    .byte $00, $0F
