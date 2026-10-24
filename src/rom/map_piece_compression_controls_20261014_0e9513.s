.setcpu "65816"
.segment "CODE"
.org $9513
map_control_0e9513:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
