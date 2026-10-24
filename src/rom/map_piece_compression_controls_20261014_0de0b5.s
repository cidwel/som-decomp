.setcpu "65816"
.segment "CODE"
.org $E0B5
map_control_0de0b5:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
