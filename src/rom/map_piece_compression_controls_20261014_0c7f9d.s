.setcpu "65816"
.segment "CODE"
.org $7F9D
map_control_0c7f9d:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
