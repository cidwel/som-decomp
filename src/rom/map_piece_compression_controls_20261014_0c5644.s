.setcpu "65816"
.segment "CODE"
.org $5644
map_control_0c5644:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
