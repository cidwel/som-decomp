.setcpu "65816"
.segment "CODE"
.org $9D6B
map_control_0e9d6b:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
