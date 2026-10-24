.setcpu "65816"
.segment "CODE"
.org $E6DB
map_control_0fe6db:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
