.setcpu "65816"
.segment "CODE"
.org $87BE
map_control_0f87be:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
