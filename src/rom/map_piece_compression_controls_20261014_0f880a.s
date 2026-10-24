.setcpu "65816"
.segment "CODE"
.org $880A
map_control_0f880a:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
