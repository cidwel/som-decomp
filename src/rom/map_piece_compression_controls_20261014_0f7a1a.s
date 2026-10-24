.setcpu "65816"
.segment "CODE"
.org $7A1A
map_control_0f7a1a:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
