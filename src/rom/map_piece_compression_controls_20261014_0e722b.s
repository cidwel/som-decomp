.setcpu "65816"
.segment "CODE"
.org $722B
map_control_0e722b:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
