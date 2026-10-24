.setcpu "65816"
.segment "CODE"
.org $E8DC
map_control_0fe8dc:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
