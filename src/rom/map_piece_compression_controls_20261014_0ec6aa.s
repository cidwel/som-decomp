.setcpu "65816"
.segment "CODE"
.org $C6AA
map_control_0ec6aa:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
