.setcpu "65816"
.segment "CODE"
.org $57E3
map_control_0f57e3:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
