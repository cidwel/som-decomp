.setcpu "65816"
.segment "CODE"
.org $1F54
map_control_0d1f54:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
