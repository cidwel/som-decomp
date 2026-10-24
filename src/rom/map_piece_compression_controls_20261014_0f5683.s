.setcpu "65816"
.segment "CODE"
.org $5683
map_control_0f5683:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
