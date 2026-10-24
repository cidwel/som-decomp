.setcpu "65816"
.segment "CODE"
.org $0A99
map_control_0d0a99:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
