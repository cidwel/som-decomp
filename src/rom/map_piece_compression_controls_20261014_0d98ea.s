.setcpu "65816"
.segment "CODE"
.org $98EA
map_control_0d98ea:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
