.setcpu "65816"
.segment "CODE"
.org $80AA
map_control_0d80aa:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
