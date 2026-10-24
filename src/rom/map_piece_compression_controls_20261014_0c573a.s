.setcpu "65816"
.segment "CODE"
.org $573A
map_control_0c573a:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
