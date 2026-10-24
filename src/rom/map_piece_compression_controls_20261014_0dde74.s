.setcpu "65816"
.segment "CODE"
.org $DE74
map_control_0dde74:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
