.setcpu "65816"
.segment "CODE"
.org $2F76
map_control_0f2f76:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
