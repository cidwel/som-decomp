.setcpu "65816"
.segment "CODE"
.org $38E1
map_control_0d38e1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
