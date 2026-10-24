.setcpu "65816"
.segment "CODE"
.org $EBB3
map_control_0debb3:
    .byte $C3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
