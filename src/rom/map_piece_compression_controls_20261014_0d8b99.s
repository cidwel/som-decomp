.setcpu "65816"
.segment "CODE"
.org $8B99
map_control_0d8b99:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
