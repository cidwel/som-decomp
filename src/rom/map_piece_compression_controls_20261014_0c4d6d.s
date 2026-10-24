.setcpu "65816"
.segment "CODE"
.org $4D6D
map_control_0c4d6d:
    .byte $ED ; backreference distance high bits
    .byte $9F ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
