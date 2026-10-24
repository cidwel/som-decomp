; Eight command/type control bits only; tile/attribute/tail bits excluded.
.setcpu "65816"
.segment "RODATA"
.org $FE15
map_stream_controls_c8fe15:
    .byte $02, $01
