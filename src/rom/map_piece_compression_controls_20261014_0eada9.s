.setcpu "65816"
.segment "CODE"
.org $ADA9
map_control_0eada9:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
