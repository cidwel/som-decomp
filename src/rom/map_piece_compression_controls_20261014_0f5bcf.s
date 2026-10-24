.setcpu "65816"
.segment "CODE"
.org $5BCF
map_control_0f5bcf:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
