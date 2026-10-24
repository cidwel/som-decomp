.setcpu "65816"
.segment "CODE"
.org $AE2A
map_control_0eae2a:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
