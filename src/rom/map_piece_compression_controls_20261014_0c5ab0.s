.setcpu "65816"
.segment "CODE"
.org $5AB0
map_control_0c5ab0:
    .byte $C3 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
