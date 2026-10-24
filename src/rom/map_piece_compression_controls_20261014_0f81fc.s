.setcpu "65816"
.segment "CODE"
.org $81FC
map_control_0f81fc:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
