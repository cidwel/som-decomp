.setcpu "65816"
.segment "CODE"
.org $9546
map_control_0d9546:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
