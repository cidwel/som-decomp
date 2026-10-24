.setcpu "65816"
.segment "CODE"
.org $1379
map_control_0f1379:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
