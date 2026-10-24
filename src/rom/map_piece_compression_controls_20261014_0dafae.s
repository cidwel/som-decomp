.setcpu "65816"
.segment "CODE"
.org $AFAE
map_control_0dafae:
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
