.setcpu "65816"
.segment "CODE"
.org $5BAB
map_control_0f5bab:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
