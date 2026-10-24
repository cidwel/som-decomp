.setcpu "65816"
.segment "CODE"
.org $E3B8
map_control_0de3b8:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
