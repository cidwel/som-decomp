.setcpu "65816"
.segment "CODE"
.org $8DCB
map_control_0d8dcb:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
