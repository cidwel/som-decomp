.setcpu "65816"
.segment "CODE"
.org $2666
map_control_0f2666:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
