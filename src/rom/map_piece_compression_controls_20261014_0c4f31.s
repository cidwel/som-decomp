.setcpu "65816"
.segment "CODE"
.org $4F31
map_control_0c4f31:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
