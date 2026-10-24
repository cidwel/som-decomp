.setcpu "65816"
.segment "CODE"
.org $DAA6
map_control_0fdaa6:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
