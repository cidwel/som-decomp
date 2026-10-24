.setcpu "65816"
.segment "CODE"
.org $1A95
map_control_0d1a95:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
