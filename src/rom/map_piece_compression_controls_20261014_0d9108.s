.setcpu "65816"
.segment "CODE"
.org $9108
map_control_0d9108:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
