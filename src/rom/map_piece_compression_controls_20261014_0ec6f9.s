.setcpu "65816"
.segment "CODE"
.org $C6F9
map_control_0ec6f9:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
