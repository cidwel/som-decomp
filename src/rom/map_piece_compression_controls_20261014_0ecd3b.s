.setcpu "65816"
.segment "CODE"
.org $CD3B
map_control_0ecd3b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
