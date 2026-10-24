.setcpu "65816"
.segment "CODE"
.org $E55F
map_control_0fe55f:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
