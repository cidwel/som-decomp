.setcpu "65816"
.segment "CODE"
.org $C6D6
map_control_0ec6d6:
    .byte $E8 ; backreference distance high bits
    .byte $9F ; distance low bit/count
