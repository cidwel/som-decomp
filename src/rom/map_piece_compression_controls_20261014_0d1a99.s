.setcpu "65816"
.segment "CODE"
.org $1A99
map_control_0d1a99:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
