.setcpu "65816"
.segment "CODE"
.org $4D53
map_control_0c4d53:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
