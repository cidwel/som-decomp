.setcpu "65816"
.segment "CODE"
.org $E3AA
map_control_0de3aa:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
