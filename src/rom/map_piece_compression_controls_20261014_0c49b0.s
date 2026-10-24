.setcpu "65816"
.segment "CODE"
.org $49B0
map_control_0c49b0:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
