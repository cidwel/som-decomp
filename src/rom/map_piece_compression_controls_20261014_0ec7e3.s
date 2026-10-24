.setcpu "65816"
.segment "CODE"
.org $C7E3
map_control_0ec7e3:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
