.setcpu "65816"
.segment "CODE"
.org $9291
map_control_0e9291:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
