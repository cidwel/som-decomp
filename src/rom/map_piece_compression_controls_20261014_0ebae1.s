.setcpu "65816"
.segment "CODE"
.org $BAE1
map_control_0ebae1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
