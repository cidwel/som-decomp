.setcpu "65816"
.segment "CODE"
.org $3109
map_control_0e3109:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
