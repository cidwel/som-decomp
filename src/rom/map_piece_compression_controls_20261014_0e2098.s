.setcpu "65816"
.segment "CODE"
.org $2098
map_control_0e2098:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
