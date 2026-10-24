.setcpu "65816"
.segment "CODE"
.org $C8B9
map_control_0ec8b9:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
