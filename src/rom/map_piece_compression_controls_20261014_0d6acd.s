.setcpu "65816"
.segment "CODE"
.org $6ACD
map_control_0d6acd:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
