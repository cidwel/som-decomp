.setcpu "65816"
.segment "CODE"
.org $9C1A
map_control_0d9c1a:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
