.setcpu "65816"
.segment "CODE"
.org $E37D
map_control_0de37d:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
