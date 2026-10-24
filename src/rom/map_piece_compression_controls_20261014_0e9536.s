.setcpu "65816"
.segment "CODE"
.org $9536
map_control_0e9536:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
