.setcpu "65816"
.segment "CODE"
.org $3F29
map_control_0d3f29:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
