.setcpu "65816"
.segment "CODE"
.org $33F4
map_control_0e33f4:
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
