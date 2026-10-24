.setcpu "65816"
.segment "CODE"
.org $C536
map_control_0ec536:
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
