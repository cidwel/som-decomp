.setcpu "65816"
.segment "CODE"
.org $8379
map_control_0d8379:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
