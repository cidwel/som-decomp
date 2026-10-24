.setcpu "65816"
.segment "CODE"
.org $41F8
map_control_0f41f8:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
