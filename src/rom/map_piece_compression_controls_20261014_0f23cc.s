.setcpu "65816"
.segment "CODE"
.org $23CC
map_control_0f23cc:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
