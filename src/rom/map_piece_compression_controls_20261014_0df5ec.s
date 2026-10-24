.setcpu "65816"
.segment "CODE"
.org $F5EC
map_control_0df5ec:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
