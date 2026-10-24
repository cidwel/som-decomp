.setcpu "65816"
.segment "CODE"
.org $AB23
map_control_0dab23:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
