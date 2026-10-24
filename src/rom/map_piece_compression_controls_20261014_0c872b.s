.setcpu "65816"
.segment "CODE"
.org $872B
map_control_0c872b:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
