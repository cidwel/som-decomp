.setcpu "65816"
.segment "CODE"
.org $2BA0
map_control_0f2ba0:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
