.setcpu "65816"
.segment "CODE"
.org $75EB
map_control_0d75eb:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
