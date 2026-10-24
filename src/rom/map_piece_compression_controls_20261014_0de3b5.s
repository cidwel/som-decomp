.setcpu "65816"
.segment "CODE"
.org $E3B5
map_control_0de3b5:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
