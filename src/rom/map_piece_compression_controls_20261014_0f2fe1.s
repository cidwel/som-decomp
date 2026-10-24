.setcpu "65816"
.segment "CODE"
.org $2FE1
map_control_0f2fe1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
