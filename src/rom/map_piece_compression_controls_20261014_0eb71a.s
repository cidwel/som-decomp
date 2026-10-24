.setcpu "65816"
.segment "CODE"
.org $B71A
map_control_0eb71a:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
