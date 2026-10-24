.setcpu "65816"
.segment "CODE"
.org $C6B2
map_control_0ec6b2:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
