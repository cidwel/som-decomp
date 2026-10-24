.setcpu "65816"
.segment "CODE"
.org $ED7C
map_control_0fed7c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
