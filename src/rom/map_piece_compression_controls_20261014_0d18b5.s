.setcpu "65816"
.segment "CODE"
.org $18B5
map_control_0d18b5:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
