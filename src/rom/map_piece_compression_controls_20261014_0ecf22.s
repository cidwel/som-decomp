.setcpu "65816"
.segment "CODE"
.org $CF22
map_control_0ecf22:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
