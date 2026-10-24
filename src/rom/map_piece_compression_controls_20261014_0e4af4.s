.setcpu "65816"
.segment "CODE"
.org $4AF4
map_control_0e4af4:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
