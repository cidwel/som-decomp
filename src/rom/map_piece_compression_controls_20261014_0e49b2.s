.setcpu "65816"
.segment "CODE"
.org $49B2
map_control_0e49b2:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
