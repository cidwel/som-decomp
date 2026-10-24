.setcpu "65816"
.segment "CODE"
.org $6E16
map_control_0f6e16:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
