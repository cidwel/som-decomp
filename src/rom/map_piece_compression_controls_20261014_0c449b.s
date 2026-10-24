.setcpu "65816"
.segment "CODE"
.org $449B
map_control_0c449b:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
