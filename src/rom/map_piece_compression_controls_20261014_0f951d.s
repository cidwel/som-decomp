.setcpu "65816"
.segment "CODE"
.org $951D
map_control_0f951d:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
