.setcpu "65816"
.segment "CODE"
.org $87E1
map_control_0c87e1:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
