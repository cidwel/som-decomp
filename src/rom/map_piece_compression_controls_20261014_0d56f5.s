.setcpu "65816"
.segment "CODE"
.org $56F5
map_control_0d56f5:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
