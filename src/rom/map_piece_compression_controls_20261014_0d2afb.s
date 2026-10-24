.setcpu "65816"
.segment "CODE"
.org $2AFB
map_control_0d2afb:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
