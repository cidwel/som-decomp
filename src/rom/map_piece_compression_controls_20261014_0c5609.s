.setcpu "65816"
.segment "CODE"
.org $5609
map_control_0c5609:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
