.setcpu "65816"
.segment "CODE"
.org $925D
map_control_0f925d:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
