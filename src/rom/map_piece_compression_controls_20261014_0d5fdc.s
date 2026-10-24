.setcpu "65816"
.segment "CODE"
.org $5FDC
map_control_0d5fdc:
    .byte $E2 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
