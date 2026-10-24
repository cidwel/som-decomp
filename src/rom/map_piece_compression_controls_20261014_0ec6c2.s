.setcpu "65816"
.segment "CODE"
.org $C6C2
map_control_0ec6c2:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
