.setcpu "65816"
.segment "CODE"
.org $E4EF
map_control_0de4ef:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
