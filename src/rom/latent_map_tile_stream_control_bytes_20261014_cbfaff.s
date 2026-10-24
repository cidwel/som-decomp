; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FAFF
map_stream_controls_cbfaff:
    .byte $13
