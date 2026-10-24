.setcpu "65816"
.segment "CODE"
.org $2A6C
map_control_0f2a6c:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
