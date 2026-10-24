.setcpu "65816"
.segment "CODE"
.org $5A19
map_control_0c5a19:
    .byte $D2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
