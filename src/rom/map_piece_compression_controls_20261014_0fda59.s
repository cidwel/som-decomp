.setcpu "65816"
.segment "CODE"
.org $DA59
map_control_0fda59:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
