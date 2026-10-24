.setcpu "65816"
.segment "CODE"
.org $C01D
map_control_0ec01d:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
