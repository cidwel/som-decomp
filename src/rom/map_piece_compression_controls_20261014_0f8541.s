.setcpu "65816"
.segment "CODE"
.org $8541
map_control_0f8541:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count
