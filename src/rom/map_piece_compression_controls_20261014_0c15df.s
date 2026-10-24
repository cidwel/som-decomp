.setcpu "65816"
.segment "CODE"
.org $15DF
map_control_0c15df:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
