.setcpu "65816"
.segment "CODE"
.org $8038
map_control_0d8038:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
