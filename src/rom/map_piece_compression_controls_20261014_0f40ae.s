.setcpu "65816"
.segment "CODE"
.org $40AE
map_control_0f40ae:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
