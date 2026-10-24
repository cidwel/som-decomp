.setcpu "65816"
.segment "CODE"
.org $1A61
map_control_0d1a61:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
