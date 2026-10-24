.setcpu "65816"
.segment "CODE"
.org $ECC9
map_control_0decc9:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
