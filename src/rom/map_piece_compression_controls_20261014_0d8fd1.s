.setcpu "65816"
.segment "CODE"
.org $8FD1
map_control_0d8fd1:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
