.setcpu "65816"
.segment "CODE"
.org $8A97
map_control_0f8a97:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
