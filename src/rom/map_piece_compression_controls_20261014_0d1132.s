.setcpu "65816"
.segment "CODE"
.org $1132
map_control_0d1132:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
