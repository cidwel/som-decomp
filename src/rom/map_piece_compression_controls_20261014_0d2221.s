.setcpu "65816"
.segment "CODE"
.org $2221
map_control_0d2221:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
