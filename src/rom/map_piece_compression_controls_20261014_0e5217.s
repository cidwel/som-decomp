.setcpu "65816"
.segment "CODE"
.org $5217
map_control_0e5217:
    .byte $CA ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
