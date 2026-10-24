.setcpu "65816"
.segment "CODE"
.org $4AC9
map_control_0e4ac9:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
