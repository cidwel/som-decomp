.setcpu "65816"
.segment "CODE"
.org $8C53
map_control_0e8c53:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
