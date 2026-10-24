.setcpu "65816"
.segment "CODE"
.org $75B5
map_control_0d75b5:
    .byte $CE ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
