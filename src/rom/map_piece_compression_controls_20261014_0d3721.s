.setcpu "65816"
.segment "CODE"
.org $3721
map_control_0d3721:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
