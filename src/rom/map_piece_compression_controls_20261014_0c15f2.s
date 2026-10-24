.setcpu "65816"
.segment "CODE"
.org $15F2
map_control_0c15f2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
