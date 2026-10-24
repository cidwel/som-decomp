.setcpu "65816"
.segment "CODE"
.org $C6CE
map_control_0ec6ce:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
