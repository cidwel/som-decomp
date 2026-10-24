.setcpu "65816"
.segment "CODE"
.org $4738
map_control_0e4738:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
