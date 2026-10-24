.setcpu "65816"
.segment "CODE"
.org $C6A2
map_control_0ec6a2:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
