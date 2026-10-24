.setcpu "65816"
.segment "CODE"
.org $CD15
map_control_0fcd15:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
