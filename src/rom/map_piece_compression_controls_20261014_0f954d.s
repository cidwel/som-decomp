.setcpu "65816"
.segment "CODE"
.org $954D
map_control_0f954d:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
