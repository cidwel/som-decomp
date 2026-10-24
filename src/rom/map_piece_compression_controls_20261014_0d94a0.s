.setcpu "65816"
.segment "CODE"
.org $94A0
map_control_0d94a0:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
