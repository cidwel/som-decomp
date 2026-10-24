.setcpu "65816"
.segment "CODE"
.org $DF0C
map_control_0ddf0c:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
