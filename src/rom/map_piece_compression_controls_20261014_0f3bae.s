.setcpu "65816"
.segment "CODE"
.org $3BAE
map_control_0f3bae:
    .byte $D6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
