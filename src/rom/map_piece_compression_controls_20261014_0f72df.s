.setcpu "65816"
.segment "CODE"
.org $72DF
map_control_0f72df:
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
