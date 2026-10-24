.setcpu "65816"
.segment "CODE"
.org $EBDC
map_control_0debdc:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
