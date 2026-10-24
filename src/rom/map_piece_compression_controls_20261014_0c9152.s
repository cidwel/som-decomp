.setcpu "65816"
.segment "CODE"
.org $9152
map_control_0c9152:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
