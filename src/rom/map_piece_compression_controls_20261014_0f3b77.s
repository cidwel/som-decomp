.setcpu "65816"
.segment "CODE"
.org $3B77
map_control_0f3b77:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
