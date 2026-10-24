.setcpu "65816"
.segment "CODE"
.org $C6A6
map_control_0ec6a6:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
