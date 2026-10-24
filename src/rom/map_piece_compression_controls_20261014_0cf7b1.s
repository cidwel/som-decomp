.setcpu "65816"
.segment "CODE"
.org $F7B1
map_control_0cf7b1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
