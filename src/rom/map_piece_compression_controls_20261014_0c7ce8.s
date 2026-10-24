.setcpu "65816"
.segment "CODE"
.org $7CE8
map_control_0c7ce8:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
