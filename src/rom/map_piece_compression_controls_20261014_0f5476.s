.setcpu "65816"
.segment "CODE"
.org $5476
map_control_0f5476:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
