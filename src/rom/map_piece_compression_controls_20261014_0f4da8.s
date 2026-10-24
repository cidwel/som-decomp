.setcpu "65816"
.segment "CODE"
.org $4DA8
map_control_0f4da8:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
