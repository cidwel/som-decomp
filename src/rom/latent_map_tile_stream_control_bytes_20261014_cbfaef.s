; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FAEF
map_stream_controls_cbfaef:
    .byte $5C
