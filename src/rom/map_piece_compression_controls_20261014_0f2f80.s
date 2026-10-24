.setcpu "65816"
.segment "CODE"
.org $2F80
map_control_0f2f80:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
