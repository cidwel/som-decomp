.setcpu "65816"
.segment "CODE"
.org $81A4
map_control_0d81a4:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
