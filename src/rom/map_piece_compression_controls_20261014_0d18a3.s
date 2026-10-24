.setcpu "65816"
.segment "CODE"
.org $18A3
map_control_0d18a3:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
