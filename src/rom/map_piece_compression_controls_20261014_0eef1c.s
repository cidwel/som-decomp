.setcpu "65816"
.segment "CODE"
.org $EF1C
map_control_0eef1c:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
