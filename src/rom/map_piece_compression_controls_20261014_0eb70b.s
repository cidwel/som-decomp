.setcpu "65816"
.segment "CODE"
.org $B70B
map_control_0eb70b:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
