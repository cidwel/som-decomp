.setcpu "65816"
.segment "CODE"
.org $50F7
map_control_0d50f7:
    .byte $E8 ; backreference distance high bits
    .byte $51 ; distance low bit/count
