.setcpu "65816"
.segment "CODE"
.org $7ADE
map_control_0c7ade:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
