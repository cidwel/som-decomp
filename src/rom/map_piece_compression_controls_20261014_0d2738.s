.setcpu "65816"
.segment "CODE"
.org $2738
map_control_0d2738:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
