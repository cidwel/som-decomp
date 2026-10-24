.setcpu "65816"
.segment "CODE"
.org $2060
map_control_0e2060:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
