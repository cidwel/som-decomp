.setcpu "65816"
.segment "CODE"
.org $EA90
map_control_0dea90:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
