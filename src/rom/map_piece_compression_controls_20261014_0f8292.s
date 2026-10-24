.setcpu "65816"
.segment "CODE"
.org $8292
map_control_0f8292:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
