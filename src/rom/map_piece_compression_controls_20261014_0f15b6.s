.setcpu "65816"
.segment "CODE"
.org $15B6
map_control_0f15b6:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
