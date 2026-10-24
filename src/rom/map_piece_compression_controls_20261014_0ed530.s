.setcpu "65816"
.segment "CODE"
.org $D530
map_control_0ed530:
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
