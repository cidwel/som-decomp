.setcpu "65816"
.segment "CODE"
.org $65F0
map_control_0d65f0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
