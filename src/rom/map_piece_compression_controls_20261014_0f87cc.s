.setcpu "65816"
.segment "CODE"
.org $87CC
map_control_0f87cc:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
