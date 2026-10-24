.setcpu "65816"
.segment "CODE"
.org $1D1A
map_control_0f1d1a:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
