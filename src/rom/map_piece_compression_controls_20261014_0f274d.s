.setcpu "65816"
.segment "CODE"
.org $274D
map_control_0f274d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
