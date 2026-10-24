.setcpu "65816"
.segment "CODE"
.org $9C6B
map_control_0e9c6b:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
