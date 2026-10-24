.setcpu "65816"
.segment "CODE"
.org $D5DA
map_control_0fd5da:
    .byte $E2 ; previous-row copy count
    .byte $DE ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
