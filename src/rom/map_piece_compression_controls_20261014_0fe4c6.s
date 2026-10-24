.setcpu "65816"
.segment "CODE"
.org $E4C6
map_control_0fe4c6:
    .byte $E8 ; backreference distance high bits
    .byte $65 ; distance low bit/count
