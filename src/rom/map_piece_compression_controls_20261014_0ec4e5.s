.setcpu "65816"
.segment "CODE"
.org $C4E5
map_control_0ec4e5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
