.setcpu "65816"
.segment "CODE"
.org $3533
map_control_0d3533:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
