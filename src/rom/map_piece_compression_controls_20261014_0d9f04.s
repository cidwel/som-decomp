.setcpu "65816"
.segment "CODE"
.org $9F04
map_control_0d9f04:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
