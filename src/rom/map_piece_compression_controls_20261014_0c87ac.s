.setcpu "65816"
.segment "CODE"
.org $87AC
map_control_0c87ac:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
