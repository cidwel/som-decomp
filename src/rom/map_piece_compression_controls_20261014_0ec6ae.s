.setcpu "65816"
.segment "CODE"
.org $C6AE
map_control_0ec6ae:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
