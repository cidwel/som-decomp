.setcpu "65816"
.segment "CODE"
.org $56D6
map_control_0c56d6:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
