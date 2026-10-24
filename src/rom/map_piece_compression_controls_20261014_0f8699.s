.setcpu "65816"
.segment "CODE"
.org $8699
map_control_0f8699:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
