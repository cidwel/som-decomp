.setcpu "65816"
.segment "CODE"
.org $E623
map_control_0de623:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
