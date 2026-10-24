.setcpu "65816"
.segment "CODE"
.org $7249
map_control_0d7249:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
