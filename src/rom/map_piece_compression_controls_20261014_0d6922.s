.setcpu "65816"
.segment "CODE"
.org $6922
map_control_0d6922:
    .byte $C9 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
