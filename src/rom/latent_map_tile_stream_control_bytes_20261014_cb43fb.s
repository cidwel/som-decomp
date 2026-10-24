; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $43FB
map_stream_controls_cb43fb:
    .byte $02, $01
