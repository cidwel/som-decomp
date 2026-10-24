.setcpu "65816"
.segment "CODE"
.org $D4D7
map_control_0fd4d7:
    .byte $D2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
