.setcpu "65816"
.segment "CODE"
.org $1332
map_control_0e1332:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
