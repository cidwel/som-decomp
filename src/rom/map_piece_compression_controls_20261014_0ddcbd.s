.setcpu "65816"
.segment "CODE"
.org $DCBD
map_control_0ddcbd:
    .byte $E6 ; previous-row copy count
