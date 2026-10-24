.setcpu "65816"
.segment "CODE"
.org $FA12
map_control_0ffa12:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
