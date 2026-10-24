.setcpu "65816"
.segment "CODE"
.org $B98F
map_control_0eb98f:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
