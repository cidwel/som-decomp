.setcpu "65816"
.segment "CODE"
.org $9F3A
map_control_0d9f3a:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
