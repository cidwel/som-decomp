.setcpu "65816"
.segment "CODE"
.org $1083
map_control_0f1083:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
