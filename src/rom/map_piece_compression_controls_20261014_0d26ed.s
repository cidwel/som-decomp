.setcpu "65816"
.segment "CODE"
.org $26ED
map_control_0d26ed:
    .byte $D9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
