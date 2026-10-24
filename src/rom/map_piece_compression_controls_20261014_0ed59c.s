.setcpu "65816"
.segment "CODE"
.org $D59C
map_control_0ed59c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
