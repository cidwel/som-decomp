.setcpu "65816"
.segment "CODE"
.org $7DA9
map_control_0c7da9:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
