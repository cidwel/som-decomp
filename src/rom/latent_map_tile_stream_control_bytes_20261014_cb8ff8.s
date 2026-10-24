; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $8FF8
map_stream_controls_cb8ff8:
    .byte $02, $01
