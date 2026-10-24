.setcpu "65816"
.segment "CODE"
.org $D422
map_control_0fd422:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
