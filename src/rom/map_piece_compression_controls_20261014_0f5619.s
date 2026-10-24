.setcpu "65816"
.segment "CODE"
.org $5619
map_control_0f5619:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
