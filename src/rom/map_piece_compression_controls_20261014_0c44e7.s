.setcpu "65816"
.segment "CODE"
.org $44E7
map_control_0c44e7:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
