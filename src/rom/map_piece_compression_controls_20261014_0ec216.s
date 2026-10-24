.setcpu "65816"
.segment "CODE"
.org $C216
map_control_0ec216:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
