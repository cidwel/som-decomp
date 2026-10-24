.setcpu "65816"
.segment "CODE"
.org $7E23
map_control_0d7e23:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
