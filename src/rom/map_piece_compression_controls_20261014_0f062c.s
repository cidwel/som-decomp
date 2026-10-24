.setcpu "65816"
.segment "CODE"
.org $062C
map_control_0f062c:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
