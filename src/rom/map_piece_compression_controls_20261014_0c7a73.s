.setcpu "65816"
.segment "CODE"
.org $7A73
map_control_0c7a73:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
