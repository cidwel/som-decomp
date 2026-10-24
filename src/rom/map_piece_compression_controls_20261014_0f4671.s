.setcpu "65816"
.segment "CODE"
.org $4671
map_control_0f4671:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
