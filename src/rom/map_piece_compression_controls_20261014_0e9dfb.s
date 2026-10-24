.setcpu "65816"
.segment "CODE"
.org $9DFB
map_control_0e9dfb:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
