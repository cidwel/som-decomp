.setcpu "65816"
.segment "CODE"
.org $98BD
map_control_0d98bd:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
