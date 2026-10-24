.setcpu "65816"
.segment "CODE"
.org $D4CB
map_control_0dd4cb:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
