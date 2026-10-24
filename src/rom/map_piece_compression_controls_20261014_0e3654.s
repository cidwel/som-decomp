.setcpu "65816"
.segment "CODE"
.org $3654
map_control_0e3654:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
