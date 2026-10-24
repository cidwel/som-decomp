.setcpu "65816"
.segment "CODE"
.org $5B33
map_control_0f5b33:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
