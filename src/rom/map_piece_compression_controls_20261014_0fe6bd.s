.setcpu "65816"
.segment "CODE"
.org $E6BD
map_control_0fe6bd:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
