.setcpu "65816"
.segment "CODE"
.org $AC35
map_control_0fac35:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
