.setcpu "65816"
.segment "CODE"
.org $2A2A
map_control_0e2a2a:
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
