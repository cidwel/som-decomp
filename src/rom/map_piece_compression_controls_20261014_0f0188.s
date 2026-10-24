.setcpu "65816"
.segment "CODE"
.org $0188
map_control_0f0188:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
