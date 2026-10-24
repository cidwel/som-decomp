.setcpu "65816"
.segment "CODE"
.org $8DEE
map_control_0f8dee:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
