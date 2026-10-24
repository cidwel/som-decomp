.setcpu "65816"
.segment "CODE"
.org $5B0A
map_control_0f5b0a:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
