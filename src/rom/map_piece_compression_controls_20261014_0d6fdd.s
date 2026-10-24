.setcpu "65816"
.segment "CODE"
.org $6FDD
map_control_0d6fdd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
