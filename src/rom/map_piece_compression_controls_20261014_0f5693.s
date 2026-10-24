.setcpu "65816"
.segment "CODE"
.org $5693
map_control_0f5693:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
