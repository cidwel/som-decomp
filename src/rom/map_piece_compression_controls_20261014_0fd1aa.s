.setcpu "65816"
.segment "CODE"
.org $D1AA
map_control_0fd1aa:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
