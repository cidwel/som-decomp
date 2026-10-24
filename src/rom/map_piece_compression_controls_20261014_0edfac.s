.setcpu "65816"
.segment "CODE"
.org $DFAC
map_control_0edfac:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
