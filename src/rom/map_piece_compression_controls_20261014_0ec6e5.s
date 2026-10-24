.setcpu "65816"
.segment "CODE"
.org $C6E5
map_control_0ec6e5:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
