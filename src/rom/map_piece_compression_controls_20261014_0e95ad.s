.setcpu "65816"
.segment "CODE"
.org $95AD
map_control_0e95ad:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $D3 ; same-value copy count/distance
