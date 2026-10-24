.setcpu "65816"
.segment "CODE"
.org $BA3C
map_control_0eba3c:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
