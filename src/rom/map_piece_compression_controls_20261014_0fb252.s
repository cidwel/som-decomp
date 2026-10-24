.setcpu "65816"
.segment "CODE"
.org $B252
map_control_0fb252:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
