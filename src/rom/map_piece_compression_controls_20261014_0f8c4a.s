.setcpu "65816"
.segment "CODE"
.org $8C4A
map_control_0f8c4a:
    .byte $D2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
