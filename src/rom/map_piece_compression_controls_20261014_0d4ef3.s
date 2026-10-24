.setcpu "65816"
.segment "CODE"
.org $4EF3
map_control_0d4ef3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
