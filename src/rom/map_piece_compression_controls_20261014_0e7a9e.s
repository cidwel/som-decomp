.setcpu "65816"
.segment "CODE"
.org $7A9E
map_control_0e7a9e:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
