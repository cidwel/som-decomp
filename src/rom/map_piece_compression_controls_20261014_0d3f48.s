.setcpu "65816"
.segment "CODE"
.org $3F48
map_control_0d3f48:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
