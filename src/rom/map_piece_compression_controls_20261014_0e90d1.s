.setcpu "65816"
.segment "CODE"
.org $90D1
map_control_0e90d1:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
