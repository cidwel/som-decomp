.setcpu "65816"
.segment "CODE"
.org $C6BA
map_control_0ec6ba:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
