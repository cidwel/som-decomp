.setcpu "65816"
.segment "CODE"
.org $5B21
map_control_0f5b21:
    .byte $C6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
