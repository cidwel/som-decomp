.setcpu "65816"
.segment "CODE"
.org $3C34
map_control_0f3c34:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
