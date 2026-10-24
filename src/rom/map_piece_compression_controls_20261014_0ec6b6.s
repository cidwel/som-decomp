.setcpu "65816"
.segment "CODE"
.org $C6B6
map_control_0ec6b6:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
