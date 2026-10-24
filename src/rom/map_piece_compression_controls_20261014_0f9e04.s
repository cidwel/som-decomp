.setcpu "65816"
.segment "CODE"
.org $9E04
map_control_0f9e04:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
