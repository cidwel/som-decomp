.setcpu "65816"
.segment "CODE"
.org $5F35
map_control_0e5f35:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
