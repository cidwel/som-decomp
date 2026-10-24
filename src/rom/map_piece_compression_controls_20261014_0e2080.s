.setcpu "65816"
.segment "CODE"
.org $2080
map_control_0e2080:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
