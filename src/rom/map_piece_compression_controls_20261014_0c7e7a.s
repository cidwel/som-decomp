.setcpu "65816"
.segment "CODE"
.org $7E7A
map_control_0c7e7a:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
