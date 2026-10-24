.setcpu "65816"
.segment "CODE"
.org $C6C6
map_control_0ec6c6:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
