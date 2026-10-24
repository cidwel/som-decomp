.setcpu "65816"
.segment "CODE"
.org $F569
map_control_0cf569:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
