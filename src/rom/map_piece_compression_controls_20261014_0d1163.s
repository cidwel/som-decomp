.setcpu "65816"
.segment "CODE"
.org $1163
map_control_0d1163:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
