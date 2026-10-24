.setcpu "65816"
.segment "CODE"
.org $7E90
map_control_0c7e90:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
