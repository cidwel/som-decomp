.setcpu "65816"
.segment "CODE"
.org $446B
map_control_0d446b:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
