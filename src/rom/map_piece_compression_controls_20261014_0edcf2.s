.setcpu "65816"
.segment "CODE"
.org $DCF2
map_control_0edcf2:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
