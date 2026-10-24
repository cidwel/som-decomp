.setcpu "65816"
.segment "CODE"
.org $2126
map_control_0f2126:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
