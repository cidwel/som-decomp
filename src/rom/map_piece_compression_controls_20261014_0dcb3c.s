.setcpu "65816"
.segment "CODE"
.org $CB3C
map_control_0dcb3c:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
