.setcpu "65816"
.segment "CODE"
.org $558F
map_control_0f558f:
    .byte $C9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
