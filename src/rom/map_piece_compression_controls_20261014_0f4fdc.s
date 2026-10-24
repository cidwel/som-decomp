.setcpu "65816"
.segment "CODE"
.org $4FDC
map_control_0f4fdc:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
