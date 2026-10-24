.setcpu "65816"
.segment "CODE"
.org $4BB4
map_control_0e4bb4:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
