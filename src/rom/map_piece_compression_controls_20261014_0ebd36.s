.setcpu "65816"
.segment "CODE"
.org $BD36
map_control_0ebd36:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
