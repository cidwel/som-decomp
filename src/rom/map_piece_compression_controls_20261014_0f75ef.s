.setcpu "65816"
.segment "CODE"
.org $75EF
map_control_0f75ef:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
