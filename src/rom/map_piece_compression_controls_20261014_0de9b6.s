.setcpu "65816"
.segment "CODE"
.org $E9B6
map_control_0de9b6:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
