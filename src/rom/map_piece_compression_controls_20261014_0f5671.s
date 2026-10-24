.setcpu "65816"
.segment "CODE"
.org $5671
map_control_0f5671:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
