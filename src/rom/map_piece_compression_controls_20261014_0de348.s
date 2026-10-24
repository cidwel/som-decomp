.setcpu "65816"
.segment "CODE"
.org $E348
map_control_0de348:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
