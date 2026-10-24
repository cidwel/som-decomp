.setcpu "65816"
.segment "CODE"
.org $C6BE
map_control_0ec6be:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
